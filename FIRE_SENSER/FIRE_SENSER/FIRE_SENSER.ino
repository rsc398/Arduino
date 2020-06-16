int Led = 13;
int buttonpin = 3;
int analoog = A3;

int val;
float sensor;

void setup () {
  pinMode (Led, OUTPUT);
  pinMode (buttonpin, INPUT);
  pinMode (analoog, INPUT);
  Serial.begin(9600);
}
 
void loop () {
  sensor = analogRead(analoog);
  Serial.println(sensor);
 
  val = digitalRead (buttonpin);
    if (val == HIGH) {
    digitalWrite (Led, HIGH);
  } else {
    digitalWrite (Led, LOW);
  }
  delay(1000);
}
