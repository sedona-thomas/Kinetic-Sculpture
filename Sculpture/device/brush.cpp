#include "brush.h"

/**
 * BrushMotor constructor makes a brush motor object
 */
BrushMotor::BrushMotor()
{
  name = "brush";
  port = 15;
}

/**
 * BrushMotor constructor makes a brush motor object
 * 
 * @param name_in the brush motor name
 */
BrushMotor::BrushMotor(std::string _name)
{
  name = _name;
  port = 15;
}

/**
 * BrushMotor constructor makes a brush object
 * 
 * @param name_in the brush motor name
 * @param pin_in the pin that the brush motor is connected to
 */
BrushMotor::BrushMotor(std::string _name, int pin)
{
  name = _name;
  port = pin;
}

/**
 * The setup method sets up a brush motor
 */
void BrushMotor::setup()
{
  reset();
}

/**
 * The reset method moves the motor into its initial resting state
 */
void BrushMotor::reset()
{
}

/**
 * The test method moves the brush motor back and forth then resets
 */
void BrushMotor::test()
{
  //
  reset();
}

/**
 * The rotateCounterclockwise method rotates the brush motor counterclockwise
 */
void BrushMotor::rotateCounterclockwise()
{
}

/**
 * The rotateClockwise method rotates the brush motor clockwise
 */
void BrushMotor::rotateClockwise()
{
}
