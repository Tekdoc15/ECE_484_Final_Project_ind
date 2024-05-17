The section of our pinball project that I was responsible for was the build/assembly of our playfield, power systems to ensure everything would have enough power to operate, and the scoreboard. In this repositiory I will be covering the scoreboard system.

I decided to reach out to AlfaZeta based in Poland as I had seen flip dot displays before and found via a google search that they made 7 segment displays. They were kind enough to provide a 10 digit display at discount for this project.

The 7 segment flipdot display uses electromagnetic relays to flip segments of the display from white to black or vis versa. To do this, it needs a 24 volt DC power source.

The control system of the display is mounted on the back side of it along with the power connection. It utilizes the RS-485/TIA-285/EIA-485 serial protocol in order to receive data that it needs to display.

The way the data is formatted is as follows:

* A start sequence digit is sent first in our case here it is 0xFE
* A digit given the address of the display is given, the address I set was 0x00 however you have 6 bits to use to set an address if you wanted to connect many of them on the same bus
* 10 digits are then sent, one for each of the 10 digits that are a part of the display.
* Finally to close out the sequence and let the controller know that it needs to listen for the next start sequence command we send 0x8F.

These sequences must be sent over the RS-485 protocol and if you try to send them from the regular serial lines of an Arduino you will not get any information displaying on your system.

To do this a UART to RS-485 module was used to convert the serial signal from the Arduino to something that the controller could utilize.

A twisted pair of wires is then connected from the data lines on the controller to the RS-485 conversion module and when we send the sequence outlines above the display will start to update with information that we want to see.

![IMG_0989](https://github.com/Tekdoc15/ECE_484_Final_Project_ind/assets/11917221/b7f741a0-7545-4384-a4d4-f380ace3718b)
![IMG_1001](https://github.com/Tekdoc15/ECE_484_Final_Project_ind/assets/11917221/dc135d71-c6df-4d14-96c0-b4c2101f2ce3)

I am not entirely sure why the top portion of the 6th digit has stopped always functioning, but I belive it may be related to me accidentally dropping the system this morning as I was loading everything for transport to campus.
