#include <SoftwareSerial.h>
SoftwareSerial CO21(4,5), CO22(6,7), CO23(8,9);

void setup() {
Serial.begin(38400);
}
void loop() {
  Serial.print("--CO21 > " + String(sub_co2(CO21)) + " ppm");
  Serial.print(", CO22 > " + String(sub_co2(CO22)) + " ppm");
  Serial.println(", CO23 > " + String(sub_co2(CO23)) + " ppm");
}

int sub_co2(SoftwareSerial CO2){
  int val=0;
  uint32_t tim=millis();
  String str;
  CO2.begin(38400);
  while(!CO2.available() && (millis()-tim)<3000);
  str=CO2.readStringUntil('\n');
  if(str.indexOf("ppm")) {
    str=str.substring(0,str.length()-4);
    str.trim();
    val = str.toInt();
  }
  while(millis() -tim<5000);
  return val;
}
