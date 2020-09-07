#include <WiFi.h>
#include "SO2002A_I2C.h"
 
const char *ssid = "your-ssid";
const char *password = "your-password";
 
SO2002A_I2C oled(0x3c);
 
void setup() {
  // put your setup code here, to run once:
  oled.begin(20, 2);
  oled.clear();
  delay(10);
 
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
 
  if (WiFi.begin(ssid, password) != WL_DISCONNECTED) {
    ESP.restart();
  }
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
 
  configTime(9 * 3600L, 0, "ntp.nict.jp", "time.google.com", "ntp.jst.mfeed.ad.jp");
}
 
void loop() {
  // put your main code here, to run repeatedly:
  struct tm timeInfo;
  char s[20];
 
  getLocalTime(&timeInfo);
  sprintf(s, " %04d/%02d/%02d %02d:%02d:%02d",
          timeInfo.tm_year + 1900, timeInfo.tm_mon + 1, timeInfo.tm_mday,
          timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_sec);
  oled.setCursor(0, 0);
  oled.print(s);
 
  delay(10);
}
