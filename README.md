# Zeus-Trigger
Arduino powered camera trigger

# Introduction
Hi and thank you for being here.

This project has been dreamed up by myself, David Bristoll (Pringleman83), and my friend, Abhiram Vijayakumar (Abhiram223344). We're both spare time tinkerers, hackers (of the hardware variety) and hobby photographers.

The aim is to create a battery powered device that can be connected to a DSLR camera and various sensors. The device will use those sensors, and / or timing, to trigger the camera to take a shot. We've taken a lot of inspiration from the excellent open source project;  photoduino (found here: https://kalanda.github.io/photoduino/documentation/hardware/photoduino-shield-3-0/).

While reinventing the wheel might not be the most logical way forward, we both feel we can learn a lot by starting from scratch and may even be able to create some original features too. If our end product looks anywhere near as polished as Kalanda's, we'll both be very happy!

My relevant background is more on the code side of things (although I still have a lot to learn). Abhiram's background is more on the engineering side. I'm currently completing the MITx Introduction to Computer Science course online and this will be my final project for that course.

The basic idea is that I'll be working very much on the code side of things and Abhiram will be working more on the hardware side. However, we both have some experience in each other's relevant specaility and so there'll definitely be some cross over.

# Planned features

* Arduino Nano based design on custom PCB
* Small OLED display
* Timer feature for time lapse photography
* Light sensor for specialist photography such as lightening or laser triggered photography
* Infra Red LED for wireless communication with popular DSLR cameras
* Camera port for wired connection to popular cameras
* Three buttons for simple navigation, selection and adjustment of options
* Settings stored on internal eeprom

# Do next

* Agree possible final designs
* List required components
* Build some proof of concept designs to:
  * Produce a usable menu system testing the three buttons and oled display
  * Add the IR LED and code that so that it works with a camera
  
# Current hardware and software

Hardware configuration is as follows:

Arduino Nano clone based

Arduino pin		Configuration		Connection 1			Connection 2			Connection 3

D2				INPUT_PULLUP		BUTTON_1				GND
D3				INPUT_PULLUP		BUTTON_2				GND
D4				INPUT_PULLUP		BUTTON_3				GND
D5				OUTPUT				220 Ohm resistor		Red LED					GND
D6				OUTPUT				220 Ohm resistor		Green LED				GND
D7				OUTPUT				220 Ohm resistor		IR LED					GND

A4									OLED SDA
A5									OLED SCL
5V									OLED VCC
GND									OLED GND				GND

Software

BUTTON_1 = Left
BUTTON_2 = Middle
BUTTON_3 = Right

The current code shows the Zeus Trigger logo and flashes it a few times.
There's then a seven item menu that can be navigated using the left and right buttons.
The centre button lights up the selected item momentarily.

The buttons also illuminate the following LEDs for testing purposes:
BUTTON_1 = green LED
BUTTON_2 = IR LED
BUTTON_3 = red LEDs

The code includes debounce for each button and scroll speed control for the menu.
The speed control prevents speeding through the menu too quickly when a button is held for too long.

![Current prototype front] (https://github.com/Pringleman83/Zeus-Trigger/Zeus_Trigger_Proto1_front.jpg)

![Current prototype back] (https://github.com/Pringleman83/Zeus-Trigger/Zeus_Trigger_Proto1_back.jpg)


# Contributing

If you'd like to contribute to this project please let us know what areas you may be able to help in.

We're currently looking for:

* somebody who may be able to design an enclosure for the completed project

# Thank you

Thank you for visiting and reading this. Please check back for updates soon!

