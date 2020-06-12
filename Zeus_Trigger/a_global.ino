/*
 * Zeus Trigger Prototype and Testing
 * v0.1
 * Three button, Infrared LED, Light Dependent Diode,
 * OLED display, and Arduino Nano clone.
 * 
 * Libraries:
 * 
 * Adafruit SSD1306
 * Adafruit GFX
 */


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

//Debugging options and related variables
bool debug = true;
int prevMainMenuItem = 999;
//===================

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   64
#define LOGO_WIDTH    128

#define BUTTON_1      2      
#define BUTTON_2      3
#define BUTTON_3      4
#define GREEN_LED     5
#define RED_LED       7
#define IR_LED        6 // Must be a PWM 980Hz pin

long currentMillis;

bool button1Read;
bool button2Read;
bool button3Read;
bool button1State;
bool button2State;
bool button3State;
bool button1PrevState;
bool button2PrevState;
bool button3PrevState;
unsigned long button1Debounce = 0;
unsigned long button2Debounce = 0;
unsigned long button3Debounce = 0;
unsigned long menuChangeDelay = 250; // Prevents speeding through menus too quickly when holding buttons
unsigned long lastMenuChange = 0;
unsigned long debounceDelay = 50;

//Menu variables
int mainMenuItem = 1; // Current selected item in the menu
int highestMainMenuItem = 6; // The last item in the menu (so we can go back to 0 at next press)
int highestMenu1Item = 106; // The last item in the 1 submenu
int highestMenu2Item = 106; // The last item in the 2 submenu
int highestMenu3Item = 106; // The last item in the 3 submenu
int highestMenu4Item = 106; // The last item in the 4 submenu
int highestMenu5Item = 106; // The last item in the 5 submenu
int highestMenu6Item = 106; // The last item in the 6 submenu
int highestMenu7Item = 106; // The last item in the 7 submenu
