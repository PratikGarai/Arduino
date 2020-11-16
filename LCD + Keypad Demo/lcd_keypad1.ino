#include<Keypad.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(6,7,2,3,4,5);

const byte ROWS = 4;
const byte COLS = 4;
char keys [ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0,A1,A2,A3};
byte colPins[COLS] = {8,9,10,11};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int LCDRow = 0;

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(LCDRow, 0);
}

void loop()
{
  char key = keypad.getKey();
  if(key)
  {
    lcd.print(key);
    lcd.setCursor(++LCDRow, 0);
  }
}