#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "serial_communication.h"
#include "sensor.h"

/**
 * The Potentiometer class controls the necessary features of a potentiometer
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */
class Potentiometer : public Sensor, public SerialCommunication {
public:
  Potentiometer(){};
  Potentiometer(std::string, int, bool);
  Potentiometer(int, bool);
  void read();
  void send();
};

#endif
