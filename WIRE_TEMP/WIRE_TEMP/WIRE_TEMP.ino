#include <OneWire.h>

OneWire ds(10);
 
void setup(void) {
    Serial.begin(9600);
    Serial.println("start");
}
void loop(void) {
    byte i;
    byte present = 0;
    byte type_s;
    byte data[12];
    byte addr[8];
    float celsius;
  
    if ( !ds.search(addr)) {
         Serial.println(" ----- ");
         ds.reset_search();
         delay(250);
         return;
    }
   if (OneWire::crc8(addr, 7) != addr[7]) {
        Serial.println("CRC is not valid!");
        return;
    }
    ds.reset();
    ds.select(addr);
    ds.write(0x44, 1);
    delay(1000);
    present = ds.reset();
    ds.select(addr); 
    ds.write(0xBE);
        Serial.print(addr[0],HEX);Serial.print("-");
        Serial.print(addr[1],HEX);Serial.print(" ");
        Serial.print(addr[2],HEX);Serial.print(" ");
        Serial.print(addr[3],HEX);Serial.print(" ");
        Serial.print(addr[4],HEX);Serial.print(" ");
        Serial.print(addr[5],HEX);Serial.print(" ");
    for ( i = 0; i < 9; i++) { // we need 9 bytes
         data[i] = ds.read();
    }
    int16_t raw = (data[1] << 8) | data[0];
     if (type_s) {
        raw = raw << 3; // 9 bit resolution default
        if (data[7] == 0x10) {
            // "count remain" gives full 12 bit resolution
           raw = (raw & 0xFFF0) + 12 - data[6];
        }
     } else {
         byte cfg = (data[4] & 0x60);
         if (cfg == 0x00) raw = raw & ~7; // 9 bit resolution, 93.75 ms
         else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
         else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
     }
     celsius = (float)raw / 16.0;
     Serial.print("Temp= "); Serial.println(celsius);
}
