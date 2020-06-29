#include <Arduino.h>
#include <Wire.h>
#include <radio.h>
#include <RDA5807M.h>
#define FIX_BAND     RADIO_BAND_FMWORLD //RADIO_BAND_FM    //Radio Band -FM
#define FIX_STATION  8000 //10050            //Station Tuned = 100.50 MHz.
#define FIX_VOLUME   5               //Audio Volume Level 5.

RDA5807M radio;    

void setup() {

  Serial.begin(9600);
  Serial.println("FM Radio");
  delay(200);

  radio.init();
  radio.debugEnable();

  radio.setBandFrequency(FIX_BAND, FIX_STATION);
  radio.setVolume(FIX_VOLUME);
  radio.setMono(false);
  radio.setMute(false);
} 



void loop() {
  char s[12];
  radio.formatFrequency(s, sizeof(s));
  Serial.print("Station:"); 
  Serial.println(s);

  Serial.print("Radio:"); 
  radio.debugRadioInfo();

  Serial.print("Audio:"); 
  radio.debugAudioInfo();

  delay(3000);
} 
