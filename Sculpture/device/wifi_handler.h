#ifndef __WIFI_HANDLER_H__
#define __WIFI_HANDLER_H__

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "esp32_screen.h"
#include "car.h"

#define USE_SERIAL Serial    /**< serial communication */
#define TESTING_MOTORS false /**< whether motors are being tested */

const char *ssid_Router = "Columbia U Secure"; /**< router name */
const char *password_Router = "";              /**< router password */
String address = "http://165.227.76.232:3000/snt2127/running";
Car car = Car();

void wifiSetup();
void wifiLoop();

#endif