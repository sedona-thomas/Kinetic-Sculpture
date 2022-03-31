#ifndef __STEP_H__
#define __STEP_H__

#include <Arduino.h>
#include <cmath>

#define SECOND 1000  /**< miliseconds (1000 miliseconds : 1 second) */
#define STEP_DELAY 3 /**< miliseconds */

class StepMotor
{
public:
  StepMotor(std::string, int, int, int, int);
  StepMotor(std::string);
  StepMotor();
  void setup();
  void test();
  void moveSteps(bool, int, byte);
  void moveOneStep(bool);
  void moveAround(bool, int, byte);
  void moveAngle(bool, int, byte);

private:
  std::string name;
  int outPorts[4];
};

#endif