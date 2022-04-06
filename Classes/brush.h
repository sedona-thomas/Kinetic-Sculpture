#ifndef __BRUSH_H__
#define __BRUSH_H__

#include <Arduino.h>
#include <cmath>
#include <string>
#include <stdint.h>

#define SECOND 1000              /**< miliseconds (1000 miliseconds : 1 second) */
#define READ_POTENTIOMETER false /**< whether or not a potentiometer is connected */

/**
 * The BrushMotor class controls the necessary features of a DC brush motor
 *
 * @author Sedona Thomas
 * @version 1.0.0
 */
class BrushMotor
{
public:
  BrushMotor(std::string, int, int, int, int);
  BrushMotor(std::string, int, int, int);
  BrushMotor(std::string);
  BrushMotor();
  void setup();
  void reset();
  void test();
  void driveMotor(bool, int);
  void drive(int);
  void rotate();
  void rotateClockwise();
  void rotateCounterclockwise();
  void motorSpeed();
  void motorDirection();

private:
  std::string name;
  int ports[3]; /**< Ports use GPOI pins {12, 15, 13} by default */
  int potentiometerPin;
  int channel;
  int potentiometerValue;
  int rotationSpeed;
  bool rotationDirection;
};

#endif