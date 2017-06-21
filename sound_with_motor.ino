int sensorValue ;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;
#include <Servo.h>
int potPin = 1;
int servoPin = 9;
Servo servo;

void setup() {
  servo.attach(servoPin);
  pinMode(ledPin, OUTPUT);
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if (sensorValue < sensorLow){
      sensorHigh = sensorValue; 
    }
    if (sensorValue > sensorLow){
      sensorLow = sensorValue;
    }
  }
  
  // put your setup code here, to run once:

}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 0, 400);
  tone(8,pitch,50);
  delay(10);

  int reading = analogRead(potPin);
  int angle = reading / 6;
  servo.write(angle);
  // put your main code here, to run repeatedly:

}
