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
byte colPins[COLS] = {13,12,11,10};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int detected=0;
int correct=1025;    // the correct password
int read=0, n_read=0;

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  pinMode(1,OUTPUT);
}

void loop()
{
  if(detected==0 && digitalRead(A4)==HIGH)
  {
    lcd.clear();
    lcd.print("Password : ");
    detected=1;
    
  }
  if(detected==1 && n_read<4)
  {
    char key = keypad.getKey();
  	if(key)
  	{
        read = read*10 + key-'0';
      	n_read++;
    	lcd.print('*');
 	}
  }
  if(n_read==4)
  {
    lcd.setCursor(0,1);
    if(read==correct)
    {
      lcd.print("Welcome!");
      delay(1000);
      lcd.clear();
    }
    else
    {
      lcd.print("Intruder!");
      for(int i=0;i<5000000;i++)
      	digitalWrite(1,HIGH);
    }
    read=0;
    n_read=0;
  }
   
}