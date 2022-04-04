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
  rotateCounterClockwise();
  delay(10 * SECOND);
  reset();
}

/**
 * The rotate method rotates the brush motor
 */
void BrushMotor::driveMotor(boolean direction, int speed) {
  if (dirextion) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  } else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
  ledcWrite(channel, speed);
}

/**
 * The rotate method rotates the brush motor
 */
void BrushMotor::rotate()
{
  rotationSpeed = potentiometerValue - 2048;
  if (potentiometerValue > 2048) {
    rotationDirection = true;
  } else {
    rotationDirection = false;
  }
  motorSpeed();
  // Control the steering and speed of the motor
  driveMotor(rotationDirection, constrain(rotationSpeed, 0, 2048));
}

/**
 * The rotateCounterclockwise method rotates the brush motor counterclockwise
 */
void BrushMotor::rotateCounterclockwise()
{
  if (READ_POTENTIOMETER) {
    potentiometerValue = analogRead(A0);
  } else {
    potentiometerValue = 2048 - 200;
  }
  rotate();
}

/**
 * The rotateClockwise method rotates the brush motor clockwise
 */
void BrushMotor::rotateClockwise()
{
  if (READ_POTENTIOMETER) {
    potentiometerValue = analogRead(A0);
  } else {
    potentiometerValue = 2048 + 200;
  }
  rotate();
}

/**
 * The speed method calculates the current rotation speed
 */
void BrushMotor::motorSpeed() {
  rotationSpeed = abs(potentiometerValue - 2048);
}




void loop() {
  int potenVal = 100;
  //analogRead(A0); // Convert the voltage of rotary potentiometer into digital
  // Compare the number with value 2048,
  // if more than 2048, clockwise rotates, otherwise, counter clockwise rotates
  rotationSpeed = potenVal - 2048;
  if (potenVal > 2048)
    rotationDirection = true;
  else
    rotationDirection = false;
  // Calculate the motor speed
  rotationSpeed = abs(potenVal - 2048);
  // Control the steering and speed of the motor
  driveMotor(rotationDirection, constrain(rotationSpeed, 0, 2048));
}