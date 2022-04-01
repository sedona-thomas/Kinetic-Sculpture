#ifndef __SERIAL_COMMUNICATION_H__
#define __SERIAL_COMMUNICATION_H__

#include <Arduino.h>
#include <stdint.h>
#include <string>

#define JSON true /**< sends JSON data over serial connection not tagged */

/**
 * The SerialCommunication class defines the necessary features to send data across a serial connection
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */
class SerialCommunication {
protected:
  std::string name;
  bool json;
  void send(){};
  void sendSerialObject(std::string, uint8_t);
};

#endif
