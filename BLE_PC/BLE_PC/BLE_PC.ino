#include <SoftwareSerial.h>

int bluetoothRx = 12;  // RX-I of bluetooth
int bluetoothTx = 13;  // TX-O of bluetooth
int count = 0;

SoftwareSerial mySerial(bluetoothRx, bluetoothTx); // RX, TX

void setup()  
{
  mySerial.begin(115200);
}

void loop()
{
    mySerial.println(count);
    count++;
    delay(1000);
}
