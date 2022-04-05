#ifndef __STEP_H__
#define __STEP_H__

#include <Arduino.h>
#include <cmath>
#include <string>
#include <stdint.h>

#define SECOND 1000  /**< miliseconds (1000 miliseconds : 1 second) */
#define STEP_DELAY 3 /**< miliseconds */

/**
 * The StepMotor class controls the necessary features of a step motor
 *
 * @author Sedona Thomas
 * @version 1.0.0
 */
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
  int outPorts[4]; /**< Ports use GPOI pins {33, 25, 26, 27} by default */
};

#endif