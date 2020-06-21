int ledPin = 3;
int analogPin = 0;
int val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);
  analogWrite(ledPin, val / 4);
  Serial.println(val/4);
  delay(100);
}
