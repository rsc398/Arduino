#include <Wire.h>
 
long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;
 
long gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;
 
void setup() {
  Serial.begin(9600);
  Wire.begin();
  setupMPU6050();
}
void loop() {
  recordAccelRegisters();
  recordGyroRegisters();
  printData();
  delay(200);
}
void setupMPU6050() {
  Wire.beginTransmission(0b1101000);
  Wire.write(0x6B);
  Wire.write(0b00000000);
  Wire.endTransmission();
  Wire.beginTransmission(0b1101000);
  Wire.write(0x1B);
  Wire.write(0x00000000);
  Wire.endTransmission();
  Wire.beginTransmission(0b1101000);
  Wire.write(0x1C);
  Wire.write(0b00000000);
  Wire.endTransmission();
}
void recordAccelRegisters() {
  Wire.beginTransmission(0b1101000);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(0b1101000, 6);
  while (Wire.available() < 6);
  accelX = Wire.read() << 8 | Wire.read();
  accelY = Wire.read() << 8 | Wire.read();
  accelZ = Wire.read() << 8 | Wire.read();
  calculateAccelData();
}
void calculateAccelData() {
  gForceX = accelX / 16384.0;
  gForceY = accelY / 16384.0;
  gForceZ = accelZ / 16384.0;
}
void recordGyroRegisters() {
  Wire.beginTransmission(0b1101000);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0b1101000, 6);
  while (Wire.available() < 6);
  gyroX = Wire.read() << 8 | Wire.read();
  gyroY = Wire.read() << 8 | Wire.read();
  gyroZ = Wire.read() << 8 | Wire.read();
  calculateGyroData();
}
void calculateGyroData() {
  rotX = gyroX / 131.0;
  rotY = gyroY / 131.0;
  rotZ = gyroZ / 131.0;
}
void printData() {
  Serial.print("Gyro");
  Serial.print(" X=");
  Serial.print(rotX);
  Serial.print("deg/sec");
  Serial.print(" Y=");
  Serial.print(rotY);
  Serial.print("deg/sec");
  Serial.print(" Z=");
  Serial.print(rotZ);
  Serial.print("deg/sec");
  Serial.print("  Accel");
  Serial.print(" X=");
  Serial.print(gForceX);
  Serial.print('g');
  Serial.print(" Y=");
  Serial.print(gForceY);
  Serial.print('g');
  Serial.print(" Z=");
  Serial.print(gForceZ);
  Serial.println('g');
}
