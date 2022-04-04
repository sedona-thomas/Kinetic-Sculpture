#include "car.h"

/**
 * Car constructor makes a car object
 */
Car::Car()
{
  name = "car";
  wheels = BrushMotor();
  flower = StepMotor();
  frontLeaves = ServoMotor();
  backLeaves = ServoMotor();
}

/**
 * Car constructor makes a car object
 * 
 * @param name_in the car name
 */
Car::Car(std::string _name)
{
  name = _name;
  rightWheel = BrushMotor();
  leftWheel = BrushMotor();
  flower = StepMotor();
  frontLeaves = ServoMotor();
  backLeaves = ServoMotor();
}

/**
 * The setup method sets up the car
 */
void Car::setup()
{
  
}

/**
 * The run method runs the car
 */
void Car::run()
{
  
}
