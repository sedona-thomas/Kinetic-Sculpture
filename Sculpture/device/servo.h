#ifndef __SERVO_H__
#define __SERVO_H__

#include <Arduino.h>
#include <ESP32Servo.h>
#include <cmath>
#include <string>
#include <stdint.h>

#define SECOND 1000    /**< miliseconds (1000 miliseconds : 1 second) */
#define SERVO_DELAY 15 /**< miliseconds */

/**
 * The ServoMotor class controls the necessary features of a Servo motor
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */
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
  int port; /**< Port uses GPOI pin 2 by default */
  int angle;
};

#endif