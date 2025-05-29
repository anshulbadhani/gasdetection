# Gas Leakage Detection
Made this project as a part of a 4 day workshop about microcontrollers, wireless commmunication and PCB fabrication. So, at the end of our workshop we were randomly paired with another team and we have to make an application of whatever has been taught to us. One team is supposed to make a transmitter and other side had to make something with reciver. We used Radio Communication to make our ESPs communincate between each other. Our team was the transmitter team and our part was to make a transmitter and design a PCB using proteus.

## Hardware Used
- ESP 8266 microcontroller
- MQ 5 Gas Sensor
- 5V Battery
- FS1000A Transmitter
- Resistors (220 ohms) (well not required but just to be on a safer side)
- Maybe some buzzer and leds stuff. Not necessary though (you may change the code if you want to exclude it)

## What are we doing?
Simple, we are checking for change in concentration of Hydrocarbons for LPG Leakages and then transmitting the message to the recieving end which is completely indepent team from us. Now, they may turn on ventilation or turn of the source (if possible).

Also the geber file is included, for those who don't know. One can use this gerber file to print out the pcb.
