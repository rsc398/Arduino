#include <TimerOne.h>

#define INPUT_PIN 3
#define OUTPUT_PIN_1 6
#define OUTPUT_PIN_2 5
float V1, Vo;
float Vi;
void serOut(){
  Serial.print(Vi, 4);
  Serial.print(',');
  Serial.print(V1, 4);
  Serial.print(',');
  Serial.println(Vo, 4);
}

float convDac(float y){
  return (y - 511) / 1023.0 * 5.0;
}
int convPwm(float u){
  int ret = 255/5*u + 128;

  if (ret > 255)
    ret = 255;
  else if (ret < 0)
    ret = 0;

  return ret;
}

void control() {
  V1 = convDac(analogRead(OUTPUT_PIN_1));
  Vo = convDac(analogRead(OUTPUT_PIN_2));

  analogWrite(INPUT_PIN, convPwm(Vi));
  serOut();
}

void setup() {
  Serial.begin(/* Baud */);

  Timer1.initialize(/* */);
  Timer1.attachInterrupt(control);

  Timer1.start();
}

void loop() {
}
