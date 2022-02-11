
//////////////////////////////////
// WORKING CODE //////////////////
//////////////////////////////////

#include <Servo.h>

class radMotor {
    private:
    Servo radServo;
    int pin = 13;
    int angle = 80;
    unsigned long oldtime = 0;
    int randomSpeed = 80;
    bool isOn = false;

    public:
    radMotor(){}

      void begin( int _pin, int _angle) {
        pin = _pin;
        pinMode(pin, OUTPUT);
        radServo.attach(pin);
        angle = _angle;
        oldtime = millis();

      }

    void close() {
      radServo.write(90);
      isOn = false;
    }

    void open() {
      if ( ( millis() - oldtime) > 5000) {
        oldtime = millis();

        randomSpeed = random(0, 50);
      }
      
      radServo.write(randomSpeed);
      isOn = true;
    }

    bool getOn() {
      return isOn;
    }
};