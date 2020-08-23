const int lazer = 5;
const int led = 7;
 
void setup() {
  Serial.begin(9600);
  pinMode(lazer, OUTPUT);
  pinMode(led, OUTPUT);
}
 
void loop() {
  digitalWrite(lazer, HIGH);
  int val = analogRead(0);
  Serial.println(val);
  if(val >= 100){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);  
  }
}
