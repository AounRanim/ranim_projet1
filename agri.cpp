#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include<DHT.h>
DHT dht(2,DHT22);
#define lightS 0
#define  tempS 1

void setup() {
 lcd.init();
 lcd.backlight();
 dht.begin();

}

void loop() {
  int light=1023-analogRead(lightS);
  int lightPrecent= (light / 1023.0) * 100;
  int temp=dht.readTemperature();
  int hmd=dht.readHumidity();
  int soilT=1023-analogRead(tempS);
  int soilPrecent= (soilT / 1023.0) * 100;
  lcd.setCursor(0,0);
  lcd.print("temperature: ");
  lcd.setCursor(12,0);
  lcd.print(temp);
  lcd.setCursor(17,0);
  lcd.print("c");
  lcd.setCursor(0,1);
  lcd.print("humidity :");
  lcd.setCursor(14,1);
  lcd.print(hmd);
  lcd.setCursor(17,1);
  lcd.print( "%");
  lcd.setCursor(0,2);
  lcd.print("light :");
  lcd.setCursor(14,2);
  lcd.print( lightPrecent);
  lcd.setCursor(17,2);
  lcd.print( "%");
  lcd.setCursor(0,3);
  lcd.print("temp soil: ");
    lcd.setCursor(11,3);
  lcd.print(soilPrecent);
  lcd.setCursor(17,0);
  lcd.print("c");
  

  if (lightPrecent <30 ){
    lcd.backlight();
  }
  else{
    lcd.noBacklight();
  }
  
  lcd.clear();
 

}
