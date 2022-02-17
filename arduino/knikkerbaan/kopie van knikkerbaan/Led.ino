class Led {
  private:
    int pin = 9;
    int ledStatus = LOW;
    bool isAan = false;
  
  public:
    Led(int _pin) {
      pin = _pin;
      pinMode(pin, OUTPUT);
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
