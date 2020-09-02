#include <SPI.h>
#include <Ethernet.h>
byte mac_address[] = {
  0x90, 0xA2, 0xDa, 0x0D, 0xD2, 0xEF
};
 
void setup() {
 // put your setup code here, to run once:
  Serial.begin(9600);
  if (Ethernet.begin(mac_address) > 0) {
    Serial.print("IP Address:         ");
    Serial.println(Ethernet.localIP());
    Serial.print("Subnet Mask:        ");
    Serial.println(Ethernet.subnetMask());
    Serial.print("Gateway IP Address: "); 
    Serial.println(Ethernet.gatewayIP());
    Serial.print("DNS Server Address: "); 
    Serial.println(Ethernet.dnsServerIP());
  }
}
 
void loop() {
  // put your main code here, to run repeatedly: 
}
