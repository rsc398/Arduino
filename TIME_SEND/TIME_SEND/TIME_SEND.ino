void setup() { 
    Serial.begin(9600); 
    t1 = micros(); 
    val = analogRead(pin); 
    t2 = micros(); 
    Serial.print(t2-t1); 
} 
