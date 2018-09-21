# e-Mark Wireless Multimeter

![GitHub](https://img.shields.io/badge/NTWoC-2018-blue.svg) ![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)

eMark Wireless multimeter is an open-source project, aimed towards building a cheap wireless multimeter device for hobbyists and enthusiasts. This project is a part of Next Tech's Winter of Code, and all the hardware designed will be openly accessible to the public in the form of schematics and gerber files.

## Technical Details
### Ideal Choice of Hardware
Choice of Hardware  - PIC16F18855-I/SS (8bit-Low Power PIC Microcontroller)  
Choice of Peripherals - HM-10 BLE, ESP8266-12E, INA219  
Choice of Communication Protocol - UART (Tx-Rx Comms.)  

### Extra features
Low Power consumption  
State Machine based command set  

## NTWoC Project Details

### Abstract

eMark Wireless Multimeter is a device which can measure voltage and current values, similar to a regular multimeter, but it is wireless. It is supposed to be cheap and accessible to all, and the voltage and current values, along with power and other values can be directly read/calculated by a handheld device (Mobile Phones/Tablet/Laptops). The heart of the system will be a microcontroller and the wireless connection can be created using bluetooth/wifi. This needs to be accurate, cheap and should have features which support its build costs and quality.

### Skill Requirements (You can apply if you have any one of the skills mentioned below)

1) Hardware Designer (To Work on electronic schematics using EagleCAD or KiCAD).  
2) Hardware Programmer (Will write code to control the hardware, preferably Embedded C).  
3) App Developer (Will create the Android/IOS/Windows/Hybrid Web App to create a User Interface for the Project).  

### Ideas that can be implemented

1) Use HC05/HC06/HC10 to interface the microcontroller with the handheld device.  
2) Choose Suitable hardware and design a clean schematic for the device.
3) Choose suitable component for Votage-Current Sensing and Interface with Microcontroller. Make design changes accordingly to the schematics.
4) Implement a state machine (with command sets) to control the device from handheld device.  
5) Document entire command sets/schematics and create an expanded documentation.   
6) Choose suitable hardware to implement wifi connection and create front-end to show values.  
7) Build Android/IOS/Web App to create a functional UI for the device.  

### New Ideas
New Ideas are always welcome. Talk to your mentor and convince him/her that this new idea/feature for this hardware is useful, easy to build and can be built in the time duration. 

## NTWoC Guidelines for this project

Anyone can choose to participate in NTWoC from SRM. It is free, it is open and everyone gets a fair chance.

1) No plaigarism. Try to work on your project without stealing credits or code.  
2) Fellow participants are not competitors. Work alongside them, and build a very good project.  
3) Try to finish the tasks at hand that are assigned to you or are self-assigned.

### Contributing to this Project
Read Contributing.md file in the repository to learn more about making pull requests, and contributing in general.

## Project Maintainers
The project is currently being maintained by :  
1) Projjal Gupta (paltrickontpb) - Next Tech Lab
