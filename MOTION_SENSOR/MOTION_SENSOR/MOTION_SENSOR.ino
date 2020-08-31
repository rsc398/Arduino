#define SENSOR 8

void setup() 
{
  // put your setup code here, to run once:
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(digitalRead(SENSOR))
  {
    Serial.println("High");
  }
  else
  {
    Serial.println("Low");
  }
}
