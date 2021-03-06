/*
 * device.ino: reads values from an Esp32 and sends them as serial data
 */

#define BAUDRATE 115200      // baudrate for serial communications
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
}

void runClock() {
  for (int angle = 0; true; angle = (angle + 10) % 190) {
    step.moveMinute();
    servo.moveTo(angle);
  }
}

void setupSerial() {
  Serial.begin(BAUDRATE);
  delay(1000);
}

void setup() {
  setupSerial();
  setupScreen();
  updateScreen(DISPLAY_VALUES);
  setupMotors();
}

void loop() {
  runClock();
}