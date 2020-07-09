int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if (sensorValue < 400) {
    Serial.println("");
  } else {
    Serial.println("");
  }
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(5000);  

}
