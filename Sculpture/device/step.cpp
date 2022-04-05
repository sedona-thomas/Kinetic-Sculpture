#include "step.h"

/**
 * StepMotor constructor makes a step motor object
 */
StepMotor::StepMotor()
{
  name = "step";
  outPorts[0] = 33;
  outPorts[1] = 25;
  outPorts[2] = 26;
  outPorts[3] = 27;
  setup();
}

/**
 * StepMotor constructor makes a step motor object
 *
 * @param name_in the step motor name
 */
StepMotor::StepMotor(std::string _name)
{
  name = _name;
  outPorts[0] = 33;
  outPorts[1] = 25;
  outPorts[2] = 26;
  outPorts[3] = 27;
  setup();
}

/**
 * StepMotor constructor makes a step object
 *
 * @param name_in the step motor name
 * @param in1 the pin that the step motor in1 is connected to
 * @param in2 the pin that the step motor in2 is connected to
 * @param in3 the pin that the step motor in3 is connected to
 * @param in4 the pin that the step motor in4 is connected to
 */
StepMotor::StepMotor(std::string _name, int in1, int in2, int in3, int in4)
{
  name = _name;
  outPorts[0] = in1;
  outPorts[1] = in2;
  outPorts[2] = in3;
  outPorts[3] = in4;
  setup();
}

/**
 * The setup method sets up a step motor
 */
void StepMotor::setup()
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(outPorts[i], OUTPUT);
  }
}

/**
 * The test method moves the step motor back and forth then resets
 */
void StepMotor::test()
{
  moveSteps(true, 32 * 64, 3);
  delay(1000);
  moveSteps(false, 32 * 64, 3);
  delay(1000);
}

/**
 * The moveSteps method moves the specified number of steps in the specified direction
 *
 * @param dir direction to move (true if clockwise else false)
 * @param steps number of steps to move
 * @param ms miliseconds to delay between rotation steps
 */
void StepMotor::moveSteps(bool dir, int steps, byte ms)
{
  for (unsigned long i = 0; i < steps; i++)
  {
    moveOneStep(dir);
    delay(constrain(ms, 3, 20));
  }
}

/**
 * The moveOneStep method moves one step in the specified direction
 *
 * @param dir direction to move (true if clockwise else false)
 */
void StepMotor::moveOneStep(bool dir)
{
  static byte out = 0x01;
  if (dir)
  {
    out != 0x08 ? out = out << 1 : out = 0x01;
  }
  else
  {
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

/**
 * The moveAround method moves full rotations at a controlled speed
 *
 * @param dir direction to move (true if clockwise else false)
 * @param turns number of full rotations to make
 * @param ms miliseconds to delay between rotation steps
 */
void StepMotor::moveAround(bool dir, int turns, byte ms)
{
  for (int i = 0; i < turns; i++)
    moveSteps(dir, 32 * 64, ms);
}

/**
 * The moveAngle method moves the step motor by the specified angle
 *
 * @param dir direction to move (true if clockwise else false)
 * @param angle angle by which to turn
 * @param ms miliseconds to delay between rotation steps
 */
void StepMotor::moveAngle(bool dir, int angle, byte ms)
{
  moveSteps(dir, (angle * 32 * 64 / 360), ms);
}
