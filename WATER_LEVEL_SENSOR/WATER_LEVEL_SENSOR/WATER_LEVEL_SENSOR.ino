int watorLevel = 0;
int watorLevelPin = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  watorLevel = analogRead(watorLevelPin);

  if(watorLevel <= 100) {
    Serial.println("Wator Level: Empty(" + String(watorLevel) + ")");
  }
  else if(watorLevel > 100  && watorLevel <= 200) {
    Serial.println("Wator Level: Low(" + String(watorLevel) + ")");
  }
  else if(watorLevel > 200 && watorLevel <= 260) {
    Serial.println("Wator Level: Medium(" + String(watorLevel) + ")");
  }
  else if(watorLevel > 260) {
    Serial.println("Wator Level: High(" + String(watorLevel) + ")");
  }
  delay(1000);
}
