void setup() {
  analogReference(INTERNAL);
  Serial.begin(115200);
}
void loop() {
  float V, R, T; 
  long x;
  x = 0;
  for (int n = 0; n < 10; n++) {
    x += analogRead(0);
  }
  V = x * 1.1 / 10230.0;
  R = thermistorR(V, 3.3, 75000.0);
  T = thermistorT(R, 3431.0, 10000.0, 25.0);
 
  Serial.print(V, 3);
  Serial.print(", "); Serial.print(R, 1);
  Serial.print(", "); Serial.println(T, 1);
  delay(500);
}
float thermistorR(float Vx, float V0, float Rs) {
  return Vx * Rs / (V0 - Vx);
}
float thermistorT(float R, float B, float R0, float T0) {
  return 1 / ((1.0 / B) * log(R / R0) + (1.0 / (T0 + 273.15))) - 273.15;
}
