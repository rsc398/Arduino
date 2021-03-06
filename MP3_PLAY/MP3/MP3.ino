const unsigned char sample_raw[] PROGMEM = {
  0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x80, 0x80,
・・・・・・
  0x7f, 0x80, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x7f
};
unsigned int sample_raw_len = 1200;

void setup() 
{
  pinMode(3, OUTPUT);
  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  
  play();
}

void play() {
  for (int i = 0; i < sample_raw_len; i++) {
    OCR2B = pgm_read_byte_near(&sample_raw[i]);
    delayMicroseconds(125);
  }
} 

void loop() {
}
