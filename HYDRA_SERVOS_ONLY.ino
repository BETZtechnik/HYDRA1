
#include <Servo.h>

Servo myservo1;
Servo myservo2;

int leftposition;
int rightposition;
int lastleftposition;
int lastrightposition;
float leftright;
float foraft;
unsigned long lastmillis;
int incriment;
int buttondelay;
int leftservomicros;
int rightservomicros;

void setup(){

  myservo1.attach(3);
  myservo2.attach(10);
  leftposition = 45;  //set intial servo position to 45 degrees, neutral.
  rightposition = 45; //same for the right.
  lastmillis = millis();
  incriment = 5;
  buttondelay = 0;
  
}

void loop(){

  // FLIGHT CONTROLS:

  leftright = map(analogRead(A2), 0, 1023, 0.0, 5.0); // map to volts 0 - 5 (2.5 is neutral!)
  foraft = map(analogRead(A3), 0, 1023, 0.0, 5.0);  // same as above

  if((leftright < 2.0) && (millis() > lastmillis + (buttondelay))){
    leftposition -= (incriment);
    rightposition += (incriment);
    lastmillis = millis();
  }

  if((leftright > 2.9 ) && (millis() > lastmillis + (buttondelay))){
    leftposition += (incriment);
    rightposition -= (incriment);
    lastmillis = millis();
  }

  if((foraft < 2.0) && (millis() > lastmillis + (buttondelay))){
    leftposition -= (incriment);
    rightposition -= (incriment);
    lastmillis = millis();
  }

  if((foraft > 2.9 ) && (millis() > lastmillis + (buttondelay))){
    leftposition += (incriment);
    rightposition += (incriment);
    lastmillis = millis();
  }

  leftposition = constrain(leftposition, 0, 90);
  rightposition = constrain(rightposition, 0, 90);

  leftservomicros = map(leftposition, 0, 90, 1050, 1950); //limits for servo in microseconds
  rightservomicros = map(rightposition, 0, 90, 1950, 1050);// limits for servo


  myservo1.writeMicroseconds(leftservomicros);
  myservo2.writeMicroseconds(rightservomicros);


}




