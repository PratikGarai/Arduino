#include<LiquidCrystal.h>
#include<Wire.h>

LiquidCrystal lcd(2,3,4,5,6,7);
int s;
double temp;

void setup()
{
  Wire.begin(4);
  Wire.onReceive(recvHandler);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Temp : ");
}

void loop()
{
  delay(100);
}

void recvHandler(int h)
{
  s = Wire.read();
  temp = (double)s / 1024;   
  temp = temp * 5;                     
  temp = temp - 0.5;                  
  temp = temp * 100; 
  lcd.clear();
  lcd.print("Temp : ");
  lcd.setCursor(7,0);
  lcd.print(temp);
  lcd.print((char)176);
  lcd.print("C");
  delay(50);
}