int sec = 0;
unsigned char tv[1000];
int count=0;
void setup() {
  Serial.begin(9600) ;
}
void loop() {
  int ans;
  ans = analogRead(0) ;
  tv[count]  = map(ans,0,1023,0,255) ;
  
  if(count==999){
    int hit = 0;
    int rpm = 0;
    for (int i=1;i2) {
        hit++;
      }
    }
    
    rpm = hit * 30;
    
    Serial.print("RPM: ");
    Serial.print(rpm);
    Serial.print(", Time(second): ");
    Serial.println(sec);
    sec++;
    count = 0;
  }else{
    count ++;
  }
  delayMicroseconds(997) ;
}
