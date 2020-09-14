#include <HkNfcRw.h>
#include <HkNfcA.h>
#include <inttypes.h>
#include <string.h>
 
uint32_t last_uid    = 0;
uint32_t current_uid = 0;
uint8_t uid[] = {0, 0, 0, 0, 0, 0, 0}; 
 
const uint8_t UID_RESET_COUNT PROGMEM = 2;
uint8_t not_detected_count = 0;
 
const uint32_t TAG_1 PROGMEM = 2852876548;
const uint32_t TAG_2 PROGMEM = 2987950596;
 
void setup()
{
  bool ret;
 
  Serial.begin(115200);
 
  ret = HkNfcRw::open();
  while (!ret) {}
}
 
void loop()
{
  HkNfcRw::Type type = HkNfcRw::detect(true, false, false);
  if(type == HkNfcRw::NFC_A) {
 
    if(HkNfcRw::getNfcId(uid)){      
 
      current_uid = uid[6];
      for(int i=5; i>=0; i--){
        current_uid <<= 8; current_uid |= uid[i];
      }
      Serial.print(F("UID:"));
      Serial.println(current_uid);   
      if(last_uid != current_uid){
        if(current_uid == TAG_1){
          Serial.println(F("Find TAG 1!"));
        }else if(current_uid == TAG_2){
          Serial.println(F("Find TAG 2!"));
        }        
        last_uid = current_uid;
      }
 
      not_detected_count = 0;
    }else{
      Serial.println(F("Failed to get UID."));
    }
  } else {
 
    Serial.println(F("No Tag."));
 
    not_detected_count++;
    if(not_detected_count == UID_RESET_COUNT){
      Serial.println(F("Reset UID."));
      last_uid = 0;
      not_detected_count = 0;
    }
  }
 
  delay(500);
}
