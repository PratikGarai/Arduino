#include<LiquidCrystal.h>

LiquidCrystal lcd(6,7,2,3,4,5); //RS,enable, data pins in ascending order
void setup()
{
  lcd.begin(16,2);    // 16x2 is the size of LCD ; 16 alpha 2 lines
  lcd.clear();
  lcd.setCursor(0,0);   // 0th character of 0th line
  lcd.print("Pratik");  // Cursor is currently at 0,7
  lcd.setCursor(0,1);   // 0th character of 1th Line
  lcd.print("Time : "); // Cursor is at 7,1
}

void loop()
{
  lcd.setCursor(7,1);   // to prevent cursor from sliding
  lcd.print(millis()/1000);
  delay(1000);
}


// LED pins = LED backlight