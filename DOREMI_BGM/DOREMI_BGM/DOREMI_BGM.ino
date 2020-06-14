int pin = 13;
int state = 0 ;
void setup() {
  pinMode(10,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
}


void loop() {
  state = digitalRead(3);
 

  if(state == 0){
     tone(pin,262,200) ;
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(600);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,294,200) ;
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,330,200) ;
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(500);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,262,200) ;
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(200);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(400);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,262,200) ;  // ド
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(400);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(600);
     digitalWrite(7,LOW);
     delay(10);
    
     tone(pin,294,200) ;  // レ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(600);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(200);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
    
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(200);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(200);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,294,200) ;  // レ
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(200);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(1200);
     digitalWrite(8,LOW);
     delay(10);
    
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(600);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(200);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(500);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(400);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(400);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(600);
     digitalWrite(10,LOW);
     delay(10);

     tone(pin,349,200) ;
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(600);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(200);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,440,200) ;  // ラ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(200);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,440,200) ;  // ラ
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(200);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(200);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,440,200) ;  // ラ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(1200);
     digitalWrite(2,LOW);
     delay(10);

     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(600);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,262,200) ;  // ド
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,294,200) ;  // レ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(200);
     digitalWrite(7,LOW);
     delay(10);

     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(200);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(200);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,440,200) ;  // ラ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(1200);
     digitalWrite(7,LOW);
     delay(10);

     tone(pin,440,200) ;  // ラ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(600);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,294,200) ;  // レ
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(200);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(200);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(200);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,440,200) ;  // ラ
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(200);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,494,200) ;  // シ
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(1200);
     digitalWrite(8,LOW);
     delay(10);

     tone(pin,494,200) ;  // シ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(600);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(200);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(200);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,440,200) ;  // ラ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(200);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,494,200) ;  // シ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(200);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,523,200) ;  // ド
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(1200);
     digitalWrite(10,LOW);
     delay(10);

     tone(pin,494,200) ;  // シ
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,466,200) ;  // シ♭
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(200);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,440,200) ;  // ラ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(400);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(400);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,494,200) ;  // シ
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(400);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(400);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,523,200) ;  // ド
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(1200);
     digitalWrite(2,LOW);
     delay(10);

     tone(pin,262,200) ;  // ド
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(200);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,294,200) ;  // レ
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,330,200) ;  // ミ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(200);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,349,200) ;  // ファ
     delay(0) ;
     digitalWrite(2,HIGH);
     delay(200);
     digitalWrite(2,LOW);
     delay(10);
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(200);
     digitalWrite(10,LOW);
     delay(10);
     tone(pin,440,200) ;  // ラ
     delay(0) ;
     digitalWrite(8,HIGH);
     delay(200);
     digitalWrite(8,LOW);
     delay(10);
     tone(pin,494,200) ;  // シ
     delay(0) ;
     digitalWrite(7,HIGH);
     delay(200);
     digitalWrite(7,LOW);
     delay(10);
     tone(pin,523,200) ;  // ド
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(0);
     digitalWrite(8,HIGH);
     delay(0);
     digitalWrite(7,HIGH);
     delay(0);
     digitalWrite(2,HIGH);
     delay(400);

     digitalWrite(10,LOW);
     delay(0);
     digitalWrite(8,LOW);
     delay(0);
     digitalWrite(7,LOW);
     delay(0);
     digitalWrite(2,LOW);
     delay(70);

    
     tone(pin,392,200) ;
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(0);
     digitalWrite(8,HIGH);
     delay(0);
     digitalWrite(7,HIGH);
     delay(0);  
     digitalWrite(2,HIGH);
     delay(400);

     digitalWrite(10,LOW);
     delay(0);
     digitalWrite(8,LOW);
     delay(0);
     digitalWrite(7,LOW);
     delay(0);
     digitalWrite(2,LOW);
     delay(70);
    
     tone(pin,523,200) ;  // ド
     delay(0) ;
     digitalWrite(10,HIGH);
     delay(0); 
     digitalWrite(8,HIGH);
     delay(0);
     digitalWrite(7,HIGH);
     delay(0); 
     digitalWrite(2,HIGH);
     delay(1200);

     digitalWrite(10,LOW);
     delay(0);
     digitalWrite(8,LOW);
     delay(0);
     digitalWrite(7,LOW);
     delay(0);
     digitalWrite(2,LOW);
     delay(70);

    
}
}
