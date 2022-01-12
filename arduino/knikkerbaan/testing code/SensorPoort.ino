#include <Servo.h>

class SensorPoort {
   private:
    Servo sensorServo;
    int pin = 4;
    int gradenOpen = 90;
    int gradenDicht = 0;
    int oldtime = 0;
    bool isOpen = false;

    public:
      SensorPoort( int _pin, int _gradenOpen, int _gradenDicht) {
        pin = _pin;
        pinMode(pin, OUTPUT);
        sensorServo.attach(pin);
        gradenOpen = _gradenOpen;
        gradenDicht = _gradenDicht;
        sluit();
      }

    void sluit() {
      sensorServo.write(gradenDicht);
      isOpen = false;
    }

    void open() {
      sensorServo.write(gradenOpen);
      isOpen = true;
    }

    bool getOpen() {
      return isOpen;
    }
};