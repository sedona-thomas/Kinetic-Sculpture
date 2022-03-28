/*
 * device.ino: reads values from an Esp32 and sends them as serial data
 */

#define BAUDRATE 115200      // baudrate for serial communications
#define DISPLAY_VALUES false // true: sensors; false: rainbow background

#include "esp32_screen.h"
#include "motors.h"
#include <SPI.h>
#include <TFT_eSPI.h>
#include <list>
#include <stdint.h>
#include <string>

StepMotor step;
ServoMotor servo;

void setupMotors() {
  step = StepMotor();
  servo = ServoMotor();
}

void runMotors() {}

void setup() {
  setupScreen();
  setupMotors();
}

void loop() {
  updateScreen(DISPLAY_VALUES);
  runMotors();
  delay(FRAMERATE);
}
