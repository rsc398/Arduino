int pin = 0;
void setup(){
  Serial.begin(9600);
}
void loop() {
  int val;
  val = analogRead(pin);
  Serial.println(val);
  delay(100);
}
