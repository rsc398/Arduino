const int BUTTON_RED = 7;
const int BUTTON_WHITE = 6;
const int BUTTON_YELLOW = 5;

const int LED = 13;

int press_count_red = 0;
int press_count_white = 0;
int press_count_yellow = 0;
int old_state_red = LOW;
int new_state_red = LOW;
int old_state_white = LOW;
int new_state_white = LOW;
int old_state_yellow = LOW;
int new_state_yellow = LOW;

//なし:0 トン:1 ツー:2
int morse_code[26][4] = {
  {1,2,0,0}, // A
  {2,1,1,1},
  {2,1,2,1},
  {2,1,1,0},
  {1,0,0,0}, // E
  {1,1,2,1},
  {2,2,1,0},
  {1,1,1,1},
  {1,1,0,0}, // I
  {1,2,2,2},
  {2,1,2,0},
  {1,2,1,1},
  {2,2,0,0}, // M
  {2,1,0,0},
  {2,2,2,0},
  {1,2,2,1},
  {2,2,1,2}, // Q
  {1,2,1,0},
  {1,1,1,0},
  {2,0,0,0},
  {1,1,2,0}, // U
  {1,1,1,2},
  {1,2,2,0},
  {2,1,1,2},
  {2,1,2,2}, // Y
  {2,2,1,1}
};

void setup(){
  
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_RED,INPUT);
  pinMode(BUTTON_WHITE,INPUT);
  pinMode(BUTTON_YELLOW,INPUT);
}

void loop(){
  
  new_state_red = digitalRead(BUTTON_RED);
  new_state_white = digitalRead(BUTTON_WHITE);
  new_state_yellow = digitalRead(BUTTON_YELLOW);
  
  if( (new_state_red == HIGH) && (old_state_red == LOW) ){
    
    press_count_red = press_count_red + 1;
  }
  
  if( (new_state_white == HIGH) && (old_state_white == LOW) ){
    
    press_count_white = press_count_white + 1;
  }
  
  if( (new_state_yellow == HIGH) && (old_state_yellow == LOW) ){
    
    morse( press_count_red, press_count_white);
    press_count_red = 0;
    press_count_white = 0; 
    
  }

  delay(20);
  
  old_state_red = new_state_red;
  old_state_white = new_state_white;
  old_state_yellow = new_state_yellow;

void morse(int a, int b){
  
  // ascii codeのみ。hexです。(from 41 to 5a)
  
  //Serial.print( "Morse with ");
  //Serial.print( a);
  //Serial.print( b);
  
  int a_code = 16*a + b;
  if( (a_code < 0x41) || (a_code > 0x5a)){
    return;
  }
  
  for( int i=0; i<4;i++){
    
    int morse_pulse = morse_code[a_code - 0x41][i];
    if( morse_pulse == 1){
      digitalWrite(LED,HIGH);
      delay(300);
      digitalWrite(LED,LOW);
      delay(300);
    }
    else if( morse_pulse == 2){
      digitalWrite(LED,HIGH);
      delay(1000);
      digitalWrite(LED,LOW);
      delay(300);
    }
    
  }
}
