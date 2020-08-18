long hex_pre;
long hex_aft;
byte trash;
long temper;
 
void setup(){
  Serial.begin(9600);
}
 
void loop(){
  //
  if(Serial.available() > 20){
    if(Serial.read() == 0x7E){
      delay(10);
      for( int i = 1; i < 21; i++){
        trash = Serial.read();
      }
      hex_pre = Serial.read();
      hex_aft = Serial.read();
      Serial.print(String(hex_pre,HEX) +" " + String(hex_aft,HEX) );
      temper = (((hex_pre * 256 + hex_aft) * 1200 / 1024) - 600) / 10;
      Serial.print("-> "+ String(temper));
      Serial.print("\n");
    }
  }
}
