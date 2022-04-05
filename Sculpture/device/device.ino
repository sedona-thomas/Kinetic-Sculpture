/**
 * The device.ino file manages the functionality of the ESP32
 *
 * @author Sedona Thomas
 * @version 1.0.0
 */

#define BAUDRATE 115200      /**< baudrate for serial communications */
#define DISPLAY_VALUES false /**< true: sensors; false: rainbow background */
#define TESTING_MOTORS false /**< whether motors are being tested */

#include "esp32_screen.h"
#include "car.h"

Car car = Car();

#if TESTING_MOTORS
#include "step.h"
#include "servo.h"
#include "brush.h"
StepMotor step = StepMotor("flower", 33, 25, 26, 27);
ServoMotor servo = ServoMotor("leaves", 2);
BrushMotor brush = BrushMotor("wheels", 12, 15, 13);
void setupMotors()
{
  step.setup();
  servo.setup();
  brush.setup();
}
void testMotors()
{
  step.test();
  servo.test();
  brush.test();
}
#endif

void setupSerial()
{
  Serial.begin(BAUDRATE);
  delay(1000);
}

void setup()
{
  setupSerial();
  setupScreen();
  car.setup();
  updateScreen(DISPLAY_VALUES);
}

void loop()
{
  updateScreen(DISPLAY_VALUES);
  car.run();
}
