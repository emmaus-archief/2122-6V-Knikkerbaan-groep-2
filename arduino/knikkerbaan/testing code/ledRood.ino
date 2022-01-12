class LedRood {
  private:
    int pin = 8;
    int ledStatus = LOW;
    bool isAan = false;
  
  public:
    ledRood() { }
      
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