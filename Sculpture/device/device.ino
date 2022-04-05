/**
 * The device.ino file manages the functionality of the ESP32
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */

#define BAUDRATE 115200      /**< baudrate for serial communications */
#define DISPLAY_VALUES false /**< true: sensors; false: rainbow background */

#include "esp32_screen.h"
#include "car.h"

Car car = Car();

void setupSerial() {
  Serial.begin(BAUDRATE);
  delay(1000);
}

void test() {
  car.run();
}

void testingLoop() {
  updateScreen(true);
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
