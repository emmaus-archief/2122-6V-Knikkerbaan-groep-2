#include <Arduino_JSON.h>

radMotor servoRad = radMotor();
SensorPoort servoPoort = SensorPoort();

PoortIR poortDetector = PoortIR(7);
PoortIR LEDSensorL = PoortIR(8);
PoortIR LEDSensorR = PoortIR(6);

Led LEDRood = Led(9);
Led LEDGroen = Led(10);


unsigned long poortTime = 0;
unsigned long LedRoodTime = 0;

void setup() {
  Serial.begin(9600);

 servoPoort.begin(2, 0, 90);
 servoPoort.open();

 servoRad.begin(3,80);
 servoRad.open();
}


void loop() {


// servo van rad
servoRad.open();

//servo van Poort & IR sensor van poort
poortDetector.update();

  if(poortDetector.isOnderbroken() && servoPoort.getOpen()){
    servoPoort.sluit();
  }

  if(millis() - poortTime > 3000) {
    poortTime = millis();
    servoPoort.open();
    
  }

//LED linkerzijde baan & IR sensor van LED
LEDSensorL.update();

  if(LEDSensorL.isOnderbroken()) {
    LEDRood.on();
  }

  else {
    LEDRood.off();
  }

//LED rechterzijde baan & IR sensor van LED
LEDSensorR.update();

  if(LEDSensorR.isOnderbroken()) {
    LEDGroen.on();
  }

  else {
    LEDGroen.off();
  }


 // rodeLamp.on();

 // rodeLamp.off();

 // servoRad.close();
  


  
  // laat de teller detecteren:

  
  // pauzeer de knikkerbaan als het tijd is voor contact met server


  // knikkerbaan is leeggelopen, er zijn geen sensors dit iets moeten meten
  // nu is het tijd om contact te leggen met de server:


    // en zet nu het poortje weer open:

  }
;
