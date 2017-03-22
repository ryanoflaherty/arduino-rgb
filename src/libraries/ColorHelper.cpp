#include "Rgb.h"
#include "ColorHelper.h"
#include <Arduino.h>

ColorHelper::ColorHelper(int minTempInK, int maxTempInK)
{
    randomSeed(analogRead(0));
    minK = minTempInK;
    maxK = maxTempInK;
}

Rgb ColorHelper::convertKToRgb(int colorTemp)
{
    float tmp;
    float tmpR;
    float tmpG;
    float tmpB;
    Rgb c;

    // Range check
    if (colorTemp < minK)
        colorTemp = minK;
    if (colorTemp > maxK)
        colorTemp = maxK;

    tmp = (float)(colorTemp / 100);

    // Red
    if (tmp <= 66)
    {
        c.red = 255;
    }
    else
    {
        tmpR = 329.698727446 * pow(tmp - 60, -0.1332047592);
        if (tmpR < 0)
            c.red = 0;
        else if (tmpR > 255)
            c.red = 255;
        else
            c.red = (int)tmpR;
    }

    // Green
    if (tmp <= 66)
    {
        tmpG = 99.4708025861 * log(tmp) - 161.1195681661;
        if (tmpG < 0)
            c.green = 0;
        else if (tmpG > 255)
            c.green = 255;
        else
            c.green = (int)tmpG;
    }
    else
    {
        tmpG = 288.1221695283 * pow(tmp - 60, -0.0755148492);
        if (tmpG < 0)
            c.green = 0;
        else if (tmpG > 255)
            c.green = 255;
        else
            c.green = (int)tmpG;
    }

    // Blue
    if (tmp >= 66)
    {
        c.blue = 255;
    }
    else if (tmp <= 19)
    {
        c.blue = 0;
    }
    else
    {
        tmpB = 138.5177312231 * log(tmp - 10) - 305.0447927307;
        if (tmpB < 0)
            c.blue = 0;
        else if (tmpB > 255)
            c.blue = 255;
        else
            c.blue = tmpB;
    }

    return c;
}

Rgb ColorHelper::getRandomColor()
{
    Rgb color;
    color.red = (int)random(256);
    color.green = (int)random(256);
    color.blue = (int)random(256);
    return color;
}