#include <SoftwareSerial.h>

const int PIN_TMP36 = 1;
SoftwareSerial bt = SoftwareSerial(2,3);
boolean bt_found = false;
void setup() {
  String s;
  Serial.begin(9600);
  bt.begin(38400);
  delay(3000);
  s = bt_sendCommand("AT");
  Serial.println("AT --> " + s);
  if( s == "OK" ){
    bt_found = true;
  }
  else{
    return;
  }   
}
void loop() {
  if(!bt_found){
    return;
  }
  String r = "";
  if(bt.available() == 0){
    return;
  }
  while(bt.available() > 0){
    char ch = bt.read();
    r += ch;
  }
  Serial.println("Command: " + r);
  process_command( r ); 
}
float get_temperature(){
  int i = analogRead( PIN_TMP36 ); 
  float f = i * 5.0 / 1023.0;
  return 100 * f - 50;
}
void process_command(String r){
  if( r == "GET:TEMP" ){
    float temp = get_temperature();
    String s = String(temp, 1);
    bt.print(s);
    bt.flush();
  }
  else{
    Serial.println("Unknown command.");
  } 
}
String bt_sendCommand(String cmd){
  String r = "";
  bt.print(cmd);
  bt.flush();
  
  Serial.println("Waiting [" + cmd + "]");
  while(bt.available() == 0){
    delay(300);
  }
  Serial.println("OK [" + cmd + "]");
  while(bt.available() > 0){
    char ch = bt.read();
    r += ch;
  }
  Serial.println("Response [" + r + "]");
  return r;
}
