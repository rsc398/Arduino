void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(0);
  
  Serial.write('H');
  Serial.write(highByte(value));
  Serial.write(lowByte(value));
}
