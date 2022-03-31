#include "potentiometer.h"

Potentiometer::Potentiometer(std::string name_in, int pin_in, bool json_in) {
  name = name_in;
  pin = pin_in;
  value = 0;
  json = json_in;
}

Potentiometer::Potentiometer(int pin_in, bool json_in) {
  name = "";
  pin = pin_in;
  value = 0;
  json = json_in;
}

// read(): reads potentiometer value
void Potentiometer::read() {
  values.add(analogRead(pin));
  value = values.median();
#if DISPLAY_VALUES
  printSensorToScreen("potentiometer" + name, value);
#endif
};

// send(): sends data from peripheral over the serial connection
void Potentiometer::send() {
  read();
  sendSerialObject("potentiometer", value);
};