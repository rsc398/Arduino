#include <Servo.h>

Servo servoline;

void setup()
{
    // put your setup code here, to run once:
    servoline.attach(3);
}

void loop()
{
  // put your main code here, to run repeatedly:
    servoline.write(35);
    delay(1000);
    servoline.write(70);
    delay(1000);
}
