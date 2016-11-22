/*
JoystickLCD by Dominion-Network
Outputs the direction of the thumb stick to the LCD Screen

This example code is in the public domain.
*/
//Include the LCD Library.
#include <LiquidCrystal.h>
//Declare the LCD object and define pins.


LiquidCrystal lcd(12,11,10,9,8,7);

void setup() {
//Start the LCD object.
lcd.begin(16, 2);
//Start with a clear LCD screen.
lcd.clear();
}

void loop() {
lcd.print("Welcome to our");
lcd.setCursor(0, 1);
lcd.print("Cereal Machine   ");
}

