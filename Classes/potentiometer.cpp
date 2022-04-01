#include "potentiometer.h"

/**
 * Potentiometer constructor makes a potentiometer object
 * 
 * @param name_in the potentiometer name
 * @param pin_in the pin that the potentiometer is connected to
 * @param json_in boolean for whether the serial data is sent in a JSON format
 */
Potentiometer::Potentiometer(std::string name_in, int pin_in, bool json_in) {
  name = name_in;
  pin = pin_in;
  value = 0;
  json = json_in;
}

/**
 * Potentiometer constructor makes a potentiometer object
 * 
 * @param pin_in the pin that the potentiometer is connected to
 * @param json_in boolean for whether the serial data is sent in a JSON format
 */
Potentiometer::Potentiometer(int pin_in, bool json_in) {
  name = "";
  pin = pin_in;
  value = 0;
  json = json_in;
}

/**
 * The read method reads potentiometer value
 */
void Potentiometer::read() {
  values.add(analogRead(pin));
  value = values.median();
#if DISPLAY_VALUES
  printSensorToScreen("potentiometer" + name, value);
#endif
};

/**
 * The send method sends data from the potentiometer over the serial connection
 */
void Potentiometer::send() {
  read();
  sendSerialObject("potentiometer", value);
};