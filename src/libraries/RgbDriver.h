#ifndef RGBDRIVER_H
#define RGBDRIVER_H

class RgbDriver
{
protected:
  Led red;
  Led green;
  Led blue;
  bool ledOn;

public:
  RgbDriver(int redPin, int greenPin, int bluePin);
  void setColor(Rgb color);
  void turnRgbOff();
};

#endif