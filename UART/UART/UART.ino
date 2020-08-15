int data = 0;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.write("from Arduino\n");
    Serial.write(data);
    Serial.write("\n");
    Serial.flush();
  }
}
