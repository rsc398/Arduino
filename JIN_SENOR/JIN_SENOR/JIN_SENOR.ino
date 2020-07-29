void setup()
{
    pinMode(13, OUTPUT);
}

void loop()
{
    if (digitalRead(2) == LOW) {
        digitalWrite(13, HIGH);
      delay(100);
    } else
        digitalWrite(13, LOW);
    }
}
