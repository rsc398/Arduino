#include <time_personal.h>
using namespace GPS;

//------------------------------------------------------
GPS::Time timeA(20130106ul, 15200l); // 15200l: 1:52:00 and set UTC, 15200ul: TOW == 15200 and set GPST
const int testpin = A3;
int pinState = LOW;
//------------------------------------------------------

void tprint(GPS::Time* time)
{
  Serial.print(time->GetTimeSystemName());
  Serial.print(", ");
  Serial.print(time->getYear());
  Serial.print("/");
  Serial.print(time->getMonth());
  Serial.print("/");
  Serial.print(time->getDay());
  Serial.print(", hhmmss: ");
  Serial.print(time->getClock());
  Serial.print(", Week no.: ");
  Serial.print(time->getWeek());
  Serial.print(", Week name: "); 
  Serial.print(time->GetWeekName());
  Serial.print(", GPSW: ");
  Serial.print(time->getGpsWeek());
  Serial.print(", GPS TOW: ");
  Serial.print(time->getGpsTow());
  Serial.print(", DOY: ");
  Serial.print(time->getDOY());
  Serial.print(", GPST: "); 
  Serial.println(time->getGpsTime());
  return;
}

void setup() {
  // test pin
  pinMode(testpin, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  Serial.println("This is time class obj. test program.");
  Serial.println("\nDeep-Copy test.");
  GPS::Time timeB = timeA;
  GPS::Time timeC;
  timeC = timeA;
  Serial.print("B raw  : ");
  tprint(&timeB);
  Serial.print("B      : ");
  timeB.Increase_Clock(86400l);
  tprint(&timeB);
  Serial.print("C      : ");
  timeC.Increase_Clock(-43200l);
  tprint(&timeC);
  Serial.print("A pre  : ");
  tprint(&timeA);
    timeA.SetTimeSystem(Time::GPST);
  Serial.print("A post : ");
  tprint(&timeA);
  timeA.SetTimeSystem(Time::UTC);
  Serial.print("A post2: ");
  tprint(&timeA);
  Serial.println("\nCompare test.");
  const char *tf[2] = {
    "False", "True"    };
  Serial.print("A > B : ");
  Serial.println(tf[timeA > timeB]);
  Serial.print("A < B : ");
  Serial.println(tf[timeA < timeB]);
  Serial.print("A == B: ");
  Serial.println(tf[timeA == timeB]);
  Serial.print("A > C : ");
  Serial.println(tf[timeA > timeC]);
  Serial.print("A < C : ");
  Serial.println(tf[timeA < timeC]);
  Serial.print("A == C: ");
  Serial.println(tf[timeA == timeC]);
  delay(3000); 
}
void loop() {
  for(long int i = 0l; i < 604800l; i++)
  {
    timeA.Increase_Clock(1l); 
  }
  Serial.print("A: ");
  tprint(&timeA);
}
