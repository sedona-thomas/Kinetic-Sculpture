/*
 * device.ino: reads values from an Esp32 and sends them as serial data
 */

#define DISPLAY_VALUES false // true: sensors; false: rainbow background

#include "esp32_screen.h"
#include "motors.h"
#include <SPI.h>
#include <TFT_eSPI.h>

StepMotor step = StepMotor();
ServoMotor servo = ServoMotor();

void setupMotors() {
  step.setup();
  servo.setup();

  // step.run();
  // servo.run();
}

void runMotors() {
  // step.moveMinute();
  servo.moveMinute();
}

void setup() {
  setupScreen();
  updateScreen(DISPLAY_VALUES);
  setupMotors();
}

void loop() { runMotors(); }