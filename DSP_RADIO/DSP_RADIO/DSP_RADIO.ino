#include <Wire.h>
void setup()
{
delay(100);
Wire.begin();
Wire.beginTransmission(0X63); //slave ad
  Wire.write(0x01); //  Power up
  Wire.write(0b00010000);
  Wire.write(0b00000101);
Wire.endTransmission();
delay(200);
Wire.beginTransmission(0X63); //slave ad
  Wire.write(0x20); //  FM Freq
  Wire.write(0x00); 
  Wire.write(0x1F); // 8000 =1F40
  Wire.write(0x40); // 8000 =1F40
  //Wire.write(0x20); // 8250
  //Wire.write(0x3A); // 8250
  Wire.write(0x00);
Wire.endTransmission();
}

void loop() {
  // put your main code here, to run repeatedly:
}
