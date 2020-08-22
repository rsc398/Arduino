#include <LiquidCrystal.h>
LiquidCrystal Lcd1(12, 11, 7, 6, 5, 4);
LiquidCrystal Lcd2(14, 15, 18, 19, 20, 21);
float VoltageToTor(float v){
  float calib=0.2;
  float p = pow(10, 1.667 * (v-calib) * 3 - 11.46);
  return p;
}
int floatToExpo(float *p){
  int cnt = 0;
  if(*p > 10){
    while(1){
      if(*p < 10){
        break;
      }
      *p /= 10;
      cnt++;
    }
  } else if(*p < 1) {
    while(1){
      if(*p > 1){
        break;
      }
      *p *= 10;
      cnt--;
    }
  }
  return cnt;
}
void setup() {
  Lcd1.begin(2, 12);
  Lcd2.begin(14, 21);
}
void loop() {
  analogReadResolution(12);
  float v1, v2, v3, v4;
  float p1, p2, p3, p4;
  v1 = analogRead(A1) * 3.3 / 4096;
  v2 = analogRead(A2) * 3.3 / 4096;
  v3 = analogRead(A3) * 3.3 / 4096;
  v4 = analogRead(A4) * 3.3 / 4096;
  p1 = VoltageToTor(v1);
  p2 = VoltageToTor(v2);
  p3 = VoltageToTor(v3);
  p4 = VoltageToTor(v4);
  int cnt1 = floatToExpo(&p1);
  Lcd2.print("ch1 : ");
  Lcd2.print(p1, 2);
  Lcd2.print("e");
  if(cnt1>0){
    Lcd2.print("+");
  }
  Lcd2.print(cnt1, DEC);
  Lcd2.setCursor(0, 1);
  int cnt2 = floatToExpo(&p2);
  Lcd2.print("ch2 : ");
  Lcd2.print(p2, 2);
  Lcd2.print("e");
  if(cnt2>0){
    Lcd2.print("+");
  }
  Lcd2.print(cnt2, DEC);
  int cnt3 = floatToExpo(&p3);
  Lcd1.print("ch3 : ");
  Lcd1.print(p3, 2);
  Lcd1.print("e");
  if(cnt3>0){
    Lcd1.print("+");
  }
  Lcd1.print(cnt3, DEC);
  Lcd1.setCursor(0, 1);
  int cnt4 = floatToExpo(&p4);
  Lcd1.print("ch4 : ");
  Lcd1.print(p4, 2);
  Lcd1.print("e");
  if(cnt4>0){
    Lcd1.print("+");
  }
  Lcd1.print(cnt4, DEC);
  delay(500);
  Lcd1.clear();
  Lcd2.clear();
}
