int prevt = 0;
int t = 0;
int threshold = 5;

void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
}

void loop()
{ 
  t = 0;
  digitalWrite(8, HIGH);
  while (digitalRead(9)!=HIGH) t++;
  digitalWrite(8, LOW);  
  delay(1);
  if( t > threshold ){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }  
}
