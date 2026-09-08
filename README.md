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
**PCB-Less version coming SOON**<br>
The gerbers are <a href="https://github.com/made0fjell0/CommieCAD/tree/main/gerbers">HERE</a> and their compressed version <a href="https://github.com/made0fjell0/CommieCAD/tree/main/production/gerbers.zip">HERE.</a>
<br>
You can get the board cut from <a href="https://jlcpcb.com/pcb-fabrication/fr4-pcb">JLCPCB</a> probably for under 10 or 15$. Just sumbit the <a href="https://github.com/made0fjell0/CommieCAD/raw/refs/heads/main/production/gerbers.zip?raw=true">zip file</a> and they will cut it.
<br><br>
**Schematic**
<img src="https://github.com/made0fjell0/CommieCAD/blob/main/images/schematic.png?raw=true">

### Assembly

First, you need to consult the <a href="https://github.com/made0fjell0/CommieCAD/blob/main/BOM.csv">BOM</a> (open it in excel) and get all the necesarry parts.
<br>
| Item Name                           | Qty | Price (total) (EUR) | Item link                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
|-------------------------------------|-----|---------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 10-piece Cherry MX Brown switch kit | 1   | $4.58               | https://www.aliexpress.com/item/1005007891400560.html?spm=a2g0o.productlist.main.1.6632471082oz75&algo_pvid=cc87eb31-2a04-4b75-8094-35904d8a1e38&algo_exp_id=cc87eb31-2a04-4b75-8094-35904d8a1e38-0&pdp_ext_f=%7B"order"%3A"548"%2C"spu_best_type"%3A"price"%2C"eval"%3A"1"%2C"fromPage"%3A"search"%7D&pdp_npi=6%40dis%21EUR%214.58%214.58%21%21%2134.98%2134.98%21%4021613b2717880804173645049e10b2%2112000042740647794%21sea%21SK%216159834576%21X%211%210%21n_tag%3A-29919%3Bd%3A96cef531%3Bm03_new_user%3A-29895&curPageLogUid=I1Bh7Q49Hqvc&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007891400560%7C_p_origin_prod%3A                               |
| EC11 Rotary Encoder                 | 1   | $2.21               | https://www.aliexpress.com/item/1005006761212564.html?spm=a2g0o.productlist.main.50.29da2f4feu9XAI&algo_pvid=f01df35c-01d2-4d27-9c51-af2cd1076af7&algo_exp_id=f01df35c-01d2-4d27-9c51-af2cd1076af7-49&pdp_ext_f=%7B"order"%3A"107"%2C"eval"%3A"1"%2C"fromPage"%3A"search"%7D&pdp_npi=6%40dis%21EUR%211.67%211.67%21%21%2112.73%2112.72%21%402103962917880806218548881e10ef%2112000038303345963%21sea%21SK%216159834576%21X%211%210%21n_tag%3A-29919%3Bd%3A96cef531%3Bm03_new_user%3A-29895&curPageLogUid=YS14es0NDtm3&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006761212564%7C_p_origin_prod%3A                                                         |
| Joystick                            | 1   | $1.88               | https://www.aliexpress.com/item/1005008937490649.html?spm=a2g0o.productlist.main.21.3da072ecLABGBB&algo_pvid=135f1916-67c1-4bf8-8561-105024952dd0&algo_exp_id=135f1916-67c1-4bf8-8561-105024952dd0-20&pdp_ext_f=%7B"order"%3A"3448"%2C"spu_best_type"%3A"price"%2C"eval"%3A"1"%2C"fromPage"%3A"search"%7D&pdp_npi=6%40dis%21EUR%212.40%212.33%21%21%2118.36%2117.81%21%40210381f017880808031036287e0ea1%2112000047277002614%21sea%21SK%216159834576%21X%211%210%21n_tag%3A-29919%3Bd%3A96cef531%3Bm03_new_user%3A-29895%3BpisId%3A5000000215888387&curPageLogUid=N5SeqCFrkKCS&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008937490649%7C_p_origin_prod%3A |
| Keycaps                             | 3   | N/A                 | Find any set you like or get some spares from a keyboard.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| Seeedstudio XIAO RP2040             | 1   | $3.99               | https://www.seeedstudio.com/XIAO-RP2040-v1-0-p-5026.html                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| M3 Screws 25mm screws               | 4   | $5.25               |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| Total Price (EUR): 17.91€           |     |                     |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
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
Download <a href="https://github.com/made0fjell0/CommieCAD/blob/main/Firmware/CommieCAD.ino">CommieCAD.ino</a>, open up Arduino IDE, plug in your seeeduino board and flash the code onto it. That's it, nice and easy.

## End

You should now be sucessfully done with building your very own **CommieCAD**! Hopefully it serves you well and helps you with many projects just like it.

<!-- LICENSE -->
## License

Distributed under the MIT license. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>
