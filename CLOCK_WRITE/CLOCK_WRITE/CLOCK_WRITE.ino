#include <Servo.h>
#include <Wire.h>
#include <DS3231.h>
 
DS3231 clock;
RTCDateTime dt;
Servo myservo1, myservo2, myservo3;
float th1=90.0,th2=90.0,th3=90.0;
float phi,ld,l;  
 
float L1=92.0,L2=137.0,L3=190.0;
 
int x = -100,y = 165,z = 225;
float rad = 0.0;
float radlong = 1.4;
 
char c;
int shortHand = 0, longHand = 0, longHandOld = 0;
 
void setup() {
  Serial.begin(9600);
  myservo1.attach(6, 500, 2420);  //MG995
  myservo2.attach(9, 820, 2140); //DS3115
  myservo3.attach(10, 820, 2140); //DS3115
  ik(x, y, z);
  clock.begin();
 
  // Set sketch compiling time
  //clock.setDateTime(__DATE__, __TIME__);
}
 
void loop() {
  dt = clock.getDateTime();
  shortHand = dt.hour;
  if(shortHand >= 12){
    shortHand -= 12;
  }
  
  longHand = dt.minute;
 
  if(longHand != longHandOld){
    Serial.print(shortHand);
    Serial.print(":");
    Serial.println(longHand);
 
    erase();
    shand(shortHand, longHand);
    lhand(longHand);
    ini();
  }
  
 
  
  longHandOld = longHand;
  delay(10000);
}
 
void ik(float x,float y,float z){
  th1=atan2(y,x);
  l=sqrt(x*x + y*y);
  ld=sqrt(l*l + (z-L1)*(z-L1));
  phi=atan2((z-L1),l);
  th2=phi + acos((ld*ld+L2*L2-L3*L3)/(2.0*ld*L2));
  th3=asin((ld*ld-L2*L2-L3*L3)/(2.0*L2*L3)) + M_PI /2.0;
  th1=th1*180.0/M_PI ;
  th2=th2*180.0/M_PI ;
  th3=th3*180.0/M_PI ;
  set_servo();
}
 
void set_servo(){
    myservo1.write(th1);
    myservo2.write(th2);
    myservo3.write(th3);
}
 
 
//短針描画
void shand(int h, int m){
  ik(0, 140, 60);
  delay(100);
 
  if(h <= 3){
    z = 1;
    rad = 25.0;
  }else if(h <= 5){
    z = 6;
    rad = 28.0;
  }else if(h <= 7){
    z = 6;
    rad = 35.0;
  }else if(h < 9){
    z = 6;
    rad = 30.0;
  }else if(h >= 9){
    z = 1;
    rad = 25.0;
  }
  
  for(int i = 60; i >= z; i-=1){
    ik(0, 140, i);
    delay(10);
  }
 
  float th = 2.0 * M_PI / 12.0 * h + 2.0 * M_PI / (12.0 * 60.0) * m; 
  
  for(int i = 0; i <= 60; i+=1){
    x = rad/60.0*sin(th)*i;
    y = 140+(rad/60.0*cos(th))*i;
    ik(x, y, z);
    delay(30);
  }
 
  for(int i = z; i <= 60; i+=1){
    ik(x, y, i);
    delay(6);
  }
  z = 60;
  ik(x, y, z);
  delay(70);
}
void lhand(int m){
  ik(0, 140, 60);
  delay(100);
 
  if(m <= 15){
    z = 1;
    rad = 25.0 * radlong;
  }else if(m <= 25){
    z = 6;
    rad = 28.0 * radlong;
  }else if(m <= 35){
    z = 6;
    rad = 35.0 * radlong;
  }else if(m < 45){
    z = 6;
    rad = 30.0 * radlong;
  }else if(m >= 45){
    z = 1;
    rad = 25.0 * radlong;
  }
  
  for(int i = 60; i >= z; i-=1){
    ik(0, 140, i);
    delay(10);
  }
 
  float th = 2.0 * M_PI / 60.0 * m; 
  
  for(int i = 0; i <= 60; i+=1){
    x = rad/60.0*sin(th)*i;
    y = 140+(rad/60.0*cos(th))*i;
    ik(x, y, z);
    delay(30);
  }
 
  for(int i = z; i <= 60; i+=1){
    ik(x, y, i);
    delay(6);
  }
  z = 60;
  ik(x, y, z);
  delay(70);
}
 
 
//初期姿勢
void ini(){ 
  x = -100;
  y = 165;
  z = 225;
  ik(x, y, z);
  delay(70);
}
 
 
//消去
void erase(){ 
  ik(x, y, 60);
  delay(500);
  ik(x, 225, 60);
  delay(500);
  ik(80, 225, 60);
  delay(20);
  ik(80, 225, 60);
  delay(100);
  ik(80, 225, -5);
  for(int i = 225; i >= 200; i-=2){
    ik(80, i, -5);
    delay(50);
  }
  ik(80, 215, 40);
  delay(200);
  for(int i = 215; i >= 120; i-=2){
    ik(75, i, -5);
    delay(40);
  }
  ik(70, 140, 40);
  delay(200);
  for(int i = 140; i >= 90; i-=2){
    ik(70, i, 0);
    delay(40);
  }
  ik(70, 90, 40);
  delay(100);
  ik(75, 85, 40);
  delay(100);
  for(int i = 85; i <= 155; i+=2){
    ik(75, i, 0);
    delay(20);
  }
  ik(75, 135, -5);
  delay(100);
  for(int i = 135; i <= 210; i+=2){
    ik(75, i, -5);
    delay(20);
  }
  ik(70, 180, 60);
  delay(100);
  x = 70;
  y = 180;
  z = 60;
  x = 0;
}
