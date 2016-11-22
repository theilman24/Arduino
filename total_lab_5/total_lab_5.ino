
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 10;        

//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;  

int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int servoPin = 9;
const int buttonPin = 7;
int buzzerPin = 5;


int i = 0;
int buttonState = 0; 



int pos = 180;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    Serial.begin(9600);
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);

  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  

}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (i != 1)
  {
        if(digitalRead(pirPin) == HIGH){            //detects person
            for (pos = 180; pos >= 0; pos -= 16.5) { // goes from 180 degrees to 0 degrees
                buttonState = digitalRead(buttonPin);
                if(buttonState == HIGH){
                    myservo.detach();
                    i = 1;
                    tone(5,400, 200);
                    delay(50);
                     tone(5,400, 200);
                   }
                myservo.write(pos);              // tell servo to go to position in variable 'pos'
                delay(1000);                       // waits 15ms for the servo to reach the position
                }
      
        }
  }
           i = 1;
          myservo.detach();
          tone(5,700, 10000);
         
}

