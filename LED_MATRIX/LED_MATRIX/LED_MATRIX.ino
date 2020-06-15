 boolean ledmatrix[8][8] = {
  {0,0,0,1,1,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,1,1,1,1,0,0}
};

void setup(){
  for(int i=2;i<=17;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,HIGH);
  }
}

void loop(){
  for( int i = 2 ; i <= 9 ; i++ ){
    digitalWrite( i , LOW );
    for( int j = 10 ; j <= 17 ; j++ ){
      digitalWrite( j , ledmatrix[ i - 2 ][ j - 10 ] );
      delayMicroseconds(300);
      digitalWrite( j , LOW );
    }
    digitalWrite( i , HIGH );
  }
