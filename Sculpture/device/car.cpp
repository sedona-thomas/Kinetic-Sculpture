#include "car.h"

/**
 * Car constructor makes a car object
 */
Car::Car()
{
  name = "car";
#if SEPARATE_WHEELS
  rightWheel = BrushMotor();
  leftWheel = BrushMotor();
#else
  wheels = BrushMotor();
#endif
  flower = StepMotor();
  
#if SEPARATE_LEAVES
  frontLeaves = ServoMotor();
  backLeaves = ServoMotor();
#else
  leaves = ServoMotor();
#endif
}

/**
 * Car constructor makes a car object
 * 
 * @param name_in the car name
 */
Car::Car(std::string _name)
{
  name = _name;
#if SEPARATE_WHEELS
  rightWheel = BrushMotor();
  leftWheel = BrushMotor();
#else
  wheels = BrushMotor();
#endif
  flower = StepMotor();
  frontLeaves = ServoMotor();
  backLeaves = ServoMotor();
}

/**
 * The run method runs the car
 */
void Car::run()
{
#if SEPARATE_WHEELS
  //
#else
  wheels.drive(2048);
#endif
  flower.moveAround(true, 1, 3);
#if SEPARATE_LEAVES
  //
#else
  leaves.moveTo(180);
  leaves.moveTo(0);
#endif
}