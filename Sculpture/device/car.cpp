#include "car.h"

/**
 * Car constructor makes a car object
 */
Car::Car()
{
  name = "car";
#if SEPARATE_WHEELS
  // TODO: specify pins for separate wheeks
  rightWheel = BrushMotor("right wheel", 12, 15, 13);
  leftWheel = BrushMotor("left wheel", 12, 15, 13);
#else
  wheels = BrushMotor("wheels", 12, 15, 13);
#endif
  flower = StepMotor("flower", 33, 25, 26, 27);
#if SEPARATE_LEAVES
  // TODO: specify pins for separate leaves
  frontLeaves = ServoMotor("front leaves", 1);
  backLeaves = ServoMotor("back leaves", 2);
#else
  leaves = ServoMotor("leaves", 2);
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
  // TODO: specify pins for separate wheeks
  rightWheel = BrushMotor();
  leftWheel = BrushMotor();
#else
  wheels = BrushMotor("flower", 33, 25, 26, 27);
#endif
  flower = StepMotor();
#if SEPARATE_LEAVES
  // TODO: specify pins for separate leaves
  frontLeaves = ServoMotor("front leaves", 1);
  backLeaves = ServoMotor("back leaves", 2);
#else
  leaves = ServoMotor("leaves", 2);
#endif
}

/**
 * The setup method sets up the car
 */
void Car::setup()
{
#if SEPARATE_WHEELS
  // TODO: specify pins for separate wheeks
  rightWheel.setup();
  leftWheel.setup();
#else
  wheels.setup();
#endif
  flower.setup();
#if SEPARATE_LEAVES
  // TODO: specify pins for separate leaves
  frontLeaves.setup();
  backLeaves.setup();
#else
  leaves.setup();
#endif
}

/**
 * The run method runs the car
 */
void Car::run()
{
  // #if SEPARATE_WHEELS
  //   // TODO: write handler for separate wheels
  // #else
  //   wheels.drive(2000);
  //   delay(5 * SECOND);
  // #endif
  flower.moveAround(true, 1, 3);
#if SEPARATE_LEAVES
  // TODO: write handler for separate leaves
#else
  leaves.moveTo(180);
  leaves.moveTo(0);
#endif
}