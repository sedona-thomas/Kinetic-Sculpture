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

#### Resources for Assembly  
- Makercase - Enclosure Box: https://en.makercase.com/#/ 
- Thingiverse link for 3D printable rose: https://www.thingiverse.com/thing:255980
- Box measurements added to Github

##### Building Box
- Use Makercase webite to build a basic box
- Finger Edge Joints set to smallest Finger Size (0.25075)
- Download Box plans as DXF File (Not SVG for some laser cutting software)
- Use Dremel for holes to insert motor wires, battery pack wires and ESP32 USB-C connection 
-- Use with your own discretion because you want to have the holes big enough to fit each of the components
-- Since the DC motors are glue to the bottom, break the 1st and 4th teeth of the each long side box piece and use the dremel to make the hole big so that the wires can fit through and connect to the bread board
-- For the other two holes (for the battery wires and ESP32 USB-Connection) make sure that the holes are higher than height of the breadboard for easier connection
- Use super glue to attach the parts of the box together
-- Note: For easy detachment if the glue all the sides of the box piece, then just press top onto glued pieces. Since the bottom is attached to other components be gentle when pressing the assembled box pieces on to it

#### Adding Components to Top Box Piece
- 2 Servo motors, and 1 stepper motor were affixed to the top piece using hot glue
- Using a pencil to trace a general outline and the dremel to bore the holes you only need it large enough to fit the top half of the motors
- The stepper motor is in the middle whereas the servo motors are on either end 

####  Adding Components to Bottom Box Piece
- After retrieving laser cutted pieces use the bottom piece to add all the hardware components
- Remove the backing of breadboard and stick to piece
-- Note: The meausurements are specific to the breadboard we used
- For the DC motors and the back axle, use a flat object to glue to each end of the side of the bottom piece that is not stuck to the breadboard
-- Note: We used a small protoboard just for its phyiscal features not technical
- Hot glue the DC motors to either ends of one protoboard
-- Note: Make sure that extended rod side sticks out so wheels can be pushed on to it
- For the other end, small jewelry hooks were forced onto the protoboard and hot glued so that the "axle" could go through each loop. 
- Insert something small enough to fit into the small wheels, a small metal rod was used to stabilize the weight of the project
- For external power a 4 AA battery pack was secured to the bottom of the project (for testing purposes) using hot glue in the middle of the bottom piece 

#### Connecting Wires
- Wires should be soldered the DC motors and the 4 AA Battery pack come with soldered wired
- The should go through the holes in the side pieces that were made prior and inserted into the breadboard

#### Decoration
- Blue and green felt were used to give it its "garden" look. 
- For the blue flowers cut out small inorganic shapes and pinch one end to scrunch the sides together. Afterward, insert some hot glue where the sides meet and the felt was pinched.
- The green felt was used for the leaves and green wiring was used to give it its "raised" look
- For the motor leaves, use one of the addtional attachments that fan out on either side and hot glue three pieces of felt leaves and some wiring(to raise the felt) to the attachement.
- Bore a hole into the base of the 3D printed rose deep enough to fit the stepper motor. Fit the hole with hot glue and then insert the stepper motor
- Use paint how you see fit to recreate look (brown and green acrylic paint was used)
- To conceal holes hot glue "raised" leaves above them and hot glue other decorations to make it look like more of a garden


## More Information

Medium Blog Post: []()

Youtube Demos: [https://youtu.be/uOoaBGFkzKg](https://youtu.be/uOoaBGFkzKg)

##
## Special Thanks to Professor Mark Santolucito and the staff at the Barnard Design Center for all of their help!!!
