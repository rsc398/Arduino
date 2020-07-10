void setup()
{
  Serial.begin(115200UL);
}

void loop()
{
  double value = analogRead(A0);
  value *= 5;
  value /= 1024;
  value /= 30;
  value *= 130;
  Serial.println(value);
  delay(1000);
}
