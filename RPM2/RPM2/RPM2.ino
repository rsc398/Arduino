volatile unsigned long tachoBefore = 0;
volatile unsigned long tachoAfter = 0;
volatile unsigned long tachoWidth = 0;
volatile float tachoRpm = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  //pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, tachometer, FALLING);
  //attachInterrupt(1, tachometer, FALLING);

}

void loop() {

}

void tachometer() {
  tachoAfter = micros();
  tachoWidth = tachoAfter - tachoBefore;
  tachoBefore = tachoAfter;
  tachoRpm = 60000000.0 / tachoWidth;
  
  Serial.print(tachoRpm);
  Serial.print("[rpm]");
  Serial.print("\t");
  Serial.print("Before: ");
  Serial.print(tachoBefore);
  Serial.print("[us]");
  Serial.print("\t");
  Serial.print("After:");
  Serial.print(tachoAfter);
  Serial.print("[us]");
  Serial.print("\t");
  Serial.print("Width: ");
  Serial.print(tachoWidth);
  Serial.println("[us]");
