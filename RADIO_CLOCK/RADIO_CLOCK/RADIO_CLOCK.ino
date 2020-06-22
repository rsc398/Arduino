#include &ltLiquidCrystal.h>

#define Input_Pin 13
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int year;
byte month;
byte week_no;
byte day;
byte hour;
byte minutes;
byte sec;
const byte month_day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

unsigned int c_year;
unsigned int c_week;
unsigned int c_day;
unsigned int c_hour;
unsigned int c_minutes;
unsigned long pulse;
long pulse_width;

byte code;
byte marker;
byte i;
byte err = 0;

byte get_code(void){
  byte ret_code = 3; // エラー
  
  while (digitalRead(Input_Pin) == 0){
  }
  lcd.setCursor(14, 1);
  if (sec < 10)
    lcd.print(" ");
  lcd.print(sec++);
  
  pulse = millis() >> 1;
  while (digitalRead(Input_Pin) == 1){
  }
  pulse_width = (millis() >> 1) - pulse;
  if (pulse_width < 0){
    pulse_width = (pulse_width + 0x7FFFFFFF) << 1;
  }else{
    pulse_width = pulse_width << 1;
  }
  if ((pulse_width > 150) && (pulse_width < 250)) // 0.2sec
    ret_code = 2; // marker
  if ((pulse_width > 450) && (pulse_width < 550)) // 0.5sec
    ret_code = 1; // High
  if ((pulse_width > 750) && (pulse_width < 850)) // 0.8sec
    ret_code = 0; // Low
  lcd.setCursor(0, 1);
  lcd.print(pulse_width);
  lcd.setCursor(4, 1);
  lcd.print(ret_code);
  if (ret_code ==3){
    lcd.print(" ");
    lcd.print(++err);
  }
  return(ret_code);
}

void setup() {
  year = 0;
  month = 0;
  week_no = 0;
  day = 0;
  hour = 0;
  minutes = 0;
  lcd.begin(16, 2);
  pinMode(Input_Pin, INPUT);
  while (digitalRead(Input_Pin) == 1){
  }
  marker = 0;
  do{
    code = get_code();
    if (code == 2){
      marker++;
    }else{
      marker = 0;
    }
  } while (marker < 2);
}

void loop() {
  sec = 0;
  c_minutes = 0;
  for (i = 0; i < 8; i++){
    c_minutes = c_minutes  << 1;
    c_minutes += get_code();
  }
  minutes = (c_minutes >> 5) * 10 + (c_minutes & B1111) ;
  code = get_code();
  c_hour = 0;
  for (i = 0; i < 9; i++){
    c_hour = c_hour << 1;
    c_hour += get_code();
  }
  hour = (c_hour >> 5) * 10 + (c_hour & B1111) ;
  code = get_code();
  c_day = 0;
  for (i = 0; i < 9; i++){
    c_day = c_day << 1;
    c_day += get_code();
  }
  day = (c_day >> 5) * 100 + (c_day & B1111) * 10 ;
  code = get_code();
  
  c_day = 0;
  for (i = 0; i < 4; i++){
    c_day = c_day << 1;
    c_day += get_code();
  }
  day += c_day;
  
  month = 0;
  do{
    day -= month_day[month];
    month ++;
  } while( day > month_day[month]);
    
  do{
    code = get_code();
  } while (code != 2);

  if (minutes != 15 && minutes != 45){
    c_year = 0;
    for (i = 0; i < 9; i++){
      c_year = c_year << 1;
      c_year += get_code();
    }
    year = (c_year >> 4) * 10 + (c_year & B1111) + 2000;
    code = get_code();
    week_no = 0;
    for (i = 0; i < 3; i++){
    week_no = week_no << 1;
    week_no += get_code();
    }
  }else{
    delay(10500);
  }

  while (get_code() != 2);
  lcd.setCursor(0, 0);
  lcd.print(year);
  lcd.print("/");
  if (month < 10)
    lcd.print(" ");
  lcd.print(month);
  lcd.print("/");
    if (day < 10)
    lcd.print(" ");
  lcd.print(day);
  lcd.print("/");
  lcd.print("(");
  lcd.print(week_no);
  lcd.print(") ");
  
  lcd.setCursor(8, 1);
    if (hour < 10)
    lcd.print(" ");
  lcd.print(hour);
  lcd.print(":");
  if (minutes < 10)
    lcd.print("0");
  lcd.print(minutes);
  
  code = get_code();

}
