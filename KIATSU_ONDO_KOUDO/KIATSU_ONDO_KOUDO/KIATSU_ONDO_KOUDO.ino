#include <Wire.h>

uint8_t DEVICE_ADDRESS = 0x5C;
bool WHO_AM_I = false;
void setup() {
  Serial.begin(9600); 
  Wire.begin();       
  Wire.beginTransmission(DEVICE_ADDRESS);
    Wire.write(0x0F);
  Wire.endTransmission();
  Wire.requestFrom(DEVICE_ADDRESS, 1);
 
  while(Wire.available() == 0) {}
  uint8_t test = Wire.read(); 
     
  if(0xBD != test){
    Serial.println("INPUTERR");
    return;
  }
  WHO_AM_I = true;
  Wire.beginTransmission(DEVICE_ADDRESS);      
    Wire.write(0x20);  
    Wire.write(0x90);
  Wire.endTransmission();    
}
void loop() {  
  if(!WHO_AM_I) return;
  int i; uint8_t RegTbl[5];   
  for (i=0; i< 5; i++){
    Wire.beginTransmission(DEVICE_ADDRESS);
      Wire.write(0x28 + i );
    Wire.endTransmission();
    Wire.requestFrom(DEVICE_ADDRESS, 1);
    while(Wire.available() == 0) {}
    RegTbl[i] = Wire.read();     
  }
  uint16_t lo = RegTbl[1] << 8 | RegTbl[0];
  uint32_t hi = RegTbl[2] * 65536;
  float P = (hi +  lo) / 4096.0;
  
  Serial.print("KIATSU：");      
  Serial.print(P);
  Serial.print("hPa(mbar)");    
  int temperature = (RegTbl[4] << 8 |  RegTbl[3]);
  float T = 42.5 + (temperature / 480.0); 
  Serial.print(" ONDO：");      
  Serial.print(T);
  Serial.print("℃");   
  float H = ((pow(1013.25 / P, 1 / 5.257) - 1) * (T+ 273.15)) / 0.0065;
  Serial.print(" KOUDO：");    
  Serial.print(H);
  Serial.println("m");      
  delay(1000);
}  
