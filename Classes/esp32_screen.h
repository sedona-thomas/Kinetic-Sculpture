/**
 * The esp32 header file handles an ESP TFT display
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */

#ifndef __ESP32_SCREEN_H__
#define __ESP32_SCREEN_H__

#include <SPI.h>
#include <TFT_eSPI.h>
#include <stdint.h>
#include <string>

#define WAIT 500     /**< miliseconds */
#define FRAMERATE 50 /**< miliseconds */

TFT_eSPI tft = TFT_eSPI(); /**< defines TFT screen object */
uint32_t currentBackgroundColor = TFT_WHITE; /**< defines current background color */
uint32_t currentTextColor = TFT_BLACK; /**< defines current text color */
uint8_t currentTextSize = 1; /**< defines current text size (1 size value == 10 pixels) */

void setupScreen();
void resetScreen();
void updateScreen(bool display_values);
void printToScreen(std::string s);
void printSensorToScreen(std::string name, uint8_t value);
String getArduinoString(std::string str);
std::vector<String> getLetterVector(std::string str);
inline uint16_t randomColor();
inline uint16_t getRGB(uint8_t r, uint8_t g, uint8_t b);
void rainbowBackground();

#endif