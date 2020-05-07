void setup()
{

}

void loop()
{
   analogWrite(3, 50);
   delay(1000);
   analogWrite(3, 0);
   delay(1000);
}
