#include <SPI.h>
#include <WiFiNINA.h>

class IngebouwdeRGBLED {
  private:
    int pasAanOpHelderheid(byte kleurWaarde) {
      return int ((float)kleurWaarde * (float)helderheid / 255.0);
    }

  public:
    byte helderheid = 255;
    IngebouwdeRGBLED() {}
    void toonRGB(byte rood, byte groen, byte blauw) {
      WiFiDrv::analogWrite(25, pasAanOpHelderheid(rood));
      WiFiDrv::analogWrite(26, pasAanOpHelderheid(groen));
      WiFiDrv::analogWrite(27, pasAanOpHelderheid(blauw));
    }

    void uit() {
      toonRGB(0, 0, 0);
    }

    void rood() {
      toonRGB(255, 0, 0);
    }

    void groen() {
      toonRGB(0, 255, 0);
    }

    void blauw() {
      toonRGB(0, 0, 255);
    }

    void geel() {
      toonRGB(255, 255, 0);
    }

    void cyaan() {
      toonRGB(0, 255, 255);
    }

    void magenta() {
      toonRGB(255, 0, 255);
    }

    void wit() {
      toonRGB(255, 255, 255);
    }

    void oranje() {
      toonRGB(255, 100, 0);
    }
};
