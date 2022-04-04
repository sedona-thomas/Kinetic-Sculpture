#ifndef __BRUSH_H__
#define __BRUSH_H__

#include <Arduino.h>

#include <cmath>

#define SECOND 1000    /**< miliseconds (1000 miliseconds : 1 second) */

/**
 * The BrushMotor class controls the necessary features of a DC brush motor
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */
class BrushMotor
{
public:
  BrushMotor(std::string, int);
  BrushMotor(std::string);
  BrushMotor();
  void setup();
  void reset();
  void test();
  void rotateClockwise();
  void rotateCounterclockwise();

private:
  std::string name;
  int port; /**< Port uses GPOI pin 15 by default */
};

#endif