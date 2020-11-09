#include &lt;Metro.h&gt;
Metro metro1 = Metro(250);
#define DATAPIN (5)
#define LATCHPIN (6)
#define CLOCKPIN (7)
#define FREQPIN (3)
unsigned long l_time = 0;
unsigned long t_time = 0;
unsigned int h_time = 0;
struct PTN{
int nOut;
};
struct PTN ptn[11]
{
B00111111,
B00000110,
B01011011,
B01001111,
B01100110,
B01101101,
B01111101,
B00000111,
B01111111,
B01100111,
B00000000
};
void setup() {
pinMode(DATAPIN, OUTPUT);
pinMode(LATCHPIN, OUTPUT);
pinMode(CLOCKPIN, OUTPUT);
pinMode(FREQPIN, INPUT);
Serial.begin(9600);
}
long FREQ1 = 0;
void loop() {
if (metro1.check() == 1) {
h_time = pulseIn( 3, HIGH );
l_time = pulseIn( 3, LOW);
t_time = h_time + l_time ;
Serial.print( (1.0 / t_time) * 1000000 , DEC );
Serial.println( "Hz");
FREQ1 = (1.0 / t_time) * 1000000;
Out5Digit(FREQ1);
}
Out5Digit(FREQ1);
}
void Out5Digit(long nValue)
{
for(int i=0;i&lt;5;i++){
int amari = nValue %10;
Out(i, amari);
nValue = nValue / 10;
}
}
void Out(int nKeta, int nValue)
{
if(nKeta==4 and nValue==0) {
nValue=10;
}
digitalWrite(LATCHPIN, LOW);
ShiftOut8( DATAPIN, CLOCKPIN, ~(B00000001 &lt;&lt; nKeta));
ShiftOut8( DATAPIN, CLOCKPIN, ptn[nValue].nOut);
digitalWrite(LATCHPIN, HIGH);
delay(1);
}
void ShiftOut8( int dataPin, int clockPin, unsigned long val )
{
for( int i = 7; i &gt;= 0; i-- ){
digitalWrite(dataPin, !!(val &amp; (1L &lt;&lt; i)));
digitalWrite(clockPin, HIGH);
digitalWrite(clockPin, LOW);
}
}
