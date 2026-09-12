#include <Arduino.h>
#include <Keyboard.h>
#include <Mouse.h>


// ============================================================
// XIAO RP2040 PIN DEFINITIONS
// ============================================================

// ------------------------------------------------------------
// Joystick
// ------------------------------------------------------------
// XIAO A0 = D0 = GPIO26
// XIAO A1 = D1 = GPIO27

const int JOY_Y_PIN = A0;
const int JOY_X_PIN = A1;

// Joystick push button is intentionally NOT connected.
// Do not define/use a joystick button pin.


// ------------------------------------------------------------
// Keyboard buttons
// ------------------------------------------------------------
// XIAO D8 = GPIO2
// XIAO D9 = GPIO4
// XIAO D10 = GPIO3

const int F_PIN = D8;
const int C_PIN = D9;
const int E_PIN = D10;


// ------------------------------------------------------------
// Rotary encoder
// ------------------------------------------------------------
// XIAO D4 = GPIO6
// XIAO D5 = GPIO7
// XIAO D6 = GPIO0

const int ENCODER_A  = D4;
const int ENCODER_B  = D5;
const int ENCODER_SW = D6;


// ============================================================
// JOYSTICK SETTINGS
// ============================================================

// Arduino-Pico's default analogRead resolution is 10-bit.
// Therefore readings are normally 0-1023.
//
// We explicitly use 10-bit here so the values remain predictable.
const int ADC_MAX = 1023;


// Joystick center position.
// These are measured automatically during startup.
int joyXCenter = 512;
int joyYCenter = 512;


// Joystick deadzone.
// Increase this if the joystick moves when you aren't touching it.
const int JOY_DEADZONE = 70;


// Maximum joystick deflection after deadzone.
// Used to make the movement response smoother.
const int JOY_RANGE = 450;


// Maximum mouse movement per loop.
const int MAX_MOUSE_SPEED = 8;


// ============================================================
// NAVIGATION MODE
// ============================================================

enum NavigationMode {
  ORBIT_MODE,
  PAN_MODE
};

NavigationMode navigationMode = ORBIT_MODE;


// ============================================================
// STATE VARIABLES
// ============================================================

// Keyboard buttons
bool lastEState = HIGH;
bool lastCState = HIGH;
bool lastFState = HIGH;


// Encoder button
bool lastEncoderButtonState = HIGH;
unsigned long encoderButtonTime = 0;


// Encoder
int lastEncoderAState = HIGH;
unsigned long lastEncoderTime = 0;


// Joystick mouse state
bool navigationMouseHeld = false;


// ============================================================
// SETUP
// ============================================================

void setup() {

  // ----------------------------------------------------------
  // Keyboard buttons
  // ----------------------------------------------------------

  pinMode(E_PIN, INPUT_PULLUP);
  pinMode(C_PIN, INPUT_PULLUP);
  pinMode(F_PIN, INPUT_PULLUP);


  // ----------------------------------------------------------
  // Joystick
  // ----------------------------------------------------------

  pinMode(JOY_X_PIN, INPUT);
  pinMode(JOY_Y_PIN, INPUT);


  // ----------------------------------------------------------
  // Rotary encoder
  // ----------------------------------------------------------

  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  pinMode(ENCODER_SW, INPUT_PULLUP);


  // ----------------------------------------------------------
  // USB HID
  // ----------------------------------------------------------

  Keyboard.begin();
  Mouse.begin();


  // Give USB time to enumerate.
  delay(1500);


  // ----------------------------------------------------------
  // Configure ADC
  // ----------------------------------------------------------

  analogReadResolution(10);


  // ----------------------------------------------------------
  // Calibrate joystick center
  // ----------------------------------------------------------

  long xTotal = 0;
  long yTotal = 0;

  const int samples = 50;

  for (int i = 0; i < samples; i++) {

    xTotal += analogRead(JOY_X_PIN);
    yTotal += analogRead(JOY_Y_PIN);

    delay(5);
  }

  joyXCenter = xTotal / samples;
  joyYCenter = yTotal / samples;


  // ----------------------------------------------------------
  // Initialize encoder
  // ----------------------------------------------------------

  lastEncoderAState = digitalRead(ENCODER_A);
  lastEncoderButtonState = digitalRead(ENCODER_SW);
}


// ============================================================
// SEND A KEY
// ============================================================

void sendKey(char key) {

  Keyboard.press(key);

  delay(20);

  Keyboard.release(key);
}


// ============================================================
// HANDLE E / C / F BUTTONS
// ============================================================

void handleKeyboardButtons() {

  bool eState = digitalRead(E_PIN);
  bool cState = digitalRead(C_PIN);
  bool fState = digitalRead(F_PIN);


  // ----------------------------------------------------------
  // E
  // ----------------------------------------------------------

  if (lastEState == HIGH && eState == LOW) {
    sendKey('e');
  }


  // ----------------------------------------------------------
  // C
  // ----------------------------------------------------------

  if (lastCState == HIGH && cState == LOW) {
    sendKey('c');
  }


  // ----------------------------------------------------------
  // F
  // ----------------------------------------------------------

  if (lastFState == HIGH && fState == LOW) {
    sendKey('f');
  }


  lastEState = eState;
  lastCState = cState;
  lastFState = fState;
}


// ============================================================
// HANDLE ENCODER BUTTON
// ============================================================
//
// Encoder button toggles:
//
//     ORBIT ↔ PAN
//
// Joystick button is NOT used.
// ============================================================

void handleEncoderButton() {

  bool currentState = digitalRead(ENCODER_SW);

  unsigned long now = millis();


  // Detect button press
  if (lastEncoderButtonState == HIGH &&
      currentState == LOW) {

    // Simple debounce
    if (now - encoderButtonTime > 200) {

      encoderButtonTime = now;


      // ------------------------------------------------------
      // Stop any active navigation before changing mode
      // ------------------------------------------------------

      if (navigationMouseHeld) {

        Mouse.release(MOUSE_MIDDLE);

        if (navigationMode == ORBIT_MODE) {
          Keyboard.release(KEY_LEFT_SHIFT);
        }

        navigationMouseHeld = false;
      }


      // ------------------------------------------------------
      // Toggle mode
      // ------------------------------------------------------

      if (navigationMode == ORBIT_MODE) {
        navigationMode = PAN_MODE;
      }
      else {
        navigationMode = ORBIT_MODE;
      }
    }
  }

  lastEncoderButtonState = currentState;
}


// ============================================================
// JOYSTICK
// ============================================================

void handleJoystick() {

  int x = analogRead(JOY_X_PIN) - joyXCenter;
  int y = analogRead(JOY_Y_PIN) - joyYCenter;


  // ----------------------------------------------------------
  // Deadzone
  // ----------------------------------------------------------

  if (abs(x) < JOY_DEADZONE) {
    x = 0;
  }

  if (abs(y) < JOY_DEADZONE) {
    y = 0;
  }


  // ----------------------------------------------------------
  // If joystick is centered, stop navigation
  // ----------------------------------------------------------

  if (x == 0 && y == 0) {

    if (navigationMouseHeld) {

      Mouse.release(MOUSE_MIDDLE);

      if (navigationMode == ORBIT_MODE) {
        Keyboard.release(KEY_LEFT_SHIFT);
      }

      navigationMouseHeld = false;
    }

    return;
  }


  // ----------------------------------------------------------
  // Start navigation
  // ----------------------------------------------------------

  if (!navigationMouseHeld) {

    if (navigationMode == ORBIT_MODE) {

      // Fusion orbit:
      // Shift + middle mouse

      Keyboard.press(KEY_LEFT_SHIFT);
      Mouse.press(MOUSE_MIDDLE);
    }

    else {

      // Fusion pan:
      // middle mouse

      Mouse.press(MOUSE_MIDDLE);
    }

    navigationMouseHeld = true;
  }


  // ----------------------------------------------------------
  // Scale joystick movement
  // ----------------------------------------------------------

  int mouseX;
  int mouseY;


  // Remove deadzone from the usable range
  if (x > 0)
    x -= JOY_DEADZONE;
  else if (x < 0)
    x += JOY_DEADZONE;

  if (y > 0)
    y -= JOY_DEADZONE;
  else if (y < 0)
    y += JOY_DEADZONE;


  // Map joystick position to mouse speed
  mouseX = map(
    constrain(x, -JOY_RANGE, JOY_RANGE),
    -JOY_RANGE,
    JOY_RANGE,
    -MAX_MOUSE_SPEED,
    MAX_MOUSE_SPEED
  );

  mouseY = map(
    constrain(y, -JOY_RANGE, JOY_RANGE),
    -JOY_RANGE,
    JOY_RANGE,
    -MAX_MOUSE_SPEED,
    MAX_MOUSE_SPEED
  );


  // ----------------------------------------------------------
  // Invert Y
  // ----------------------------------------------------------
  //
  // Change this to:
  //
  // mouseY = -mouseY;
  //
  // if the joystick feels backwards.
  //

  mouseY = -mouseY;


  // ----------------------------------------------------------
  // Send mouse movement
  // ----------------------------------------------------------

  if (mouseX != 0 || mouseY != 0) {
    Mouse.move(mouseX, mouseY, 0);
  }
}


// ============================================================
// ROTARY ENCODER
// ============================================================
//
// Encoder rotation is sent as a mouse wheel movement.
//
// Fusion 360 interprets the wheel as zoom.
// ============================================================

void handleEncoder() {

  int currentA = digitalRead(ENCODER_A);

  unsigned long now = micros();


  // Detect rising edge on encoder A
  if (currentA != lastEncoderAState &&
      currentA == HIGH) {

    // Basic debounce
    if (now - lastEncoderTime > 1000) {

      lastEncoderTime = now;


      int direction;


      // Determine direction
      if (digitalRead(ENCODER_B) != currentA) {
        direction = 1;
      }
      else {
        direction = -1;
      }


      // Send wheel movement
      Mouse.move(0, 0, direction);
    }
  }


  lastEncoderAState = currentA;
}


// ============================================================
// MAIN LOOP
// ============================================================

void loop() {

  handleKeyboardButtons();

  handleEncoderButton();

  handleJoystick();

  handleEncoder();

  // Small delay prevents the loop from running unnecessarily fast.
  delay(2);
}
