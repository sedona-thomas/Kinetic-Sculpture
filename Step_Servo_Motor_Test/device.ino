/*
 * device.ino: reads values from an Esp32 and sends them as serial data
 */

#define BAUDRATE 115200     // baudrate for serial communications
#define DISPLAY_VALUES true // true: sensors; false: rainbow background
#define JSON true           // sends JSON data over serial connection not tagged
#define BUTTON_DELAY 50     // delays button if defined

#include "ValueQueue.h"
#include "esp32_screen.h"
#include "motors.h"
#include <SPI.h>
#include <TFT_eSPI.h>
#include <list>
#include <stdint.h>
#include <string>

class StepMotor {
public:
  StepMotor(std::string, int, int, int, int);
  StepMotor(std::string);
  void setup();
  void run();
  void moveSteps(bool, int, byte);
  void moveOneStep(bool);
  void moveAround(bool, int, byte);
  void moveAngle(bool, int, byte);

private:
  std::string name;
  int outPorts[];
}

class ServoMotor {
public:
  ServoMotor(std::string, int);
  ServoMotor(std::string);
  void setup();
  void run();

private:
  std::string name;
  int port;
}
