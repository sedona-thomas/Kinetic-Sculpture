#include "servo.h"

ServoMotor::ServoMotor()
{
  name = "servo";
  port = 15;
}

ServoMotor::ServoMotor(std::string _name)
{
  name = _name;
  port = 15;
}

ServoMotor::ServoMotor(std::string _name, int pin)
{
  name = _name;
  port = pin;
}

void ServoMotor::setup()
{
  motor.setPeriodHertz(50);
  motor.attach(port, 500, 2500);
  reset();
}

void ServoMotor::reset()
{
  angle = 0;
  motor.write(angle);
}

int ServoMotor::getAngle() { return angle; }

void ServoMotor::changeAngle(int change) { angle += change; }

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

void ServoMotor::rotateCounterclockwise(int degrees)
{
  for (; angle <= angle + degrees; angle += 1)
  {
    motor.write(angle);
    delay(SERVO_DELAY);
  }
}

void ServoMotor::rotateClockwise(int degrees)
{
  for (; angle >= angle - degrees; angle -= 1)
  {
    motor.write(angle);
    delay(SERVO_DELAY);
  }
}
