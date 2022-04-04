#ifndef __CAR_H__
#define __CAR_H__

#include <Arduino.h>
#include <cmath>
#include <string>
#include <stdint.h>
#include "servo.h"
#include "step.h"
#include "brush.h"

#define SECOND 1000    /**< miliseconds (1000 miliseconds : 1 second) */
#define SEPARATE_WHEELS false /**< whether wheels are controlled individually */

/**
 * The Car class controls the car and flower
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */
class Car
{
public:
  Car();
  Car(std::string);
  void setup();
  void run();

private:
  std::string name;
#if SEPARATE_WHEELS
  BrushMotor rightWheel;
  BrushMotor leftWheel;
#else
  BrushMotor wheels;
#endif
  StepMotor flower;
  ServoMotor frontLeaves;
  ServoMotor backLeaves;
};

#endif