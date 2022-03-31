#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "serial_communication.h"
#include "sensor.h"

class Potentiometer : public Sensor, public SerialCommunication {
public:
  Potentiometer(){};
  Potentiometer(std::string, int, bool);
  Potentiometer(int, bool);
  void read();
  void send();
};

#endif
