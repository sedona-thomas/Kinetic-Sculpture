#ifndef __MOTORS_H__
#define __MOTORS_H__

#include <Arduino.h>
#include <ESP32Servo.h>
#include <cmath>

#define SECOND 3       // miliseconds (1000 miliseconds : 1 second)
#define STEP_DELAY 3   // miliseconds
#define SERVO_DELAY 15 // miliseconds

class StepMotor {
public:
  StepMotor(std::string, int, int, int, int);
  StepMotor(std::string);
  StepMotor();
  void setup();
  void run();
  void moveSecond();
  void moveMinute();
  void moveSteps(bool, int, byte);
  void moveOneStep(bool);
  void moveAround(bool, int, byte);
  void moveAngle(bool, int, byte);

private:
  std::string name;
  int outPorts[4];
};

class ServoMotor {
public:
  ServoMotor(std::string, int);
  ServoMotor(std::string);
  ServoMotor();
  int getAngle();
  void changeAngle(int);
  void setup();
  void reset();
  void run();
  void moveTo(int);
  void rotateClockwise(int);
  void rotateCounterclockwise(int);
  void moveMinute();

private:
  std::string name;
  Servo motor;
  int port;
  int angle;
};

#endif