#include <Arduino_JSON.h>

KnikkerPoort poortBoven = KnikkerPoort (BOVEN_POORT_PIN, 0, 90);
WiFiCommunicator wifi = WiFiCommunicator(WIFI_NETWERK, WIFI_WACHTWOORD, SERVER_DOMEINNAAM);
Teller tellerA = Teller(TELLER_A_PIN);

int serverContactInterval = 15;                // 15 seconden
unsigned long tijdVoorContactMetServer = 0;

void setup() {
  Serial.begin(9600);

  wifi.begin();

  wifi.stuurVerzoek("/api/set/nieuwerun", "");

  poortBoven.open();
}


void loop() {
  // laat de teller detecteren:
  tellerA.update();

  
  // pauzeer de knikkerbaan als het tijd is voor contact met server
  if (millis() > tijdVoorContactMetServer && poortBoven.getOpen()) {
    poortBoven.sluit();
  }

  // knikkerbaan is leeggelopen, er zijn geen sensors dit iets moeten meten
  // nu is het tijd om contact te leggen met de server:
  if (millis() > tijdVoorContactMetServer + LEEGLOOP_TIJD) {
    Serial.print("Er zijn nu zoveel knikkers geteld: ");
    Serial.println(tellerA.getAantal())


    // en zet nu het poortje weer open:
    poortBoven.open();
  }
}
