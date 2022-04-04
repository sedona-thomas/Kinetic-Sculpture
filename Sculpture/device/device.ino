/**
 * The device.ino file manages the functionality of the ESP32
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */


#define BAUDRATE 115200      /**< baudrate for serial communications */
#define DISPLAY_VALUES false /**< true: sensors; false: rainbow background */

#include "esp32_screen.h"
//#include "car.h"

//#include "brush.h"

//Car car = Car();

/*
BrushMotor motor = BrushMotor();

void setupSerial() {
  Serial.begin(BAUDRATE);
  delay(1000);
}

void test() {
  motor.test();
}

void testingLoop() {
  updateScreen(true);//DISPLAY_VALUES);
  test();
  delay(FRAMERATE);
}

void setup() {
  setupSerial();
  setupScreen();
  updateScreen(DISPLAY_VALUES);
}

void loop() {
  testingLoop();
}
*/


int in1Pin = 12;     // Define L293D channel 1 pin
int in2Pin = 15;     // Define L293D channel 2 pin
int enable1Pin = 13; // Define L293D enable 1 pin
int channel = 0;

boolean rotationDir; // Define a variable to save the motor's rotation direction
int rotationSpeed;   // Define a variable to save the motor rotation speed

void driveMotor(boolean dir, int spd) {
  if (dir) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  } else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
  ledcWrite(channel, spd);
}

void setup() {
  setupScreen();
  
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  ledcSetup(channel, 1000, 11); // Set PWM to 11 bits, range is 0-2047
  ledcAttachPin(enable1Pin, channel);
}

void loop() {
  delay(FRAMERATE);
  updateScreen(true);

  int potenVal = 100;
  rotationSpeed = potenVal - 2048;
  if (potenVal > 2048)
    rotationDir = true;
  else
    rotationDir = false;
  rotationSpeed = abs(potenVal - 2048);
  driveMotor(rotationDir, constrain(rotationSpeed, 0, 2048));
}