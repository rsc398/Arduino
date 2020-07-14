#include <EthernetServer.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <Dhcp.h>
#include <Dns.h>
#include <EthernetUdp.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xF0, 0x0D };
byte ip[] = { 192, 168, 10, 10 };
EthernetServer server(8888);

const int STATE_INIT = 0;
const int STATE_1 = 1;
const int STATE_2 = 2;
const int STATE_3 = 3;

const int PIN_LED = 8;

void setup() {
  Ethernet.begin( mac, ip );
  server.begin();

  pinMode( PIN_LED, OUTPUT );
  digitalWrite( PIN_LED, LOW );
}

void loop() {
  EthernetClient client = server.available();
  int state = STATE_INIT;
  int i;
    
  if( client ){
    while( client.connected() ){
      while( ( i = client.read() ) != -1 ){
        if( state == STATE_INIT ){
          if( i == 'S' ){
            state = STATE_1;
          }
          else{
            client.stop();
            break;
          }
        }
        else if( state == STATE_1 ){
          if( i == ':' ){
            state = STATE_2;
          }
          else{
            state = STATE_INIT;
            client.stop();
            break;
          }
        }
        else if( state == STATE_2 ){
          if( i == '1' ){
            switch_led(1);
            client.print("OK");
          }
          else if( i == '0' ){
            switch_led(0);
            client.print("OK");
          }

          state = STATE_INIT;
          client.stop();
          break;
        }
      }
      
    }
  }
}

void switch_led(int on){
  digitalWrite( PIN_LED, on ? HIGH : LOW );  
}
