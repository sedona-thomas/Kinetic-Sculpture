
class StepMotor {
public:
  StepMotor(std::string, int, int, int, int);
  StepMotor(std::string);
  void setup();
  void run();
  void moveSteps(bool, int, byte);
  void moveOneStep(bool);
  void moveAround(bool, int, byte);
  void moveAngle(bool, int, byte);

private:
  std::string name;
  int outPorts[];
}

class ServoMotor {
public:
  ServoMotor(std::string, int);
  ServoMotor(std::string);
  void setup();
  void run();

private:
  std::string name;
  int port;
}