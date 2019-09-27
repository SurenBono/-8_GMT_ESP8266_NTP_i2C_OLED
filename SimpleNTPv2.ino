//Source https://forum.arduino.cc/index.php?topic=452680.0 developed by Sroto&Gargees™ 2019 
// I2C OLED SIMPLE 12-H NTP TIME FOR GMT/UTC +8

#include "time.h"
#include <ESP8266WiFi.h>  
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET     2 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid     = "************";                       // your wifi SSID (AP name)
const char* password = "************";                       // your wifi password

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 28800;       //Malaysian,Singapore GMT = +8 UTC * (60*60) , GREENWICH = 0 UTC * (60*60) = 0
const int   daylightOffset_sec = 0;

/*
  %a Abbreviated weekday name
  %A Full weekday name
  %b Abbreviated month name
  %B Full month name
  %c Date and time representation for your locale
  %d Day of month as a decimal number (01-31)
  %H Hour in 24-hour format (00-23)
  %I Hour in 12-hour format (01-12)
  %j Day of year as decimal number (001-366)
  %m Month as decimal number (01-12)
  %M Minute as decimal number (00-59)
  %p Current locale's A.M./P.M. indicator for 12-hour clock
  %S Second as decimal number (00-59)
  %U Week of year as decimal number,  Sunday as first day of week (00-51)
  %w Weekday as decimal number (0-6; Sunday is 0)
  %W Week of year as decimal number, Monday as first day of week (00-51)
  %x Date representation for current locale
  %X Time representation for current locale
  %y Year without century, as decimal number (00-99)
  %Y Year with century, as decimal number
  %z %Z Time-zone name or abbreviation, (no characters if time zone is unknown)
  %% Percent sign
  You can include text literals (such as spaces and colons) to make a neater display or for padding between adjoining columns.
  You can suppress the display of leading zeroes  by using the "#" character  (%#d, %#H, %#I, %#j, %#m, %#M, %#S, %#U, %#w, %#W, %#y, %#Y)
*/
char buffer[80];

void printLocalTime()
{
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80," %A\n%I:%M:%S%p\n %d-%m-%y",timeinfo);
  Serial.println(buffer);
  
}

void setup()
{
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);                                        //start the OLED @ Hex addy 0x3C
  display.display();                                                                //show the Adafruit Logo
  delay(2000);                                                                      //for 2 seconds
  display.clearDisplay();        
  Serial.begin(115200);
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
 
  unsigned timeout = 5000;
  unsigned start = millis();
  while (!time(nullptr))
  {
    Serial.print(".");
    delay(1000);
  }
  delay(1000);
}

void loop()
{
  printLocalTime();
  display.clearDisplay();
  display.setTextSize(2);                                       //set  text size
  display.setTextColor(WHITE);                                  //set text color to WHITE
  display.setCursor(0,0); 
  display.print(buffer); 
  display.display();  
  delay(1000);
}
