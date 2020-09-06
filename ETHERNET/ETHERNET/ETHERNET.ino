#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below. The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);

// Initialize the Ethernet server library with the IP address and port you want to use (port 80 is default for HTTP):
EthernetServer server(19227);
EthernetClient client;

char eth_recv_buf[128];
char eth_send_buf[37] = "M SD8 124 01 23 45 67 89 AB CD EF \r\n";
char eth_recv_len;
char eth_send_len;
void EthWrite(){
    if (Serial.available()){
        one_char = Serial.read();
        if (one_char == 'M'){
            serial_itr = 0;
        }
        serial_recv_buf[serial_itr] = one_char;
        if ((one_char == '\n') && (serial_itr == 35)){
            client.write(serial_recv_buf, 36);
        }
        if ((++serial_itr) > 36) {
            serial_itr = 0;
        }
    }
}
void setup() {
    // Open serial communications and wait for port to open:
    Serial.begin(115200);
    while (!Serial) { ; }
    Ethernet.init(10);  // Most Arduino shields
    Ethernet.begin(mac, ip);

    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
        while (true) {
            delay(1); // do nothing, no point running without Ethernet hardware
        }
    }
    server.begin(); // listen相当
    pinMode(8, OUTPUT);
}
char c;
void loop() {
    // listen for incoming clients
    client = server.available(); // accept相当
    if (client) {
        while (client.connected()) {
            if (eth_recv_len = client.available()) {
                digitalWrite(8, HIGH);
                c = client.read(eth_recv_buf, eth_recv_len);
                Serial.write(eth_recv_buf, eth_recv_len);
            }            
            EthWrite();
            digitalWrite(8, LOW);
        }

        delay(100);
        client.stop();
    }
}
