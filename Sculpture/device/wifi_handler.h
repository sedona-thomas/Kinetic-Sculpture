#ifndef __WIFI_HANDLER_H__
#define __WIFI_HANDLER_H__

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "esp32_screen.h"
#include "car.h"

#define USE_SERIAL Serial    /**< serial communication */
#define TESTING_MOTORS false /**< whether motors are being tested */

void wifiSetup();
void wifiLoop();

#endif