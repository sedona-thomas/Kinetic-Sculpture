/**
 * The device.ino file manages the functionality of the ESP32
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */


#define BAUDRATE 115200      /**< baudrate for serial communications */
#define DISPLAY_VALUES false /**< true: sensors; false: rainbow background */

#include <SPI.h>
#include <TFT_eSPI.h>
#include "esp32_screen.h"

void setupSerial() {
  Serial.begin(BAUDRATE);
  delay(1000);
}

void setup() {
  setupSerial();
  setupScreen();
  updateScreen(DISPLAY_VALUES);
}

void loop() {
}