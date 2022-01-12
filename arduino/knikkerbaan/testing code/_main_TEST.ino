#include <Arduino_JSON.h>

#include <Arduino_JSON.h>

radMotor servoRad = radMotor (3,90);
SensorPoort servoPoort = SensorPoort (3, 90, 0);
LedRood ledPinRood = LedRood ();
LedGroen ledPinGroen = LedGroen ();

void setup() {
  Serial.begin(9600);

  servoRad.open();

  servoPoort.open();
}


void loop() {


  servoRad.sluit();
  
  servoPoort.sluit();

   ledPinRood.on();
   delay(3000);
   ledPinRood.off();
   delay(3000);

   ledPinGroen.on();
   delay(3000);
   ledPinGroen.off();
   delay(3000);
  
  // laat de teller detecteren:

  
  // pauzeer de knikkerbaan als het tijd is voor contact met server


  // knikkerbaan is leeggelopen, er zijn geen sensors dit iets moeten meten
  // nu is het tijd om contact te leggen met de server:


    // en zet nu het poortje weer open:

  }
;