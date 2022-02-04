#include <Servo.h>

Servo sensorServo;
    int pin = 4;
    int gradenOpen = 90;
    int gradenDicht = 0;
    unsigned long oldtime = 0;


void setup() {
  pinMode (pin, OUTPUT);
  sensorServo.attach(pin);
  Serial.begin(9600);

}

void loop() {

sensorServo.write(gradenDicht);
delay(5000);
sensorServo.write(gradenOpen);
delay(5000);



}