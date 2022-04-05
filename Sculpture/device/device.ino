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

//#include "step.h"
#include "servo.h"
//#include "brush.h"

// Car car = Car();

// StepMotor step = StepMotor("flower", 33, 25, 26, 27);
ServoMotor servo = ServoMotor(2);
// BrushMotor brush = BrushMotor();

void setupSerial()
{
  Serial.begin(BAUDRATE);
  delay(1000);
}

void test()
{
  // car.run();
  printToScreen("testing");
  // step.test();
  servo.test();
  // brush.test();
  printToScreen("endTesting");
}

void testingLoop()
{
  updateScreen(true);
  test();
  // delay(FRAMERATE);
}

void setup()
{
  setupSerial();
  setupScreen();
  updateScreen(DISPLAY_VALUES);
}

void loop()
{
  test();
  delay(1000);
}
