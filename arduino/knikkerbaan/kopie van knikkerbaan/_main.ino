#include <Arduino_JSON.h>

KnikkerPoort poortBoven = KnikkerPoort();
WiFiCommunicator wifi = WiFiCommunicator(WIFI_NETWERK, WIFI_WACHTWOORD, SERVER_DOMEINNAAM);
Teller tellerA = Teller(TELLER_A_PIN);

radMotor servoRad = radMotor();
SensorPoort servoPoort = SensorPoort();

IRsensor poortDetector = IRsensor(POORTDETECTOR_PIN);
IRsensor LEDSensorL = IRsensor(LEDSENSORL_PIN);
IRsensor LEDSensorR = IRsensor(LEDSENSORR_PIN);
IRsensor SnelheidsSensor = IRsensor(SNELHEIDSSENSOR_PIN);

Led LEDRood = Led(LEDROOD_PIN);
Led LEDGroen = Led(LEDGROEN_PIN);

unsigned long poortTime = 0;                  // zet delay voor de poort
unsigned long LedRoodTime = 0;                // zet delay voor leds
unsigned long LedGroenTime = 0;               // ^     ^       ^ 

int speedTrapDelay = 4000;                    // delay van 4 seconden om tijd van knikkers te kunnen opnemen
float distance = 0.40;                        // 4000, om delay voor eerste knikker te negeren
float lastSpeed = 0.00;                       // eindtijd voor de snelheidsberekening
unsigned long speedBeginTime = 4000;
unsigned long speedEndtime = 0;
float deltaTime = 0.000;

int serverContactInterval = 15;                // 15 seconden
unsigned long tijdVoorContactMetServer = 0;

void setup() {
  Serial.begin(9600);

  poortBoven.begin(BOVEN_POORT_PIN, 0, 90);

  wifi.begin();

  wifi.stuurVerzoek("/api/set/nieuwerun", "");

  poortBoven.open();
// --------------------------------
servoPoort.begin(SERVOPOORT_PIN, 0, 90);
servoPoort.open();

servoRad.begin(SERVORAD_PIN,80);
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

//LED rechterzijde baan & IR sensor van LED & eerste sensor voor het berekenen van de snelheid
  LEDSensorR.update();

  if(LEDSensorR.isOnderbroken()) {
    LEDGroen.on();

    if((millis() - speedBeginTime) > speedTrapDelay) {
      Serial.println(speedBeginTime);
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

    if((millis() - speedEndtime) > speedTrapDelay) {
      Serial.println(speedEndtime);
      speedEndtime = millis();
    }

    //delta tijd voor het berekenen van snelheid
    deltaTime = (speedEndtime - speedBeginTime);
    deltaTime = deltaTime / 1000;
  }
//einde SNELHEIDSSENSOR//

//berekening laatste snelheid
lastSpeed = distance / deltaTime;

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

    Serial.print("Dit was de laatst opgenomen snelheid in m/s: ");
    Serial.println(lastSpeed,2);

    Serial.print("De poort staat open: ");
    Serial.println(servoPoort.getOpen());

    Serial.print("De laatste snelheid van rad: ");
    Serial.println(servoRad.getSpeed());

    wifi.stuurVerzoek("/api/set/sensordata", data.c_str());

    tijdVoorContactMetServer = millis() + (unsigned long)serverContactInterval * 1000;


    // en zet nu het poortje weer open:
    poortBoven.open();
    servoRad.open();
  }
}
