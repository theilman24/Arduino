
#define fill 105 //the position in degrees to fill the hopper
#define empty 20 //the position in degrees to empty the hopper
#define potPin A0 //this is the pin (must be analog) that the middle of the potentiometer is connected to

#include <LiquidCrystal.h>
#include <Servo.h> //this is a library used to control a servo 

//variables
Servo mainServo; //declare the main servo
int trigger = 0; //this is used to switch between fill and empty
int potIn = 0; //this is the data read from pin A0 (the potPin)
int count = 1; //used as a time muliplier
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
int pirPin = 4;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;    // variable for reading the pin status
LiquidCrystal lcd(12,11,10,9,8,7);


//basic setup
void setup(){
  
mainServo.attach(3); //tell arduino which pin the servo is on (the white wire from the servo)

//set the pin modes
pinMode(4, OUTPUT); //used to output 5V or High to the potentiometer
pinMode(6, OUTPUT); //used for the led
pinMode(5, OUTPUT); //used for the led
pinMode(buttonPin, INPUT);
pinMode(pirPin, INPUT);  // declare sensor as input

digitalWrite(4, HIGH); //set pin 4 high
digitalWrite(10, LOW); //set pin 10 low
lcd.begin(16, 2);
lcd.clear();

Serial.begin(9600);
}


void loop(){
  
val = digitalRead(pirPin);  // read input value
if (val == HIGH) {
  if (pirState == LOW) {
    Serial.println("Motion detected!");
    lcd.print("Welcome to our   ");
    lcd.setCursor(0, 1);
    lcd.print("Cereal Machine      ");

potIn = analogRead(potPin); //read the position the potentiometer is at
buttonState = digitalRead(buttonPin);
//if the trigger value is 0 fill the hopper

if (buttonState == HIGH) {
 digitalWrite(6,HIGH);

if(!trigger){
  
//this is used to setup the delay
//the delay below is calculated using potin (which can be 0-1024) as delayinseconds ~= 0 - 64 seconds
count = 1;
trigger = 1; //change trigger to 1 to setup empty
digitalWrite(6,LOW); //set led off
}
else if(trigger){
  
mainServo.write(empty); //set the servo to empty position
delay(1000); //delay while servo sets position
trigger = 0; //change trigger to 0 to setup fill
}
}

mainServo.write(fill);//move servo to fill position
digitalWrite(6,LOW); //set led to off
}
}
}
//END OF CODE
