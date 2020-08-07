#include <Servo.h> 
 
#define SW 12
Servo servo1;
Servo servo2;
Servo servo3;
 
void setup() 
{ 
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  
  pinMode(SW,INPUT);
  digitalWrite(SW,HIGH);
} 
 
void loop() 
{ 
   if(digitalRead(SW)==LOW){
     servo1.write(90);
     servo2.write(90);
     servo3.write(90);
   }else{
     servo1.write(0);
     servo2.write(0);
     servo3.write(0);
   }   
}
