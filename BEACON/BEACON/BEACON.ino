#include "SimpleBLE.h"
SimpleBLE ble;
void setup() {
    delay(10);
    ble.begin("BLE Hall Effect Sensor");
    delay(50);
    ble.end();
}
void loop() {
    int hall=0,i;
    for(i=0;i<100;i++) hall += hallRead(); hall/=100;
    String out = "ehall_1," + String(hall,DEC);
    ble.begin(out);
    delay(50);
    ble.end();
    delay(3000);
}
