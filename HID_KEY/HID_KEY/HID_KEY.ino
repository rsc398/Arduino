#include "Keyboard.h"

#define Button5 9

void setup() {
  Keyboard.begin();
  pinMode(Button5, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(Button5) == LOW){
    Keyboard.print("Arduino operating time ");
    Keyboard.write(','); //
    Keyboard.print(millis());
    Keyboard.write('\n');
    delay(100);

    while(digitalRead(Button5) == LOW);
  }

  delay(100);
}
