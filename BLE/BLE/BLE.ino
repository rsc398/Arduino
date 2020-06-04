const int LED=13;
int rsvData = 0;
int sensorVal = 0;

void setup()
{
　 pinMode(LED, OUTPUT);
　 Serial.begin(9600);
}

void loop()
{
　 if(Serial.available() > 0){
　 　rsvData = Serial.read();
　 　if(rsvData == 1){
　　 　digitalWrite(LED, HIGH);
　 　}else if(rsvData == 0){
　　 　digitalWrite(LED, LOW);
　 　}
　}
　 sensorVal = analogRead(0);
　 sensorVal = sensorVal>>2; //10bit->8bit値
　 Serial.write(sensorVal);
　　 delay(100);

}
