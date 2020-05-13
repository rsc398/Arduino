#include <TinyGPS++.h>
#include <SoftwareSerial.h>
 
TinyGPSPlus gps;
SoftwareSerial mySerial(10, 11);
void setup() {
Serial.begin(9600);
  while (!Serial) {
  ;
  } 
  Serial.println("StartUp");
  gpsSerial.begin(9600);
}
void loop() {
  while (mySerial.available() > 0){
  char data = mySerial.read();
  gps.encode(data);
    if (gps.location.isUpdated()){
      Serial.print("IDO="); Serial.print(gps.location.lat(), 6);
      Serial.print("KEIDO="); Serial.print(gps.location.lng(), 6);
      Serial.print("KOUDO="); Serial.println(gps.altitude.meters());
    }
  }
}
