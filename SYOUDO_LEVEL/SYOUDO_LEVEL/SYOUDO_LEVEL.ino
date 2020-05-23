int get_a0 = 0;
void setup(){
  Serial.begin(9600);
}

void loop()                     
{
  get_a0 = analogRead(0);
  Serial.println(get_a0);
  delay(200);
}
