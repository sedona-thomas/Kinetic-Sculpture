#ifndef __SERVO_H__
#define __SERVO_H__

#include <Arduino.h>
#include <ESP32Servo.h>
#include <cmath>

#define SECOND 1000    // miliseconds (1000 miliseconds : 1 second)
#define SERVO_DELAY 15 // miliseconds

class ServoMotor
{
public:
  ServoMotor(std::string, int);
  ServoMotor(std::string);
  ServoMotor();
  int getAngle();
  void changeAngle(int);
  void setup();
  void reset();
  void test();
  void moveTo(int);
  void rotateClockwise(int);
  void rotateCounterclockwise(int);

private:
  std::string name;
  Servo motor;
  int port;
  int angle;
};

#endif