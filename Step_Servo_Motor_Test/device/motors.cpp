#include "motors.h"

StepMotor::StepMotor() {
  name = "step";
  outPorts[0] = 33;
  outPorts[1] = 25;
  outPorts[2] = 26;
  outPorts[3] = 27;
}

StepMotor::StepMotor(std::string _name) {
  name = _name;
  outPorts[0] = 33;
  outPorts[1] = 25;
  outPorts[2] = 26;
  outPorts[3] = 27;
}

StepMotor::StepMotor(std::string _name, int in1, int in2, int in3, int in4) {
  name = _name;
  outPorts[0] = in1;
  outPorts[1] = in2;
  outPorts[2] = in3;
  outPorts[3] = in4;
}

void StepMotor::setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(outPorts[i], OUTPUT);
  }
}

void StepMotor::run() {
  moveSteps(true, 32 * 64, 3);
  delay(1000);
  moveSteps(false, 32 * 64, 3);
  delay(1000);
}

void StepMotor::moveSecond() {
  moveSteps(true, floor(32 * 64 / 60), STEP_DELAY);
}

void StepMotor::moveMinute() {
  for (int i = 0; i < 60; i++) {
    moveSecond();
    delay(SECOND - STEP_DELAY);
  }
  moveSteps(true, 32 * 64 - floor(32 * 64 / 60), 3);
}

void StepMotor::moveSteps(bool dir, int steps, byte ms) {
  for (unsigned long i = 0; i < steps; i++) {
    moveOneStep(dir);
    delay(constrain(ms, 3, 20));
  }
}

void StepMotor::moveOneStep(bool dir) {
  static byte out = 0x01;
  if (dir) {
    out != 0x08 ? out = out << 1 : out = 0x01;
  } else {
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

void StepMotor::moveAround(bool dir, int turns, byte ms) {
  for (int i = 0; i < turns; i++)
    moveSteps(dir, 32 * 64, ms);
}

void StepMotor::moveAngle(bool dir, int angle, byte ms) {
  moveSteps(dir, (angle * 32 * 64 / 360), ms);
}

////////////////////////////////////////////////////////////////////////////////

ServoMotor::ServoMotor() {
  name = "servo";
  port = 15;
}

ServoMotor::ServoMotor(std::string _name) {
  name = _name;
  port = 15;
}

ServoMotor::ServoMotor(std::string _name, int pin) {
  name = _name;
  port = pin;
}

void ServoMotor::setup() {
  motor.setPeriodHertz(50);
  motor.attach(port, 500, 2500);
  reset();
}

void ServoMotor::reset() {
  posVal = 0;
  motor.write(posVal);
}

void ServoMotor::run() {
  for (int p = 0; p <= 180; p += 1) {
    motor.write(p);
    delay(15);
  }
  for (int p = 180; p >= 0; p -= 1) {
    motor.write(p);
    delay(15);
  }
  reset();
}

void ServoMotor::rotateCounterclockwise(int degrees) {
  for (; posVal <= degrees; posVal += 1) {
    motor.write(posVal);
    delay(SERVO_DELAY);
  }
}

void ServoMotor::rotateClockwise(int degrees) {
  for (; posVal >= degrees; posVal -= 1) {
    motor.write(posVal);
    delay(SERVO_DELAY);
  }
}

void ServoMotor::moveMinute() {
  if (posVal >= 180) {
    rotateCounterclockwise(180);
  }
  rotateClockwise(10);
}