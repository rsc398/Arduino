const int repeat = 10000;
void measure(int pin) {
  long begin, end;
  volatile int val;
  Serial.print("Pin No.: ");
  Serial.println(pin);
  pinMode(pin, INPUT);
  delay(1000);
  begin = micros();
  for(int i = 0; i < repeat; i++) {
    val = digitalRead(pin);
  }
  end = micros();
  Serial.print("  digitalRead:    ");
  Serial.println((end - begin) / (float)repeat);
  pinMode(pin, OUTPUT);
  delay(1000);
  begin = micros();
  for(int i = 0; i < repeat; i++) {
    digitalWrite(pin, HIGH);
  }
  end = micros();
  Serial.print("  digitalWrite:   ");
  Serial.println((end - begin) / (float)repeat);
  if ((pin >= A0) && (pin <= A5)) {
    val = analogRead(pin);
    begin = micros();
    for(int i = 0; i < repeat; i++) {
      val = analogRead(pin);
    }
    end = micros();
    Serial.print("  analogRead:   ");
    Serial.println((end - begin) / (float)repeat); 
  }
  Serial.println();
}
void setup () {
  int pin;
  Serial.begin(9600);
  for(pin = 0; pin < 20; pin++) {
    measure(pin);
  }
}
void loop () {
}
