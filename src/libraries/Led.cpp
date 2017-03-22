#include "Led.h"

Led::Led(int ledPin)
{
    pin = ledPin;
    value = 255;
    pinMode(pin, OUTPUT);
}

void Led::write()
{
    analogWrite(pin, value);
}

void Led::set(int val)
{
    value = val;
    write();
}