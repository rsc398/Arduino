#define DAT 8
#define CLK 9
float offset=0;
  
void setup() {
    Serial.begin(9600);
    Serial.println("start");
    pinMode(CLK, OUTPUT);
    pinMode(DAT, INPUT);
    offset = Read();
}
 
void loop() { 
    float data;
    data = Read();
    Serial.print(-data,3);Serial.println("g");
    delay(1000);
}
 
float Read(void){
    long sum = 0;
    for (int i = 0; i < 100; i++) {
    long data=0;
    while(digitalRead(DAT)!=0);
    for(char i=0;i<24;i++) {
        digitalWrite(CLK,1);
        delayMicroseconds(1);
        digitalWrite(CLK,0);
        delayMicroseconds(1);
        data = (data<<1)|(digitalRead(DAT));
        }
        digitalWrite(CLK,1); //gain=128
        delayMicroseconds(1);
        digitalWrite(CLK,0);
        delayMicroseconds(1);
        data = data^0x800000;
        sum += data;
     }
     float data = sum /100;
     float volt;float gram;
     volt =data*(4.2987/16777216.0/128);Serial.println(volt,10);
     gram=volt/(0.000669*4.2987/200.0);Serial.println(gram,4);
     return gram-offset;
}
