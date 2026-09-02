<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/made0fjell0/CommieCAD">
    <img src="https://github.com/made0fjell0/CommieCAD/blob/main/images/logo.png?raw=true" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">CommieCAD</h3>

  <p align="center">
    A custom CAD controller (intended for Fusion360) make using <a href="https://hackpad.hackclub.com">Hackpad</a>!
    <br />
    <br />
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#How to">How to</a>
      <ul>
        <li><a href="#PCB">PCB</a></li>
        <li><a href="#Assembly">Assembly</a></li>
        <li><a href="#Code">Code</a></li>
      </ul>
    </li>
    <li><a href="#license">License</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<img src="https://github.com/made0fjell0/CommieCAD/blob/main/images/board.png?raw=true" width="300" height="200">
<img src="https://github.com/made0fjell0/CommieCAD/blob/main/images/back.png?raw=true" width="300" height="200">

I had a need for an assistant to help me with design work in Fusion360 because using a touchpad to clumsily navigate around my parts forever is not very nice. This controller will have the following functions: **Orbit/Pan with joystick, zoom with rotary encoder, F, E and C keys for easy hotkey access.**


<!-- GETTING STARTED -->
## How to

First, you will have to 3d print a two part <a href="https://github.com/made0fjell0/CommieCAD/tree/main/STLs">case</a>.

<img src="https://github.com/made0fjell0/CommieCAD/blob/main/images/sliced.png?raw=true">

You also need to print a simple <a href="https://github.com/made0fjell0/CommieCAD/blob/main/STLs/Joiner.stl">connective piece</a> between the encoder and joystick.

**IF YOU WANT TO** support me on printables, you can also find the STLs <a href="https://www.printables.com/model/1827930-commiecad">here</a>.

### PCB
**PCB-Less version coming SOON**
The gerbers are <a href="https://github.com/made0fjell0/CommieCAD/tree/main/gerbers">HERE.</a>
<br>
You can get the board cut from <a href="https://jlcpcb.com/pcb-fabrication/fr4-pcb">JLCPCB</a> probably for under 10 or 15$. Just sumbit the <a href="https://github.com/made0fjell0/CommieCAD/raw/refs/heads/main/gerbers/CommieCAD.zip?raw=true">zip file</a> and they will cut it.
<br><br>
**Schematic**
<img src="https://github.com/made0fjell0/CommieCAD/blob/main/images/schematic.png?raw=true">

### Assembly

First, you need to consult the <a href="https://github.com/made0fjell0/CommieCAD/blob/main/BOM.csv">BOM</a> (open it in excel) and get all the necesarry parts.
<br>
Let the assembly begin: <br>
1. Place your seeeduino xiao on its designated space on the PCB. Carefully use small amounts of solder to bind each pad to the pads on the board.

2. Flip the board upside down and put the joystick into its spot. Solder each of its pins to the golden pads on the circuit board.

3. Still upside down, put in you switches and also solder their pins in place.

4. Flip the PCB back. Use 5 slim wires and solder them in the 5 broken out pads on the board. Solder these to the pins on your encoder. (designations will be added later along with build photos)

5. Glue the joiner piece to the bottom of the encoder and attach it onto the rod of the joystick.

6. Grab your M3 screws and put the case on.

## Code

**PLEASE take the code part with a grain of salt as it is not finished and was mostly done by ChatGPT**
<br><br>
You will need the <a href="https://www.arduino.cc/en/software/">ArduinoIDE</a>.
<br>
Download <a href="https://github.com/made0fjell0/CommieCAD/blob/main/CommieCAD.ino?raw=true">CommieCAD.ino</a>, open up Arduino IDE, plug in your seeeduino board and flash the code onto it. That's it, nice and easy.

## End

You should now be sucessfully done with building your very own **CommieCAD**! Hopefully it serves you well and helps you with many projects just like it.

<!-- LICENSE -->
## License

Distributed under the MIT license. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>
