#ifndef __MOTORS_H__
#define __MOTORS_H__

#include <Arduino.h>
#include <ESP32Servo.h>

class StepMotor {
public:
  StepMotor(std::string, int, int, int, int);
  StepMotor(std::string);
  StepMotor();
  void setup();
  void run();
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
  void setup();
  void run();

private:
  std::string name;
  Servo motor;
  int port;
  int posVal;
};

#endif