#include <Wire.h>
#include <Servo.h>
#include "Kalman.h"

Kalman kalmanX;
Kalman kalmanY;

double accX, accY, accZ;
double gyroX, gyroY, gyroZ;

double gyroXangle, gyroYangle;
double kalAngleX, kalAngleY;

uint32_t timer;
uint8_t i2cData[14];

Servo myservo_x;
Servo myservo_y;

int val_x;
int val_y;

void setup() {
  myservo_x.attach(9);
  myservo_y.attach(10);

  Wire.begin();
  TWBR = ((F_CPU / 400000L) - 16) / 2;

  i2cData[0] = 7;
  i2cData[1] = 0x00;
  i2cData[2] = 0x00;
  i2cData[3] = 0x00;
  while (i2cWrite(0x19, i2cData, 4, false));
  while (i2cWrite(0x6B, 0x01, true));

  while (i2cRead(0x75, i2cData, 1));
  if (i2cData[0] != 0x68) {
    while (1);
  }

  delay(100);

  while (i2cRead(0x3B, i2cData, 6));
  accX = (i2cData[0] << 8) | i2cData[1];
  accY = (i2cData[2] << 8) | i2cData[3];
  accZ = (i2cData[4] << 8) | i2cData[5];

  double roll  = atan2(accY, accZ) * RAD_TO_DEG;
  double pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;

  kalmanX.setAngle(roll);
  kalmanY.setAngle(pitch);
  gyroXangle = roll;
  gyroYangle = pitch;

  timer = micros();
}

void loop() {
  while (i2cRead(0x3B, i2cData, 14));
  accX = ((i2cData[0] << 8) | i2cData[1]);
  accY = ((i2cData[2] << 8) | i2cData[3]);
  accZ = ((i2cData[4] << 8) | i2cData[5]);
  gyroX = (i2cData[8] << 8) | i2cData[9];
  gyroY = (i2cData[10] << 8) | i2cData[11];
  gyroZ = (i2cData[12] << 8) | i2cData[13];

  double dt = (double)(micros() - timer) / 1000000;
  timer = micros();

  double roll  = atan2(accY, accZ) * RAD_TO_DEG;
  double pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;

  double gyroXrate = gyroX / 131.0;
  double gyroYrate = gyroY / 131.0;

  if ((roll < -90 && kalAngleX > 90) || (roll > 90 && kalAngleX < -90)) {
    kalmanX.setAngle(roll);
    kalAngleX = roll;
    gyroXangle = roll;
  } else
    kalAngleX = kalmanX.getAngle(roll, gyroXrate, dt);

  if (abs(kalAngleX) > 90)
    gyroYrate = -gyroYrate;
  kalAngleY = kalmanY.getAngle(pitch, gyroYrate, dt);

  gyroXangle += gyroXrate * dt;
  gyroYangle += gyroYrate * dt;

  if (gyroXangle < -180 || gyroXangle > 180)
    gyroXangle = kalAngleX;
  if (gyroYangle < -180 || gyroYangle > 180)
    gyroYangle = kalAngleY;

  val_x = kalAngleX + 90;            
  val_x = map(val_x, 0, 180, 0, 180);
  myservo_x.write(val_x);            

  val_y = kalAngleY + 90;            
  val_y = map(val_y, 0, 180, 0, 180);
  myservo_y.write(180 - val_y);        

  delay(2);
}
