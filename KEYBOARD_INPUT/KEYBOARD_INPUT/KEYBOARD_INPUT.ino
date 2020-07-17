void setup()
{
    Keyboard.begin();
}
void loop()
{
    Keyboard.press('A');
    Keyboard.releaseAll();
    delay(1000);
}
