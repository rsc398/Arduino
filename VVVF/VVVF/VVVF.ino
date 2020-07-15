int uOut = 9;
int vOut = 3;
int wOut = 11;
int freqIn = 0;
int amplitudeIn  = 1;



//variable setup
float freq ;
float amplitude = 0.;
float uModulate;
float vModulate;
float wModulate;
int ang;
int sinw[180];
int angu;
int angv;
int angw;

void setup() {
  pinMode(uOut, OUTPUT);
  pinMode(vOut, OUTPUT);
  pinMode(wOut, OUTPUT);
    Serial.begin(9600);
    for (ang = 0; ang < 180; ang = ang + 1) {
      sinw[ang] = 126 * (sin(ang * 3.14 / 90) + 1);
      Serial.print(sinw[ang]);
      Serial.print(",");
    }


  angu = 0;
  angv = 60;
  angw = 120;


}

void loop() {
  freq = analogRead(freqIn) / 10.23;
  amplitude = freq * 0.0099 + 0.1;


  uModulate = sinw[angu];
  vModulate = sinw[angv];
  wModulate = sinw[angw];

  if (freq < 1.0) {
    amplitude = 0;
  }
  if (amplitude >= 1.) {
    amplitude = 1.;
  }
  analogWrite (uOut, int ( uModulate  * amplitude));
  analogWrite (vOut, int ( vModulate * amplitude));
  analogWrite (wOut, int ( wModulate * amplitude));

  angu = angu + 1;
  angv = angv + 1;
  angw = angw + 1;


  if (angu >= 180) {
    angu = 0;
  }
  if (angv >= 180) {
    angv = 0;
  }
  if (angw >= 180) {
    angw = 0;
  }
  delayMicroseconds(int(9000 / freq));

}
