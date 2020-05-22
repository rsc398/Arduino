void setup(){
  Serial.begin(9600) ; 
}
void loop(){
  int valX = analogRead(2); 
  int valY = analogRead(1);
  int valZ = analogRead(0);
  Serial.print("X("); 
  Serial.print(valX); 
  Serial.print("),  Y("); 
  Serial.print(valY); 
  Serial.print("),  Z("); 
  Serial.print(valZ);  
  Serial.println(")"); 
  delay(300) ;  
}
