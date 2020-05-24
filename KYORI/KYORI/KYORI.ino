int get_data = 0;
void setup(){
  Serial.begin(9600);
}
void loop()                     
{
  get_data = analogRead(0);
  Serial.println(get_data);
  delay(200);
}
