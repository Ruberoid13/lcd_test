/*Проверка работы LCD 1602
  Проверка работы кнопок
  Select, Left, Up, Down, Rigth, Rst
  Изменение яркости экрана
  http://progdron.com/ru/22-shild/298-lcd1602
 

 */


// include the library code:
#include "DHT.h"
#include <LiquidCrystal.h>
#include <Wire.h>

#define DHT1PIN 3
DHT dht(DHT1PIN, DHT22);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  analogWrite(10, 100);// изменение яркости экрана
  lcd.begin(16, 2);
  lcd.clear();
  dht.begin();
}

/*byte key(){//1-719, 2 - 477, 3 - 131, 4 - 305, 5 - 0
  int val = analogRead(0);
  if (val < 50) return 5;
  else if (val < 150) return 3;
  else if (val < 350) return 4;
  else if (val < 500) return 2;
  else if (val < 800) return 1;
  else if (val <= 1023) return 0;
}*/

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cant read DHT");
    return;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(t);
  delay(2000);
}


/*  switch (key())
  {
   case 1:
    lcd.print("Select");
     break;
   case 2:
    lcd.print("Left");
  break;
  case 3:
    lcd.print("UP");
    break;
    case 4:
     lcd.print("Down");
    break;
    case 5:
     lcd.print("Rigth");
     break;  
  }*/
 
