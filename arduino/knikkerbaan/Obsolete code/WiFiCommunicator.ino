#include <SPI.h>
#include <WiFiNINA.h>

// Class WiFiCommunicator verzorgt de communicatie via wifi

class WiFiCommunicator {

  private:
    char *ssid;
    char *password;
    char *host;

    int status = WL_IDLE_STATUS;

    WiFiSSLClient client;
    IngebouwdeRGBLED rgbLED;

  public:
    WiFiCommunicator(char *_ssid, char *_password, char *_host) {
      ssid = _ssid;
      password = _password;
      host = _host;


      rgbLED = IngebouwdeRGBLED();
      rgbLED.helderheid = 100;

    }

    void begin() {
      rgbLED.oranje();

      // check of de WiFi module het wel doet:
      if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        // don't continue
        rgbLED.rood();
        while (true);
      }

      String fv = WiFi.firmwareVersion();
      if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
        rgbLED.magenta();
        Serial.println("Please upgrade the firmware");
      }

      // proberr verbinding te maken met het WiFi-netwerk:
      while (status != WL_CONNECTED) {
        Serial.print("Probeert te verbinden met WiFi-netwerk: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, password);

        // wacht 4 seconden om verbinding te maken, anders opnieuw proberen:
        delay(4000);
      }
      rgbLED.groen();
      Serial.println("Verbonden met WiFi");
      printWiFiStatus();
    }

    String stuurVerzoek(char const *pad, char const *data) {
      Serial.print("doe verzoek op host:: ");
      Serial.print(host);
      Serial.print(", pad: ");
      Serial.print(pad);
      Serial.print(" en data: ");
      Serial.println(data);
      rgbLED.geel();

      String answer = "";

      String request = "GET ";
      request += pad;
      request += "?";
      request += data;
      request += " HTTP/1.1\nHost: ";
      request += host;
      request += "\nConnection: close\n";


      if (client.connect(host, 443)) {
        Serial.println("Verbonden met server");
        //Serial.println(request);
        client.println(request);

        while (client.connected()) {
          while (client.available()) {
            char c = client.read();
            answer.concat(c);
          }
        }
      }
      else {
        Serial.println("Kon geen verbinding maken met server");
      }

      // Serial.println(answer);

      rgbLED.groen();

      int blankLineIndex = answer.indexOf("\r\n\r\n");
      if (answer.length() > blankLineIndex + 4) {
        return answer.substring(blankLineIndex + 4);
      }

      return "";
    }



    void printWiFiStatus() {
      // print the SSID of the network you're attached to:
      Serial.print("SSID: ");
      Serial.println(WiFi.SSID());

      // print your board's IP address:
      IPAddress ip = WiFi.localIP();
      Serial.print("IP Address: ");
      Serial.println(ip);

      // print the received signal strength:
      long rssi = WiFi.RSSI();
      Serial.print("signal strength (RSSI):");
      Serial.print(rssi);
      Serial.println(" dBm");
    }
};
