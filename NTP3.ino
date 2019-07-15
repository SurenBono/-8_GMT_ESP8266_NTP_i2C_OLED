#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET     2 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char *ssid     = "Arduino Wifi";
const char *password = "xxxxxxxx";

const long utcOffsetInSeconds = 28800;
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
char daysOfTheWeek[7][12] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);                                        //start the OLED @ Hex addy 0x3C
  display.display();                                                                //show the Adafruit Logo
  delay(2000);                                                                      //for 2 seconds
  display.clearDisplay();        
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
    display.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();
  display.clearDisplay();                                                           //clear display @ beginning of each loop
  display.setTextSize(2);                                                           //set smallest text size
  display.setTextColor(WHITE);                                                      //set text color to WHITE
  display.setCursor(50,5);                                                           //cursor to upper left
  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  display.print(daysOfTheWeek[timeClient.getDay()]);
  display.display();
  //display.startscrollleft(0x00, 0x0F);
  display.setCursor(20,35);  
  //Serial.print(", ");
  //display.print(", ");
  display.display(); 
  Serial.print(timeClient.getHours());
  display.print(timeClient.getHours());
  display.display(); 
  Serial.print(":");
  display.print(":");
  display.display(); 
  Serial.print(timeClient.getMinutes());
  display.print(timeClient.getMinutes());
  display.display(); 
  Serial.print(":");
  display.print(":");
  display.display(); 
  Serial.println(timeClient.getSeconds());
  display.print(timeClient.getSeconds());
  display.display(); 
  //Serial.println(timeClient.getFormattedTime());

  delay(1000);
}
