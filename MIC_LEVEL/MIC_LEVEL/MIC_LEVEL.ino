void setup() {
Serial.begin(9600);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
}

void loop() {
sound = analogRead(0);
volts = (sound * 5.0/3.3) / 1024 ;
Serial.println(volts);
if (volts > 0.55) {
digitalWrite(led1, HIGH);
}
if (volts < 0.55) {
digitalWrite(led1, LOW);
}
if (volts > 0.65) {
digitalWrite(led2, HIGH);
}
if (volts < 0.65) {
digitalWrite(led2, LOW);
}
if (volts > 0.7) {
digitalWrite(led3, HIGH);
}
if (volts < 0.7) {
digitalWrite(led3, LOW);
}
if (volts > 0.8) {
digitalWrite(led4, HIGH);
}
if (volts < 0.8) {
digitalWrite(led4, LOW);
}
if (volts > 0.9) {
digitalWrite(led5, HIGH);
}
if (volts < 0.9) {
digitalWrite(led5, LOW);
}
}
