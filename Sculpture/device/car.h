#ifndef __CAR_H__
#define __CAR_H__

#include <Arduino.h>
#include <cmath>

#define SECOND 1000    /**< miliseconds (1000 miliseconds : 1 second) */

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
  BrushMotor rightWheel;
  BrushMotor leftWheel;
  StepMotor flower;
  ServoMotor frontLeaves;
  ServoMotor backLeaves;
};

#endif