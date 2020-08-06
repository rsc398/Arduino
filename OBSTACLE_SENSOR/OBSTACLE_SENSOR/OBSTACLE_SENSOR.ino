int LED = 13;
int isObstaclePin = 2;
int isObstacle = HIGH;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);  
}

void loop() {
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    Serial.println("");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("DELETE");
    digitalWrite(LED, LOW);
  }
  delay(200);
}
