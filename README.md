# Kinetic-Sculpture

## Materials

 - ESP32 TTGO T-Display (CP 2104 Chip)
 - computer
 - USB-C cord
 - battery
 - 28BYJ-48 Step Motor
 - SG90 Tower Pro MicroServo
 - DC Brush motor (9000 -25000 RPM (3V-12V))

## Make at Home

### Setup Arduino

- Download and open the Arduino IDE ([Download](https://www.arduino.cc/en/software))
- Open Preferences 
- Copy and paste the following link ([https://dl.espressif.com/dl/package_esp32_index.json](https://dl.espressif.com/dl/package_esp32_index.json)) into `Additonal Boards Manager URLs` to add the ESP package
- Select `Tools > Boards > Boards Manager`, then search for `esp32` and install the most recent version
- Select `Tools > Boards > ESP32 Arduino > TTGO T1`
- Select `Tools > Manage Libraries`, then search for `TFT_eSPI` and install the most recent version
- In your file storage system, find the Arduino folder
- Open `Arduino/libraries/TFT_eSPI/User_Setup_Select.h`
- Comment out the line that says `#include <User_Setup.h>`
- Uncomment the line that says `#include <User_Setups/Setup25_TTGO_T_Display.h>`

#### Test ESP32 TTGO T-Display

- Open the Arduino IDE
- Select `Files > Examples > TFT_eSPI > 160 x 128 > RLE_font_test`
- Plug in the ESP32 TTGO T-Display
- Select `Sketch > Upload`

#### Setup Python Serial Ports

- Download Anaconda ([https://www.anaconda.com/products/individual](https://www.anaconda.com/products/individual))
- Open Terminal
- Download pyserial `conda install pyserial`

### Build Clock

#### Step Motor

- Connect IN1 to `GPIO Pin #33`
- Connect IN2 to `GPIO Pin #25`
- Connect IN3 to `GPIO Pin #26`
- Connect IN4 to `GPIO Pin #27`

#### Servo Motor

- Connect the orange wire (first wire) to `GPIO Pin #15`
- Connect the red wire (second wire) to the 5V pin
- Connect the brown wire (third wire) to a ground pin

#### Test ESP32 TTGO T-Display

- Open the Arduino IDE
- Open `Clock_Test/device/device.ino`
- Plug in the ESP32 TTGO T-Display
- Select `Sketch > Upload`

### Build Kinetic Sculpture

#### Step Motor

- Connect IN1 to `GPIO Pin #33`
- Connect IN2 to `GPIO Pin #25`
- Connect IN3 to `GPIO Pin #26`
- Connect IN4 to `GPIO Pin #27`

#### Servo Motor

- Connect the orange wire (first wire) to `GPIO Pin #15`
- Connect the red wire (second wire) to the 5V pin
- Connect the brown wire (third wire) to a ground pin

#### Brush Motor

- Connect the positive terminal to the ____ pin on the ESP32
- Connect the negaitve terminal to a Ground pin on the ESP32

