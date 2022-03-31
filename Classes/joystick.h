#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "serial_communication.h"
#include "button.h"
#include "potentiometer.h"

class Joystick : public SerialCommunication {
public:
  Joystick(){};
  Joystick(std::string, int, int, int, bool);
  void send();
  void sendSerialObject();

private:
  Potentiometer potentiometerX;
  Potentiometer potentiometerY;
  Button buttonSW;
};

#endif
