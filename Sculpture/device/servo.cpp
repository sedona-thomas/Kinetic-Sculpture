#include "servo.h"

/**
 * ServoMotor constructor makes a servo motor object
 */
ServoMotor::ServoMotor()
{
  name = "servo";
  port = 15;
}

/**
 * ServoMotor constructor makes a servo motor object
 * 
 * @param name_in the servo motor name
 */
ServoMotor::ServoMotor(std::string _name)
{
  name = _name;
  port = 15;
}

/**
 * ServoMotor constructor makes a servo object
 * 
 * @param name_in the servo motor name
 * @param pin_in the pin that the servo motor is connected to
 */
ServoMotor::ServoMotor(std::string _name, int pin)
{
  name = _name;
  port = pin;
}

/**
 * The setup method sets up a servo motor
 */
void ServoMotor::setup()
{
  motor.setPeriodHertz(50);
  motor.attach(port, 500, 2500);
  reset();
}

/**
 * The reset method moves the motor into its initial resting state
 */
void ServoMotor::reset()
{
  angle = 0;
  motor.write(angle);
}

/**
 * The getAngle method returns the current angle
 * 
 * @return current angle of the servo motor
 */
int ServoMotor::getAngle() { return angle; }

/**
 * The changeAngle method changes the current angle
 * 
 * @param change the value to add to the angle
 */
void ServoMotor::changeAngle(int change) { angle += change; }

/**
 * The test method moves the servo motor back and forth then resets
 */
void ServoMotor::test()
{
  for (int p = 0; p <= 180; p += 1)
  {
    motor.write(p);
    delay(15);
  }
  for (int p = 180; p >= 0; p -= 1)
  {
    motor.write(p);
    delay(15);
  }
  reset();
}

/**
 * The moveTo method moves the servo motor to the specified angle
 * 
 * @param newAngle the new angle to move the motor arm to
 */
void ServoMotor::moveTo(int newAngle)
{
  if (angle < newAngle)
  {
    for (; angle <= newAngle; angle += 1)
    {
      motor.write(angle);
      delay(SERVO_DELAY);
    }
  }
  else
  {
    for (; angle >= newAngle; angle -= 1)
    {
      motor.write(angle);
      delay(SERVO_DELAY);
    }
  }
}

/**
 * The rotateCounterclockwise method rotates the servo motor counterclockwise
 * 
 * @param degrees the degrees to move counterclockwise
 */
void ServoMotor::rotateCounterclockwise(int degrees)
{
  for (; angle <= angle + degrees; angle += 1)
  {
    motor.write(angle);
    delay(SERVO_DELAY);
  }
}

/**
 * The rotateClockwise method rotates the servo motor clockwise
 * 
 * @param degrees the degrees to move clockwise
 */
void ServoMotor::rotateClockwise(int degrees)
{
  for (; angle >= angle - degrees; angle -= 1)
  {
    motor.write(angle);
    delay(SERVO_DELAY);
  }
}
