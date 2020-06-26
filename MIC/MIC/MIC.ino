#define BAUD 57600
#define PIN 0
int d;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN, INPUT);
  Serial.begin(BAUD);
}

void loop() {
  // put your main code here, to run repeatedly:
  d = analogRead(PIN);
  Serial.write(d>>2);
  //delay(100);
}
