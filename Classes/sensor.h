#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <Arduino.h>
#include <stdint.h>
#include "ValueQueue.h"

#define DISPLAY_VALUES true /**< true: sensors; false: rainbow background */

class Sensor {
protected:
  uint8_t pin;
  uint8_t value;
  ValueQueue values;
  virtual void read() { value = analogRead(pin); };
};

#endif
