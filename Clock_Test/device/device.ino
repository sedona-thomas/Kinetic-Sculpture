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

  servo.moveTo(0);
  delay(5000);
  servo.moveTo(10);
  delay(1000);
  servo.moveTo(20);
  delay(1000);
  servo.moveTo(30);
  delay(1000);
  servo.moveTo(180);
  delay(1000);

  /*
  for (int i = 0; i < 20; i++) {
    if (servo.getAngle() >= 180) {
      Serial.println("A");
      servo.rotateCounterclockwise(0);
      Serial.println("B");
    } else {
      Serial.println("C");
      for (; servo.getAngle() >= servo.getAngle() - (180 / 10);
           servo.changeAngle(-1)) {
        motor.write(servo.getAngle());
        delay(10);
      }
      // servo.rotateClockwise(180 / 10);
      Serial.println("D");
    }
    Serial.println("E");
    delay(15);
    Serial.println("Next");
    Serial.println(servo.getAngle());
  }
  */
}

void runClock() {
  for (int angle = 0; true; angle = (angle + 10) % 190) {
    step.moveMinute();
    servo.moveTo(angle);
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
  // runMotors();
  runClock();
}