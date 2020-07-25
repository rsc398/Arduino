#include <VirtualWire.h>
#define SEND_PIN 12
void setup() {
  vw_set_tx_pin(SEND_PIN);
  vw_setup(2000);
}
void loop() { 
  int numData = 25;
  char datas[numData];
  for (int i=0;i<numData;i++) {
    datas[i] = i;
  }
  vw_send((uint8_t *)datas, numData);
  vw_wait_tx();
}
