#include <AccelStepper.h>
 
AccelStepper stepper(1, 9, 8); // pin 9 = step, pin 8 = direction
void setup()
{  
  stepper.setMaxSpeed(500);
  stepper.setSpeed(500);
} 
void loop()
{
    stepper.runSpeed();
}
