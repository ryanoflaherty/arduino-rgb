#ifndef COLORHELPER_H
#define COLORHELPER_H

class ColorHelper
{
protected:
  int minK;
  int maxK;

public:
  ColorHelper(int minTempInK, int maxTempInK);
  Rgb convertKToRgb(int colorTemp);
  Rgb getRandomColor();
};

#endif