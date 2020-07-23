double n ;
unsigned long time;
 
void setup() {
    Serial.begin(9600);
    Serial.println(pow(2,16));
    n = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2.0*2.0; 
    Serial.println(n);
}
 
void loop() {
   time = micros();
   Serial.println(time);
   Serial.print("pow 2^16 ");
   for (int i = 0; i<10; i++){
        double n = pow(2,16);
   }
   Serial.println(micros()- time);
   time = micros();
   Serial.println(micros());
   Serial.print("1/ (pow 2^16) ");
   for (int i = 0; i<10; i++){
        double n = 1 / pow(2,16);
   }
   Serial.println(micros()- time);
   time = micros();
   Serial.println(micros());
   Serial.print("2^16 ");
   for (int i = 0; i<10; i++){
        double n = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2.0*2.0;
   }
   Serial.println(micros()- time);
   time = micros();
   Serial.println(micros());
   Serial.print("1/2^16 ");
   for (int i = 0; i<10; i++){
        double n = 1/(2*2*2*2*2*2*2*2*2*2*2*2*2*2*2.0*2.0);
   }
   Serial.println(micros()- time);
   Serial.println("----------------");
   delay(5000);
}
