#include "brush.h"

/**
 * BrushMotor constructor makes a brush motor object
 */
BrushMotor::BrushMotor()
{
  name = "brush";
  ports[0] = 12;
  ports[1] = 15;
  ports[2] = 13;
  channel = 0;
}

/**
 * BrushMotor constructor makes a brush motor object
 * 
 * @param name_in the brush motor name
 */
BrushMotor::BrushMotor(std::string _name)
{
  name = _name;
  ports[0] = 12;
  ports[1] = 15;
  ports[2] = 13;
  channel = 0;
}

/**
 * BrushMotor constructor makes a brush object
 * 
 * @param name_in the brush motor name
 * @param inPin1 the pin that the in driver 1 pin is connected to
 * @param inPin2 the pin that the in driver 2 pin is connected to
 * @param enablePin the pin that the enable driver 1 pin is connected to
 */
BrushMotor::BrushMotor(std::string _name, int inPin1, int inPin2, int enablePin)
{
  name = _name;
  ports[0] = inPin1;
  ports[1] = inPin2;
  ports[2] = enablePin;
}

/**
 * BrushMotor constructor makes a brush object
 * 
 * @param name_in the brush motor name
 * @param inPin1 the pin that the in driver 1 pin is connected to
 * @param inPin2 the pin that the in driver 2 pin is connected to
 * @param enablePin the pin that the enable driver 1 pin is connected to
 * @param _channel the channel
 */
BrushMotor::BrushMotor(std::string _name, int inPin1, int inPin2, int enablePin, int _channel)
{
  name = _name;
  ports[0] = inPin1;
  ports[1] = inPin2;
  ports[2] = enablePin;
  channel = _channel;
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
