#include "car.h"

/**
 * Car constructor makes a car object
 */
Car::Car()
{
  name = "car";
#if SEPARATE_WHEELS
  // TODO: specify pins for separate wheeks
  rightWheel = BrushMotor();
  leftWheel = BrushMotor();
#else
  wheels = BrushMotor();
#endif
  flower = StepMotor();
#if SEPARATE_LEAVES
  // TODO: specify pins for separate leaves
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
  // TODO: write handler for separate wheels
#else
  wheels.drive(1000);
  delay(5 * SECOND);
#endif

  printToScreen("drove");

  flower.moveAround(true, 1, 3);

  printToScreen("moved flower");

#if SEPARATE_LEAVES
  // TODO: write handler for separate leaves
#else
  leaves.moveTo(180);

  printToScreen("one way");

  leaves.moveTo(0);

  printToScreen("other way\nmoved leaves");

#endif

  printToScreen("endRun");
}