#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "serial_communication.h"
#include "sensor.h"

#define BUTTON_DELAY 50 /**< delays button if defined */

class Button : public Sensor, public SerialCommunication {
public:
  Button(){};
  Button(std::string, int, bool);
  Button(int, bool);
  void read();
  void send();
};

#endif
