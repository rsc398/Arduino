int val=0;
void setup() {
  Serial.begin(9800);
}
void loop() {
  val=analogRead(0);
  Serial.println(val/4);
  delay(100);
}
