#include < Stepper.h >
#include < MsTimer2.h >
#define STEPS 100

Stepper stepper(STEPS, 8, 9, 10, 11);
int goff=0;
long angle=0;

void gyro() {
angle=angle+(analogRead(0)-goff);
}

void setup()
{
if (goff==0) goff = analogRead(0);
MsTimer2::set(5, gyro); // 5ms period
MsTimer2::start();
}

void loop()
{
stepper.setSpeed(80+abs(angle)*1.5);
stepper.step(angle*0.1);
}
