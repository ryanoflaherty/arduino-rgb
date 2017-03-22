/*
  RGB LED Project
  Ryan O'Flaherty
  3/1/17
*/

#include <Time.h>
#include <TimeAlarms.h>
#include <Rgb.h>
#include <Led.h>
#include <RgbDriver.h>
#include <ColorHelper.h>

#define REDPIN 9
#define GREENPIN 10
#define BLUEPIN 11

// TODO eventually have intensity
// Array of temperature values for each hour of the day
int timeToTemp[24] =
    {
        -1, -1, -1, -1, -1, -1, 2000, 3000, 4500, 6000, 7000, 7500,    // 0-11
        8000, 7500, 7000, 6250, 5000, 4000, 3000, 2000, -1, -1, -1, -1 // 12-23
};

// Init helpers
Rgb color;
ColorHelper cHelper(1000, 32000);
RgbDriver driver(REDPIN, BLUEPIN, GREENPIN);
const int secondsUntilRefresh = 60;

void setup()
{
  // TODO RAO user interface for this
  setTime(20, 30, 0, 3, 7, 2017);

  // Set up the alarm to trigger the lighting change function every 60 seconds
  Alarm.timerRepeat(secondsUntilRefresh, lightingChange);

  // call the lighting change function initially
  lightingChange();
}

void loop()
{
  // delay 500 seconds before checking for any alarms
  Alarm.delay(500);
}

void lightingChange()
{
  // get the current hour and minutes remaining in the hour
  int hr = hour();
  int min = minute() % secondsUntilRefresh;

  // determine the next hour
  int nexthr = hr < 23 ? hr + 1 : hr;

  // get the range of temperatures between the current and next hour
  int minTemp = timeToTemp[hr];
  int maxTemp = timeToTemp[nexthr];

  // determine what the adjusted temperature should be
  int temp = ((maxTemp - minTemp) * min) / secondsUntilRefresh + minTemp;

  // turn the light on based on the temp
  if (temp > 0)
  {
    color = cHelper.convertKToRgb(temp);
    driver.setColor(color);
  }
  else
  {
    driver.turnRgbOff();
  }
}