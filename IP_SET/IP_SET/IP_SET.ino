#include <SPI.h>
#include <Ethernet.h>
byte mac_address[] = {
  0x90, 0xA2, 0xDa, 0x0D, 0xD2, 0xEF
};
byte IP_address[] = {
  192, 168, 11, 200
};
byte dns_address[] = {
  192, 168, 11, 1
};
byte gateway_address[] = {
  192, 168, 11, 1
};
byte subnet[] = {
  255, 255, 255, 0
};
 
void setup() {
 // put your setup code here, to run once:
  Serial.begin(9600);
  Ethernet.begin(mac_address, IP_address, dns_address, gateway_address, subnet);
  Serial.print("IP Address:         ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet Mask:        ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Gateway IP Address: "); 
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS Server Address: "); 
  Serial.println(Ethernet.dnsServerIP());
}
 
void loop() {
  // put your main code here, to run repeatedly: 
}
