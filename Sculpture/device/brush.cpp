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
  setup();
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
  setup();
}

/**
 * BrushMotor constructor makes a brush object
 * 
 * @param name_in the brush motor name
 * @param inPin1 the pin that the L293D channel 1 pin is connected to
 * @param inPin2 the pin that the L293D channel 2 pin is connected to
 * @param enablePin the pin that the L293D enable 1 pin is connected to
 */
BrushMotor::BrushMotor(std::string _name, int inPin1, int inPin2, int enablePin)
{
  name = _name;
  ports[0] = inPin1;
  ports[1] = inPin2;
  ports[2] = enablePin;
  setup();
}

/**
 * BrushMotor constructor makes a brush object
 * 
 * @param name_in the brush motor name
 * @param inPin1 the pin that the L293D channel 1 pin is connected to
 * @param inPin2 the pin that the L293D channel 2 pin is connected to
 * @param enablePin the pin that the L293D enable 1 pin is connected to
 * @param _channel the channel
 */
BrushMotor::BrushMotor(std::string _name, int inPin1, int inPin2, int enablePin, int _channel)
{
  name = _name;
  ports[0] = inPin1;
  ports[1] = inPin2;
  ports[2] = enablePin;
  channel = _channel;
  setup();
}

/**
 * The setup method sets up a brush motor
 * 
 * ledcAttachPin() sets pulse width modulation to 11 bits (range 0-2047)
 */
void BrushMotor::setup()
{
  pinMode(ports[0], OUTPUT);
  pinMode(ports[1], OUTPUT);
  pinMode(ports[2], OUTPUT);
  ledcSetup(channel, 1000, 11); 
  ledcAttachPin(ports[2], channel);
  reset();
}

/**
 * The reset method moves the motor into its initial resting state
 */
void BrushMotor::reset()
{
  potentiometerValue = 100;
  rotationSpeed = 100;
  rotationDirection = true;
}

/**
 * The test method moves the motor moves forward and backward
 */
void BrushMotor::test()
{
  rotateClockwise();
  delay(10 * SECOND);
  rotateCounterclockwise();
  delay(10 * SECOND);
  reset();
}

/**
 * The driveMotor method rotates the brush motor
 * 
 * @param direction whether the direction is forward
 * @param speed the speed of the motor (range 0-2048)
 */
void BrushMotor::driveMotor(bool direction, int speed) {
  if (direction) {
    digitalWrite(ports[0], HIGH);
    digitalWrite(ports[1], LOW);
  } else {
    digitalWrite(ports[0], LOW);
    digitalWrite(ports[1], HIGH);
  }
  ledcWrite(channel, speed);
}

/**
 * The drive method rotates the brush motor at the given speed
 * 
 * @param speed the speed of the motor (range 0-2048)
 */
void BrushMotor::drive(int speed)
{
  potentiometerValue = 2048 + speed;
  motorDirection();
  motorSpeed();
  driveMotor(rotationDirection, constrain(rotationSpeed, 0, 2048));
}

/**
 * The rotate method rotates the brush motor
 */
void BrushMotor::rotate()
{
  motorDirection();
  motorSpeed();
  driveMotor(rotationDirection, constrain(rotationSpeed, 0, 2048));
}

/**
 * The rotateCounterclockwise method rotates the brush motor counterclockwise
 */
void BrushMotor::rotateCounterclockwise()
{
  if (READ_POTENTIOMETER) {
    potentiometerValue = analogRead(potentiometerPin);
  } else {
    potentiometerValue = 2048 - 1000;
  }
  rotate();
}

/**
 * The rotateClockwise method rotates the brush motor clockwise
 */
void BrushMotor::rotateClockwise()
{
  if (READ_POTENTIOMETER) {
    potentiometerValue = analogRead(potentiometerPin);
  } else {
    potentiometerValue = 2048 + 1000;
  }
  rotate();
}

/**
 * The motorSpeed method calculates the current rotation speed
 */
void BrushMotor::motorSpeed() {
  rotationSpeed = abs(potentiometerValue - 2048);
}

/**
 * The motorDirection method calculates the current rotation direction
 */
void BrushMotor::motorDirection() {
  if (potentiometerValue > 2048) {
    rotationDirection = true;
  } else {
    rotationDirection = false;
  }
}