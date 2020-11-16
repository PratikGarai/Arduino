#include<LiquidCrystal.h>
LiquidCrystal lcd(6,7,2,3,4,5);
int s,t,sec,min,g;    
double temp; 
float p;

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  lcd.clear();
  printTime();
  printTemp();
  lcd.print(" ; ");
  printGas();
  delay(1000);
}

void printTime()
{
  t = millis();
  t = t/1000;
  sec = t%60;
  t = t/60;
  min = t%60;
  t = t/60;
  lcd.setCursor(0,0);
  if(t<10)
    lcd.print("0");
  lcd.print(t);
  lcd.print(":");
  if(min<10)
    lcd.print("0");
  lcd.print(min);
  lcd.print(":");
  if(sec<10)
    lcd.print("0");
  lcd.print(sec);
}

void printTemp()
{
  s = analogRead(A0);        
  temp = (double)s / 1024;   
  temp = temp * 5;                     
  temp = temp - 0.5;                  
  temp = temp * 100; 
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.print((char)176);
  lcd.print("C");
}

void printGas()
{
  g = analogRead(A1);
  p = (float)g/1024*100;
  Serial.println(g);
  lcd.print(p);
  lcd.print("%");
}