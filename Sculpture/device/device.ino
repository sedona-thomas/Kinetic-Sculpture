/**
 * The device.ino file manages the functionality of the ESP32
 *
 * @author Sedona Thomas
 * @version 1.0.0
 */

#define BAUDRATE 115200      /**< baudrate for serial communications */
#define DISPLAY_VALUES false /**< true: sensors; false: rainbow background */

#include "wifi_handler.h"

void setupSerial()
{
  Serial.begin(BAUDRATE);
  delay(1000);
}

void setup()
{
  setupSerial();
  setupScreen();
  wifiSetup();
  updateScreen(DISPLAY_VALUES);
}

void loop()
{
  updateScreen(DISPLAY_VALUES);
  wifiLoop();
}
