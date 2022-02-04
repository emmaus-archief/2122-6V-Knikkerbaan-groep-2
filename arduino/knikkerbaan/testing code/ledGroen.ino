
//////////////////////////////////
// WORKING CODE //////////////////
//////////////////////////////////

class LedGroen {
  private:
    int pin = 9;
    int ledStatus = LOW;
    bool isAan = false;
  
  public:
    ledGroen() { }
      
    void init(int _pin, int _ledStatus) {
      pin = _pin;
      pinMode(pin, OUTPUT);
      ledStatus = _ledStatus;
      on();
      off();
    }
    void on() {
      digitalWrite(pin, HIGH);
    }
    void off() {
      digitalWrite(pin, LOW);
    }
};