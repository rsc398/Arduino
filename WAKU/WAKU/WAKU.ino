void printValuesToLCD() {
    int xp = 10; int yp = 40;
    int x0 = 1; int y0 = 5; 
 
    tft.fillScreen(ST77XX_BLACK);
    tft.setTextColor(ORANGE);
    tft.setTextWrap(false);
 
    tft.setCursor(xp, yp+0);
    tft.setFont(&FreeMonoBold12pt7b);
    tft.setRotation(0);
    tft.drawRect(x0, y0, 238, 170, GREEN);
 
    tft.print("Temperature ");
    tft.setCursor(xp+128, yp+30);
    tft.print(String(bme.readTemperature(),1));
    tft.print("*C");
 
    tft.setCursor(xp,yp+70);
    tft.print("Pressure ");
    tft.print(String((bme.readPressure() / 100.0F),0));
    tft.print("hPa");
 
    tft.setCursor(xp, yp+110);
    tft.print("Humidity ");
    tft.print(String(bme.readHumidity(),0));
    tft.print("%");
}
