// Knikkerpoort is een klasse die de functionaliteit
// verzorgt van een servo die knikkers doorlaat / tegenhoudt

#include "Servo.h"


class KnikkerPoort {
  private:
    Servo poortServo;
    int pin;
    int gradenOpen;
    int gradenDicht;
    bool isOpen = false;

  public:
    KnikkerPoort(int _pin, int _gradenOpen, int _gradenDicht) {
      pin = _pin;
      pinMode(pin, OUTPUT);
      poortServo.attach(pin);
      gradenOpen = _gradenOpen;
      gradenDicht = _gradenDicht;
      sluit();
    }

    void sluit() {
      poortServo.write(gradenDicht);
      isOpen = false;
    }

    void open() {
      poortServo.write(gradenOpen);
      isOpen = true;
    }

    bool getOpen() {
      return isOpen;
    }
};
