#define SSID       "Itead_1(Public)"
#define PASSWORD   "27955416"
#include "uartWIFI.h"
#include <SoftwareSerial.h>
WIFI wifi;
void setup()
{
  wifi.begin();
  bool b = wifi.Initialize(STA, SSID, PASSWORD);
  if(!b)
  {
    DebugSerial.println("Init error");
  }
  DebugSerial.print("Connecting...");
  String wifistring  = wifi.showJAP();
  while(wifistring == "") {
    delay(200);
    wifistring = wifi.showJAP();
  }
  String ipstring = wifi.showIP();
  while(ipstring == "") {
    delay(200);
    ipstring = wifi.showIP();
  }
  DebugSerial.println(wifistring);
  DebugSerial.print("IP Address:");
  DebugSerial.println(ipstring);
}
void loop()
{
}
