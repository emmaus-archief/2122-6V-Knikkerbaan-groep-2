#include <Arduino_JSON.h>

KnikkerPoort poortBoven = KnikkerPoort();
WiFiCommunicator wifi = WiFiCommunicator(WIFI_NETWERK, WIFI_WACHTWOORD, SERVER_DOMEINNAAM);
Teller tellerA = Teller(TELLER_A_PIN);

radMotor servoRad = radMotor();
SensorPoort servoPoort = SensorPoort();

IRsensor poortDetector = IRsensor(7);
IRsensor LEDSensorL = IRsensor(8);
IRsensor LEDSensorR = IRsensor(6);
IRsensor SnelheidsSensor = IRsensor(5);

Led LEDRood = Led(9);
Led LEDGroen = Led(10);

unsigned long poortTime = 0;
unsigned long LedRoodTime = 0;
unsigned long LedGroenTime = 0;

int speedTrapDelay = 4000;
unsigned long speedBeginTime = 4000;
unsigned long speedEndTime = 0;
unsigned long deltaTime = 0;

int serverContactInterval = 15;                // 15 seconden
unsigned long tijdVoorContactMetServer = 0;

void setup() {
  Serial.begin(9600);

  poortBoven.begin(BOVEN_POORT_PIN, 0, 90);

  wifi.begin();

  wifi.stuurVerzoek("/api/set/nieuwerun", "");

  poortBoven.open();
///////////////
servoPoort.begin(2, 0, 90);
servoPoort.open();

servoRad.begin(3,80);
servoRad.open();
}


void loop() {

  // laat het servo van rad draaien
  servoRad.open();
  
  // laat de teller detecteren:
  tellerA.update();

//IR POORT//
  //laat IR sensor van poort detecteren en servo daarop reageren//
  poortDetector.update();

  if(poortDetector.isOnderbroken() && servoPoort.getOpen()){
    servoPoort.sluit();
  }

  if(millis() - poortTime > 3000) {
    poortTime = millis();
    servoPoort.open();
  }
//einde IR POORT//

//LEDS//
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

    if((millis() - speedBeginTime) > speedTrapDelay) {
      speedBeginTime = millis();
    }
  }

  else {
    LEDGroen.off();
  }
//einde LEDS//

//SnelheidsSensor
SnelheidsSensor.update();

  if(SnelheidsSensor.isOnderbroken()) {
    speedEndTime = millis();
  }

//delta tijd voor het berekenen van snelheid
deltaTime = speedEndtime - speedBeginTime;
  }
  
  // pauzeer de knikkerbaan als het tijd is voor contact met server
  if (millis() > tijdVoorContactMetServer && poortBoven.getOpen()) {
    poortBoven.sluit();
    servoRad.close();
  }

  // knikkerbaan is leeggelopen, er zijn geen sensors dit iets moeten meten
  // nu is het tijd om contact te leggen met de server:
  if (millis() > tijdVoorContactMetServer + LEEGLOOP_TIJD) {
    Serial.print("Er zijn nu zoveel knikkers geteld: ");
    Serial.println(tellerA.getAantal());

    String data = "knikkers=";
    data += tellerA.getAantal();

    wifi.stuurVerzoek("/api/set/sensordata", data.c_str());

    tijdVoorContactMetServer = millis() + (unsigned long)serverContactInterval * 1000;


    // en zet nu het poortje weer open:
    poortBoven.open();
    servoRad.open();
  }
}
