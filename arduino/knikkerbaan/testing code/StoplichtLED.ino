
//////////////////////////////////
// OBSOLETE CODE NIET GEBRUIKEN //
//////////////////////////////////

class StoplichtLED {
  private:
    int pinRood = 5;
    int pinGroen = 6;
    int ledStatusRood = LOW;
    int ledStatusGroen = LOW;
    bool roodIsAan = false;
    bool groenIsAan = false;

  public:
    LedRood(int _pinRood, int _ledStatusRood){
      pinRood = _pinRood;
      pinMode(pinRood, OUTPUT);
      ledStatusRood = _ledStatusRood;
      roodAan();
      roodUit();
      }

      
    LedGroen(int _pinGroen, int _ledStatusGroen){
      pinGroen = _pinGroen;
      pinMode(pinGroen, OUTPUT);
      ledStatusGroen = _ledStatusGroen;
      groenAan();
      groenUit();
      }

    void roodAan() {
      digitalWrite(pinRood, HIGH);
      roodIsAan = true;
    }

    void roodUit() {
      digitalWrite(pinRood, LOW);
      roodIsAan = false;
    }

    void groenAan() {
      digitalWrite(pinGroen, HIGH);
      groenIsAan = true;
    }

    void groenUit() {
      digitalWrite(pinGroen, LOW);
      groenIsAan = false;
    }
};
