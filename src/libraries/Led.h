#include <Arduino.h>

#ifndef LED_H
#define LED_H

class Led
{
protected:
  int pin;
  int value;
  void write();

public:
  Led(int ledPin);
  void set(int val);
};

#endif