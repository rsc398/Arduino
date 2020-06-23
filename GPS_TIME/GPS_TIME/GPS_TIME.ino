#include <LCD4Bit_mod.h>
#include <Time.h>
#include <SPI.h>
 
#ifndef cbi
#define cbi(PORT, BIT) (_SFR_BYTE(PORT) &= ~_BV(BIT))
#endif
#ifndef sbi
#define sbi(PORT, BIT) (_SFR_BYTE(PORT) |= _BV(BIT))
#endif
 
char   junk = ' ';
String datain; //data from serial
char   subch[96]; //sub string used for cvs
char   chbuff[128];
char   *cmd;
long   gpstime; //gps time info
long   gpsdate; //gps date info
bool   gpsstatus; //gps data valid / invalid flag
bool   initialized; //time initialized
int    lastsec; //last second updated
int    lastgpssec; //last gps data received
int    numgps;
static long timezoneadjust = 3600 * 9; //+9 hour from UTC

int    mode;
int  adc_key_val[5] = {
  30, 150, 360, 535, 760
};
int NUM_KEYS = 5;
int adc_key_in;
int key;
int oldkey;
 

byte   timecode[60];
bool   jjyemitting;
int    jjy_msdur;
unsigned long jjy_startTime;
 
LCD4Bit_mod lcd = LCD4Bit_mod(2);
 
void setup() {
  mode = 0;
  lcd.init();
  lcd.clear();
  jjyemitting = false;
  initialized = false;
  lastsec = -1;
  lastgpssec = -1;
  numgps = 0;
  Serial.begin(9600);
  lcd.cursorTo(1, 0);
  lcd.printIn("---[--]");
}
 
void loop() {
  if (mode == 0) { //GPS receive mode
    if (Serial.available()) {
      while (Serial.available() > 0) {
        junk = Serial.read();
        datain = datain + junk;
      }
      if (junk == '\n' || junk == '\r') { //end of line
        datain.trim();
        if (datain.length() > 0) {
          Serial.println(datain);
          cmd = getcsvparam(&datain[0], 0);
          if (strcmp(cmd, "$GPRMC") == 0) { //get time from RMC data
            if (strlen(getcsvparam(&datain[0], 1)) > 6) {
              gpstime = (long)atof(getcsvparam(&datain[0], 1)); //time
              gpsstatus = strcmp(getcsvparam(&datain[0], 2), "A") == 0 ? true : false; //validity
              gpsdate = atol(getcsvparam(&datain[0], 9)); //date
              setTime(gpstime / 10000, (gpstime / 100) % 100, gpstime % 100, gpsdate / 10000, (gpsdate / 100) % 100, (gpsdate % 100) + 2000);
              adjustTime(timezoneadjust);
              initialized = true;
            }
            datain = "";
          }
          else if (strcmp(cmd, "$GPGGA") == 0) { //get satellite number
            numgps = atoi(getcsvparam(&datain[0], 6));
            lastgpssec = second();
            datain = "";
          }
          else {
            datain = "";
          }
        }
      }
    }
 
    if (initialized) {
      if (lastsec != second()) {
        emitJJY();
        char gpsinfobuff[5];
        if ((second() + 60 - lastgpssec) % 60 > 5) //if over 5 sec since last gps data receive, clear flag
          lastgpssec = -1;
        if (lastgpssec == -1) {
          strcpy(gpsinfobuff, "GPS[--]");
        } else {
          sprintf(gpsinfobuff, "GPS[%02d]", numgps);
        }
        if (gpsstatus) {
          //sprintf(chbuff, "GPS[%s]:%02d:%02d:%02d %04d/%02d/%02d", gpsinfobuff, hour(), minute(), second(), year(), month(), day());
          //Serial.println(chbuff);
          lcd.cursorTo(1, 0);
          lcd.printIn(gpsinfobuff);
          sprintf(chbuff, "%02d:%02d:%02d %02d-%02d", hour(), minute(), second(), month(), day());
          lcd.cursorTo(2, 0);
          lcd.printIn(chbuff);
        } else {
          //sprintf(chbuff, "---[--]:%02d:%02d:%02d %04d/%02d/%02d", hour(), minute(), second(), year(), month(), day());
          //Serial.println(chbuff);
          lcd.cursorTo(1, 0);
          lcd.printIn("---[--]");
          sprintf(chbuff, "%02d:%02d:%02d %02d-%02d", hour(), minute(), second(), month(), day());
          lcd.cursorTo(2, 0);
          lcd.printIn(chbuff);
        }
        lastsec = second();
      }
    }
  } else {
    if (initialized) {
      if (lastsec != second()) {
        emitJJY();
        sprintf(chbuff, "%02d:%02d:%02d %02d-%02d", hour(), minute(), second(), month(), day());
        lcd.cursorTo(2, 0);
        lcd.printIn(chbuff);
        while (jjyemitting)
          procJJY();
        lastsec = second();
      }
    } else {
      lcd.cursorTo(1, 0);
      lcd.printIn("Time not synced");
    }
  }
 
  checkkey();
 
  procJJY(); //to stop emission
}
char *getcsvparam(char *cvstxt, int index) {
  int strcnt = 0;
  int csvcnt = 0;
  memset(subch, 0, 96);
  for (int i = 0; i < strlen(cvstxt); i++) {
    if (cvstxt[i] == ',') {
      csvcnt++;
      if (csvcnt > index)
        break;
    } else if (csvcnt == index) {
      subch[strcnt++] = cvstxt[i];
    }
  }
  return &subch[0];
}
 
void checkkey() {
  adc_key_in = analogRead(0);
  key = get_key(adc_key_in);
  if (key != oldkey)
  {
    delay(50);
    adc_key_in = analogRead(0);
    key = get_key(adc_key_in);
    if (key != oldkey)
    {
      oldkey = key;
      if (key == 4) {
        lcd.clear();
        if (mode == 0) {
          mode = 1;
          lcd.cursorTo(1,0);
          lcd.printIn("JJY Transmit");
        } else {
          mode = 0;
          //flush any incoming data before switching
          if (Serial.available()) {
            while (Serial.available() > 0) {
              junk = Serial.read();
            }
          }
          lcd.cursorTo(1,0);
          lcd.printIn("---[--]");
        }
      }
    }
  }
}
 
int get_key(unsigned int input)
{
  int k;
 
  for (k = 0; k < NUM_KEYS; k++)
  {
    if (input < adc_key_val[k])
    {
      return k;
    }
  }
 
  if (k >= NUM_KEYS)
    k = -1;     // No valid key pressed
 
  return k;
}

void emitJJY() {
  if (jjyemitting)
    return;
  jjy_startTime = millis();
  // generate 40khz from 3 pin using PWM
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  TCCR2A = _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS20);
  OCR2A = F_CPU / 2 / 40000/*hz*/;
  OCR2B = OCR2A / 2; /* 50% duty */
  sbi(TCCR2A, COM2B1);
  // calc signal duration (ms)
  jjy_msdur = calcTimeCodeDuration();
  jjyemitting = true;
  lcd.cursorTo(1, 15);
  lcd.printIn("*");
}
 
void procJJY() {
  if (jjyemitting) {
    if (millis() - jjy_startTime >= jjy_msdur) {
      cbi(TCCR2A, COM2B1);
      jjyemitting = false;
      lcd.cursorTo(1, 15);
      lcd.printIn(" ");
    }
  }
}
 
unsigned int calcTimeCodeDuration()
{
  int s = second();
  if (s == 0)
    setupTimeCode();
  return timecode[s] * 100;
}
 
void setupTimeCode()
{
  int i;
  memset(timecode, 8, sizeof(timecode));
 
  setupTimeCode100(minute(), 0);
  timecode[0] = 2;
 
  setupTimeCode100(hour(), 10);
 
  int d = dayOfYear();
  setupTimeCode100(d / 10, 20);
  setupTimeCode100(d % 10 * 10, 30);
 
  int parity1 = 0, parity2 = 0;
  for (i = 12; i < 20; i++) parity1 ^= timecode[i] == 5;
  for (i =  1; i < 10; i++) parity2 ^= timecode[i] == 5;
  timecode[36] = parity1 ? 5 : 8;
  timecode[37] = parity2 ? 5 : 8;
 
  setupTimeCode100(year() % 100, 40);
  for (i = 44; i > 40; i--)
    timecode[i] = timecode[i - 1];
  timecode[40] = 8;
 
  int w = weekday() - 1;
  timecode[50] = (w & 4) ? 5 : 8;
  timecode[51] = (w & 2) ? 5 : 8;
  timecode[52] = (w & 1) ? 5 : 8;
  timecode[59] = 2;
}
 
void setupTimeCode100(int m, int i)
{
  timecode[i + 0] = ((m / 10) & 8) ? 5 : 8;
  timecode[i + 1] = ((m / 10) & 4) ? 5 : 8;
  timecode[i + 2] = ((m / 10) & 2) ? 5 : 8;
  timecode[i + 3] = ((m / 10) & 1) ? 5 : 8;
  timecode[i + 4] = 8;
  timecode[i + 5] = ((m % 10) & 8) ? 5 : 8;
  timecode[i + 6] = ((m % 10) & 4) ? 5 : 8;
  timecode[i + 7] = ((m % 10) & 2) ? 5 : 8;
  timecode[i + 8] = ((m % 10) & 1) ? 5 : 8;
  timecode[i + 9] = 2;
}
 
int dayOfYear()
{
  tmElements_t tm = {0, 0, 0, 0, 1, 1, CalendarYrToTm(year())};
  time_t t = makeTime(tm);
  return (now() - t) / SECS_PER_DAY + 1;
}
