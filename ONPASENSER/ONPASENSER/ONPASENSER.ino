void setup() {
  Serial.begin(9600);
}
void loop() {
  int value = analogRead(A0);
  float V_out = (float)value * 5 / 1024;
  float distance = (V_out - 0.55)/0.033;
  float distance2 = 55 - distance;
  Serial.print(distance2);
  Serial.println("[cm]");
}
