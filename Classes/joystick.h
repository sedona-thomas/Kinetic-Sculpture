#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "serial_communication.h"
#include "button.h"
#include "potentiometer.h"

/**
 * The Joystick class controls the necessary features of a joystick
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */
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
