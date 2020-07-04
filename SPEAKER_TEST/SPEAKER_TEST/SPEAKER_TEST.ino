int speakerPin = 9;

void setup(){ 
  pinMode(speakerPin, OUTPUT);
}
void loop(){
  for(int delayTime=1; delayTime<500; delayTime++){
    for(int i=0; i<40; i++){
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(delayTime);
    }
  }
  for(int delayTime=500; delayTime>0; delayTime--){
    for(int i=0; i<40; i++){
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(delayTime);

    }
  }
}
