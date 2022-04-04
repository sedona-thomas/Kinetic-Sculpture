/**
 * The esp32 screen methods handle an ESP TFT display
 * 
 * @author Sedona Thomas
 */

#include "esp32_screen.h"

TFT_eSPI tft = TFT_eSPI(); /**< defines TFT screen object */
uint32_t currentBackgroundColor = TFT_WHITE; /**< defines current background color */
uint32_t currentTextColor = TFT_BLACK; /**< defines current text color */
uint8_t currentTextSize = 1; /**< defines current text size (1 size value == 10 pixels) */

/**
 * The setupScreen starts ESP32 screen and sets the rotation
 */
void setupScreen() {
  tft.init();
  tft.setRotation(2);
}

/** 
 * The resetScreen method resets the background and text color/size of the display
 */
void resetScreen() {
  tft.setTextSize(currentTextSize);
  tft.fillScreen(currentBackgroundColor);
  tft.setTextColor(currentTextColor);
  tft.setCursor(1, 1, currentTextSize);
  tft.setRotation(2);
}

/** 
 * The updateScreen method updates current screen with sensor values or as a rainbow background
 * 
 * @param display_values defines whether values are being displayed
 */
void updateScreen(bool display_values) {
  resetScreen();
  if (!display_values) {
    rainbowBackground();
  } else {
    randomBackground();
  }
}

/**
 * The printToScreen method prints a string to the ESP32 screen
 * 
 * @param s string to be printed to the screen
 */
void printToScreen(std::string s) { tft.println(getArduinoString(s)); }

/**
 * The printSensorToScreen method prints a sensor value to the ESP32 screen
 * 
 * @param name name of the sensor
 * @param value value of the sensor
 */
void printSensorToScreen(std::string name, uint8_t value) {
  tft.println(getArduinoString(name));
  tft.println(value);
}

/**
 * The getArduinoString method turns a std::string into an Arduino String
 * 
 * @param str string to be converted
 * @return String object representing inputted string
 */
String getArduinoString(std::string str) { return (String)str.c_str(); }

/**
 * The getLetterVector method turns a std::string into an Arduino String vector
 * 
 * @param str string to be converted
 * @return String vector containing the characters of the inputted string
 */
std::vector<String> getLetterVector(std::string str) {
  std::vector<String> letters;
  for (int i = 0; i < str.size(); i++) {
    letters.push_back(String(str[i]));
  }
  return letters;
}

/**
 * The randomColor method outputs a random pastel RGB color
 * 
 * @return random RGB color
 */
inline uint16_t randomColor() {
  return getRGB(random(0, 255) / 2, random(0, 255) / 2, random(0, 255) / 2);
}

/**
 * The getRGB method converts an RGB value to an Arduino color value 
 * 
 * @param r red color intensity
 * @param g green color intensity
 * @param b blue color intensity
 * @return Arduino color value representing the inputted RGB value
 * @see https://stackoverflow.com/questions/13720937/c-defined-16bit-high-color
 */
inline uint16_t getRGB(uint8_t r, uint8_t g, uint8_t b) {
  return ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
}

/**
 * The randomBackground method makes the background a random color
 */
void randomBackground() {
  currentBackgroundColor = randomColor();
  resetScreen();
}

/**
 * The rainbowBackground method makes the background a scrolling rainbow gradient
 */
void rainbowBackground() {
  tft.setRotation(1);
  byte red = 31, green = 0, blue = 0, state = 0;
  unsigned int colour = red << 11;
  for (int i = 0; i < tft.width(); i++) {
    tft.drawFastVLine(i, 0, tft.height(), colour);
    switch (state) {
    case 0:
      green += 2;
      if (green == 64) {
        green = 63;
        state = 1;
      }
      break;
    case 1:
      red--;
      if (red == 255) {
        red = 0;
        state = 2;
      }
      break;
    case 2:
      blue++;
      if (blue == 32) {
        blue = 31;
        state = 3;
      }
      break;
    case 3:
      green -= 2;
      if (green == 255) {
        green = 0;
        state = 4;
      }
      break;
    case 4:
      red++;
      if (red == 32) {
        red = 31;
        state = 5;
      }
      break;
    case 5:
      blue--;
      if (blue == 255) {
        blue = 0;
        state = 0;
      }
      break;
    }
    colour = red << 11 | green << 5 | blue;
  }
}