/**
 * The button class controls the necessary features of a button
 * 
 * @author Sedona Thomas
 */

#include "button.h"

/**
 * Button constructor makes a button object
 * 
 * @param name_in the button name
 * @param pin_in the pin that the button is connected to
 * @param json_in boolean for whether the serial data is sent in a JSON format
 */
Button::Button(std::string name_in, int pin_in, bool json_in) {
  name = name_in;
  pin = pin_in;
  value = 0;
#ifdef BUTTON_DELAY
  values = ValueQueue(BUTTON_DELAY);
#endif
  json = json_in;
}

/**
 * Button constructor makes a button object
 * 
 * @param pin_in the pin that the button is connected to
 * @param json_in boolean for whether the serial data is sent in a JSON format
 */
Button::Button(int pin_in, bool json_in) {
  name = "";
  pin = pin_in;
  value = 0;
#ifdef BUTTON_DELAY
  values = ValueQueue(BUTTON_DELAY);
#endif
  json = json_in;
}

/**
 * The read method reads the button value
 */
void Button::read() {
  pinMode(pin, INPUT_PULLUP);
  values.add(digitalRead(pin));
  value = values.contains(1) ? 1 : 0;
#if DISPLAY_VALUES
  printSensorToScreen("button", value);
#endif
}

/**
 *  The send method sends data from the button over the serial connection
 */
void Button::send() {
  read();
  sendSerialObject("button", value);
}