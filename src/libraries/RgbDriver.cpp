#include "Led.h"
#include "Rgb.h"
#include "RgbDriver.h"

RgbDriver::RgbDriver(int redPin, int greenPin, int bluePin)
    : red(redPin), green(greenPin), blue(bluePin)
{
    ledOn = false;
}
void RgbDriver::setColor(Rgb color)
{
    red.set(color.red);
    green.set(color.green);
    blue.set(color.blue);
    ledOn = true;
}

void RgbDriver::turnRgbOff()
{
    Rgb clr = {0, 0, 0};
    setColor(clr);
    ledOn = false;
}