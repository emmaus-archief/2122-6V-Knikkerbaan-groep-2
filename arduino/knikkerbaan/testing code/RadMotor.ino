
//////////////////////////////////
// WORKING CODE //////////////////
//////////////////////////////////

#include <Servo.h>

class radMotor {
    private:
    Servo radServo;
    int pin = 3; 
    int angle = 90;
    int oldtime = 0;
    int randomSpeed = 80;
    bool isOn = false;

    public:
      radMotor( int _pin, int _angle) {
        pin = _pin;
        pinMode(pin, OUTPUT);
        radServo.attach(pin);
        angle = _angle;
        oldtime = millis();
        sluit();
      }

    void sluit() {
      radServo.write(90);
      isOn = false;
    }

    void open() {
      if ( (millis()- oldtime) > 10000) {
        oldtime = millis();

        randomSpeed = random(0, 90);
      }
      
      radServo.write(randomSpeed);
      isOn = true;
    }

    bool getOn() {
      return isOn;
    }
};