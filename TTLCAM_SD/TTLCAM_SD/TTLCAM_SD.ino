#include <Adafruit_VC0706.h>
#include <SoftwareSerial.h>
#include <SD.h>

const int PIN_LED = 4;
SoftwareSerial cameraconnection = SoftwareSerial(2,3);
Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);
boolean camera_found = false;
int file_count = 1;
char fname[16];
void setup() {
  SD.begin();
  if( cam.begin() ){
    camera_found = true;
  }
  else{
    return;
  }
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}
void loop() {
  if( !camera_found) {
    return;
  }
  digitalWrite(PIN_LED, HIGH);
  cam.setImageSize(VC0706_640x480);
  if( cam.takePicture() ){
    set_filename();
    File file = SD.open( 
      fname, 
      FILE_WRITE | O_TRUNC );
    if( file ){
      uint16_t len = cam.frameLength();
      while (len > 0) {
        uint8_t *buf;
        uint8_t bytesToRead = min(64, len);
        buf = cam.readPicture(bytesToRead);      
        file.write( buf, bytesToRead );
        len -= bytesToRead;
      }
      file.close();
    }
  }
  cam.reset();
  digitalWrite(PIN_LED, LOW);
  delay(5000);
}
void set_filename(){
  sprintf(fname, "IMG%04d.JPG", file_count++);
  if( file_count > 9999 ){
    file_count = 1; // Overwrite
  }
}
