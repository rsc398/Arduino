const int PIN_PIR_SIG = 5;
const int PIN_LED = 10;

void setup() {
  pinMode( PIN_PIR_SIG, INPUT_PULLUP );
  pinMode( PIN_LED, OUTPUT );
}

void loop() {
  int i = digitalRead( PIN_PIR_SIG );
  if( i == LOW ){
    for( int j=0; j<5; j++ ){
      digitalWrite( PIN_LED, HIGH );
      delay( 50 );
      digitalWrite( PIN_LED, LOW );
      delay( 50 );
    }
  }
}
