#include "wifi_handler.h"

void wifiSetup()
{
    car.setup();
    USE_SERIAL.begin(115200);
    WiFi.begin(ssid_Router, password_Router);
    USE_SERIAL.println(String("Connecting to ") + ssid_Router);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        USE_SERIAL.print(".");
    }
    USE_SERIAL.println("\nConnected, IP address: ");
    USE_SERIAL.println(WiFi.localIP());
    USE_SERIAL.println("Setup End");
}

void wifiLoop()
{
    if ((WiFi.status() == WL_CONNECTED))
    {
        HTTPClient http;
        http.begin(address);

        int httpCode = http.GET(); // start connection and send HTTP header
        if (httpCode == HTTP_CODE_OK)
        {
            String response = http.getString();
            if (response.equals("false"))
            {
                // Do not run sculpture, perhaps sleep for a couple seconds
            }
            else if (response.equals("true"))
            {
                car.run();
            }
            USE_SERIAL.println("Response was: " + response);
        }
        else
        {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
        delay(500); // sleep for half of a second
    }
}

#if TESTING_MOTORS
#include "step.h"
#include "servo.h"
#include "brush.h"
StepMotor step = StepMotor("flower", 33, 25, 26, 27);
ServoMotor servo = ServoMotor("leaves", 2);
BrushMotor brush = BrushMotor("wheels", 12, 15, 13);
void setupMotors()
{
    step.setup();
    servo.setup();
    brush.setup();
}
void testMotors()
{
    step.test();
    servo.test();
    brush.test();
}
#endif