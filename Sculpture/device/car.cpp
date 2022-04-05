#include "car.h"

/**
 * Car constructor makes a car object
 */
Car::Car()
{
  name = "car";
#if SEPARATE_WHEELS
  // To-Do: specify pins for separate wheeks
  rightWheel = BrushMotor();
  leftWheel = BrushMotor();
#else
  wheels = BrushMotor();
#endif
  flower = StepMotor();
#if SEPARATE_LEAVES
  // To-Do: specify pins for separate leaves
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
#if SEPARATE_LEAVES
  frontLeaves = ServoMotor();
  backLeaves = ServoMotor();
#else
  leaves = ServoMotor();
#endif
}

/**
 * The run method runs the car
 */
void Car::run()
{
  printToScreen("running");
#if SEPARATE_WHEELS
  // To-Do: write handler for separate wheels
#else
  wheels.drive(2048);
#endif

  printToScreen("drove");

  flower.moveAround(true, 1, 3);

  printToScreen("moved flower");

#if SEPARATE_LEAVES
  // To-Do: write handler for separate leaves
#else
  leaves.moveTo(180);
  leaves.moveTo(0);
#endif
  printToScreen("endRun");
}