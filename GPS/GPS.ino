#include <SoftwareSerial.h>
 
SoftwareSerial GpsSerial(10, 11); // RX, TX
void setup() {
// Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
  }
  // set the data rate for the SoftwareSerial port
  GpsSerial.begin(9600);
  GpsSerial.println("GPS SIGNAL");
}
 
void loop() { // run over and over
  if (GpsSerial.available()) {
    Serial.write(GpsSerial.read());
  }
  if (Serial.available()) {
    GpsSerial.write(Serial.read());
  }
}
