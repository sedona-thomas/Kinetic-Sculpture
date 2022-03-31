#include "joystick.h"

Joystick::Joystick(std::string name_in, int pin_X, int pin_Y, int pin_SW,
                   bool json_in) {
  name = name_in;
  potentiometerX = Potentiometer("x", pin_X, json_in);
  potentiometerY = Potentiometer("y", pin_Y, json_in);
  buttonSW = Button("sw", pin_SW, json_in);
  json = json_in;
}

// send(): sends data from peripheral over the serial connection
void Joystick::send() {
#if DISPLAY_VALUES
  printToScreen("joystick");
#endif
  sendSerialObject();
};

// sendSerialObject(): sends all values that make up the joystick over the serial connection
void Joystick::sendSerialObject() {
  if (json) {
    if (name.length() > 0) {
      Serial.print("\"joystick_");
      Serial.print(name.c_str());
      Serial.print("\": ");
    } else {
      Serial.print("\"joystick\": ");
    }
    Serial.print("{");
    potentiometerX.send();
    Serial.print(",");
    potentiometerY.send();
    Serial.print(",");
    buttonSW.send();
    Serial.print("}");
  } else {
    Serial.print("<joystick_");
    Serial.print(name.c_str());
    Serial.print(">");
    potentiometerX.send();
    Serial.print(",");
    potentiometerY.send();
    Serial.print(",");
    buttonSW.send();
    Serial.print("</joystick_");
    Serial.print(name.c_str());
    Serial.print(">");
  }
}