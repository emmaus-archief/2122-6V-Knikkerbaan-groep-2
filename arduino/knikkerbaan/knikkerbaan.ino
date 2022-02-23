//declareer hier je globale constanten:

const int LEEGLOOP_TIJD = 5000;   // tijd die knikkers nodig hebben om na het
                                  // sluiten van de poort langs alle sensors te komen

char WIFI_NETWERK[] = "informatica-fast-wifi";
char WIFI_WACHTWOORD[] = "informatica-rocks!";
char SERVER_DOMEINNAAM[] = "3000-moccasin-cattle-lc2pi28a.ws-eu17.gitpod.io/";    // domeinnaam van gitpod-server, zoals 3000-lavendel-bla-bla.gitpod.io


const int BOVEN_POORT_PIN = 1;    // pin van servo die bovenste poort regelt
const int TELLER_A_PIN = 2;       // pin waarop IR-sensor voor Teller A(beginteller) is aangesloten


const int SERVORAD_PIN = 3;         // pin waarop de servo is aangesloten
const int SERVOPOORT_PIN = 4;       // pin waarop de sensorpoort is aangesloten
const int POORTDETECTOR_PIN = 5;        // pin waarop IR-sensor voor Sensor A(1e led sensor) is aangesloten
const int LEDSENSORL_PIN = 6;        // pin waarop IR-sensor voor Sensor B(2e led sensor) is aangesloten
const int LEDSENSORR_PIN = 7;        // pin waarop IR-sensor voor Sensor C(sensor voor poortje) is aangesloten
const int SNELHEIDSSENSOR_PIN = 8;        // pin waarop IR-sensor voor Sensor D(sensor voor snelheid) is aangesloten


const int LCD_PIN = 999;             // pin waarop het schermpje is aangsesloten
const int LEDROOD_PIN = 9;           // pin waarop LED is aangesloten
const int LEDGROEN_PIN = 10;           // pin waarop LED is aangesloten