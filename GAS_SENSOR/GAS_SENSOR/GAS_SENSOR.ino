#include 
#include "pitches.h"
#define　　 PIN_LED　　　　 13
#define　　 PIN_BUZZER　　　2
#define　　 PIN_CO　　　　　0
#define　　 PIN_CH4　　　　 1
#define　　 PIN_CO_VSS　　　11
#define　　 PIN_CO_PWM　　　75
#define CO_Ro　　　　　 2
#define CH4_Ro　　　　　10
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
byte trig=0;
byte buzzer=0x00;
unsigned long time;
unsigned long time_next;
boolean time_ovf = false;
int val;
float ch4,co;
void setup(){
　　pinMode(PIN_CO_VSS,OUTPUT);
　　digitalWrite(PIN_CO_VSS,LOW);
　　lcd.begin(16, 2);
　　lcd.clear();
　　lcd.print("Gas Sensors");
　　time_next = millis() + 1000;
}
void loop(){
　　time= millis();
　　digitalWrite(PIN_LED,HIGH);
　　if( time_ovf && time < 1000 ) time_ovf=false;
　　if( time > time_next && !time_ovf){
　　　　switch(trig){
　　　　　　case 0:
　　　　　　　　val = analogRead(PIN_CO);
　　　　　　　　co = pow(10,2.0-1.7*log10(10*(1023/(float)val-1)/CO_Ro));
　　　　　　　　digitalWrite(PIN_CO_VSS,HIGH);
　　　　　　　　time_next += 60000;
　　　　　　　　if( time_next < 60000 ) time_ovf = true;
　　　　　　　　trig++;
　　　　　　　　break;
　　　　　　case 2:
　　　　　　　　analogWrite(PIN_CO_VSS,PIN_CO_PWM);
　　　　　　　　time_next += 90000;
　　　　　　　　if( time_next < 90000 ) time_ovf = true;
　　　　　　　　trig=0;
　　　　　　　　break;
　　　　}
　　}
　　val = analogRead(PIN_CH4);
　　ch4 = pow(10,3.0-2.7*log10(22*(1023/(float)val-1)/CH4_Ro));
　　if(trig==1){
　　　　trig++;
　　　　buzzer=0x00;
　　}
　　lcd.clear();
　　lcd.print("CO =");
　　if( co < 10 ) lcd.print( co , 2);
　　else lcd.print( co , 0);
　　lcd.print("ppm");
　　lcd.setCursor(12, 0);
　　if( trig == 0 ) lcd.print("COOLING");
　　else lcd.print("HEATING");
　　lcd.setCursor(0, 1);
　　lcd.print("CH4=");
　　if( ch4 < 10 ) lcd.print( ch4 , 2);
　　else lcd.print( ch4 , 0);
　　lcd.print("ppm");
　　lcd.setCursor(12, 1);
　　lcd.print( (time/1000)%3600 );
　　digitalWrite(PIN_LED,LOW);
　　if(buzzer){
　　　　if(buzzer&0x01){
　　　　　　if(buzzer&0x10) tone(PIN_BUZZER,NOTE_B7,100);
　　　　　　else　　　　　　tone(PIN_BUZZER,NOTE_B7,300);
　　　　　　buzzer++;
　　　　}else{
　　　　　　if(buzzer&0x10) tone(PIN_BUZZER,NOTE_G7,100);
　　　　　　else　　　　　　tone(PIN_BUZZER,NOTE_G7,300);
　　　　　　buzzer--;
　　　　}
　　}else if(co >　100) buzzer=0x01;
　　else if(co　>　 50) tone(PIN_BUZZER,NOTE_A7,300);
　　else if(ch4 > 1000) buzzer=0x11;
　　else if(ch4 >　100) tone(PIN_BUZZER,NOTE_A7,100);
　　delay(500);
}
