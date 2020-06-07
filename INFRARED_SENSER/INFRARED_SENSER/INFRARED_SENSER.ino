int SOCKET = 2;

void setup() {
    Serial.begin(9600);
}

void loop() {
    String message = “”;

    if (digitalRead(SOCKET) == 1){
       message = “Some One Is Here! “;
    } else {
       message = “Nobody”;
    }
    Serial.println(message);

    delay (1000);
}
