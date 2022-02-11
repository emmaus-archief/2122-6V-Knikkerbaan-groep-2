
//////////////////////////////////
// WORK IN PROGRESS //////////////
//////////////////////////////////

#include <Arduino_JSON.h>

#include <Arduino_JSON.h>

radMotor servoRad = radMotor (3,90);
SensorPoort servoPoort = SensorPoort (3, 90, 0);
LedRood ledPinRood = LedRood ();
LedGroen ledPinGroen = LedGroen ();

void setup() {
  Serial.begin(9600);

  servoPoort.begin(4, 0, 90);
  servoPoort.open();

  servoRad.begin(13,80);
  
}


void loop() {

// laat het rad draaien
  servoRad.open();
  
// sluit en opent de poorten
  delay(3000);
  servoPoort.sluit();
  delay(3000);
  servoPoort.open();

//knippert de leds
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