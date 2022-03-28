StepMotor::StepMotor(std::string _name) {
  name = _name;
  outPorts = {33, 27, 26, 25};
}

StepMotor::StepMotor(std::string _name, int in1, int in2, int in3, int in4) {
  name = _name;
  outPorts = {in1, in2, in3, in4};
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


ServoMotor::ServoMotor(std::string _name) {
  name = _name;
  outPorts = 15;
}

ServoMotor::ServoMotor(std::string _name, int pin) {
  name = _name;
  port = pin;
}

void ServoMotor::setup() {
  myservo.setPeriodHertz(50);
  myservo.attach(port, 500, 2500);
}

void ServoMotor::run() {
  for (posVal = 0; posVal <= 180;
       posVal += 1) {
    myservo.write(posVal);
    delay(15);
  }
  for (posVal = 180; posVal >= 0;
       posVal -= 1) {
    myservo.write(posVal);
    delay(15);
  }
}