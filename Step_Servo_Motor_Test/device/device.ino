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
  Serial.println("Setup1");
  step.setup();
  servo.setup();

  // step.run();
  // servo.run();

  Serial.println("Setup2");
}

void runMotors() {
  Serial.println("Start Run");
  // step.moveMinute();
  // servo.moveMinute();
  Serial.println("Run");

  for (int i = 0; i < 20; i++) {
    if (servo.getAngle() >= 180) {
      servo.rotateCounterclockwise(0);
    } else {
      servo.rotateClockwise(180 / 10);
    }
    delay(SERVO_DELAY);
    Serial.println("Next");
    Serial.println(servo.getAngle());
  }
}

// setupSerial(): starts serial communication
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
  Serial.println("Loop");
  runMotors();
}