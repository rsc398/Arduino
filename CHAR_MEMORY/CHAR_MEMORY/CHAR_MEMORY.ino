#include <avr/pgmspace.h>

prog_char string_0[] PROGMEM = "String 0";
prog_char string_1[] PROGMEM = "String 1";
prog_char string_2[] PROGMEM = "String 2";
prog_char string_3[] PROGMEM = "String 3";

// Then set up a table to refer to your strings.

PROGMEM const char *string_table[] = {
  string_0,
  string_1,
  string_2,
  string_3
};
char buffer[30];
void setup() {
  Serial.begin(9600);
}
void loop() {
  for (int i = 0; i < 4; i++) {
    strcpy_P(buffer, (char*)pgm_read_word(&(string_table[i])));
    Serial.println( buffer );
    delay( 500 );
  }
}
