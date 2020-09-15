#include <LiquidCrystal.h>
const int rs = 4, en = 5, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte statusLed    = 13;
byte sensorInterrupt = 0;
byte sensorPin       = 3;
float calibrationFactor = 7.5;
volatile byte pulseCount;  
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
unsigned long oldTime;
void setup()
{
  pinMode(statusLed, OUTPUT);
  digitalWrite(statusLed, HIGH); 
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
  oldTime           = 0;
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
}
void loop()
{
   if((millis() - oldTime) > 1000)
  {   
    detachInterrupt(sensorInterrupt);
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    oldTime = millis();
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;
    unsigned int frac;
  lcd.begin(16, 2);
  lcd.print(" Flow Rate");
  lcd.setCursor(1, 1);
  lcd.print(flowRate);
  lcd.setCursor(6, 1);
  lcd.print("L/Min");
    pulseCount = 0;
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
}
void pulseCounter()
{
  pulseCount++;
}
