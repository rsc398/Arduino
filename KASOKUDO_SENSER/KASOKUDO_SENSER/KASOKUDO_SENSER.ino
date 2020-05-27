void setup()
{
  Serial.begin(9600) ;
}
void loop()
{
  int i ;
  long x,y,z;
  x=y=z=0;
    for (i=0 ; i < 50 ; i++) {
      x = x + analogRead(A0) ;
      y = y + analogRead(A1) ;
      z = z + analogRead(A2) ;
    }
  x = x / 50 ;
  y = y / 50 ;
  z = z / 50 ;
  int rotateX = (x-194)/0.72;
  Serial.write('H');
  Serial.write(highByte(rotateX));
  Serial.write(lowByte(rotateX));
  delay(50) ;
}
