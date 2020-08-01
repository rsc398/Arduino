void setup() {
  for(int i=0;i<=6;i++){
    pinMode(i,OUTPUT);
  }
}
void loop() {
  for(int i=1;i<=6;i++){
    tone(0,200,30);
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }
}
