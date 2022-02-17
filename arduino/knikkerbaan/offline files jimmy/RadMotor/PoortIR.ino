class PoortIR {
  private:
  int pin;
  bool wasOnderbroken;
  unsigned long laatstOnderbroken = 0;
  const int DEBOUNCE_TIME = 10;

  bool wordtOnderbroken() {
      return (wasOnderbroken == false && isOnderbroken() == true);
    }

    public:
    PoortIR(int _pin) {
      pinMode(_pin, INPUT_PULLUP);
      pin = _pin;
      wasOnderbroken = false;
    }

      bool isOnderbroken() {
      return !digitalRead(pin);
    }

    void update() {
      Serial.println(digitalRead(pin));
      wasOnderbroken = isOnderbroken();
    }

    


  
};
