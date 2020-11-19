#include<LiquidCrystal.h>
#include<Servo.h>

LiquidCrystal lcd(6,7,2,3,4,5); 
int diff, slots = 5, trig = 13, echo = 12, timeduration, distance, last_distance;
Servo servo;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Smart Parking!");
  lcd.setCursor(0,1);
  lcd.print("Slots left :");
  lcd.print(slots);
  servo.attach(10);
  servo.write(0);
  delay(50);
  distance = last_distance = scan();
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop()
{
  digitalWrite(8,LOW);
  diff = distance-last_distance;
  if((diff>0 && diff>20)||(diff<0 && diff<-20))
  {
    last_distance = distance;
    do_stuff();
  }
  distance = scan();
  Serial.println(distance);
  delay(100);
}

float scan()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  timeduration = pulseIn(echo, HIGH);
  return 0.034*timeduration/2;
}

void do_stuff()
{
  if(slots==0)
  {
    lcd.clear();
    lcd.print("No slots left!");
    for(int i=0;i<50;i++)
    {
      digitalWrite(8,HIGH);
      delay(100);
    }
    lcd.clear();
    lcd.print("Smart Parking!");
  }
  else
  {
    slots--;
    lcd.clear();
    lcd.print("Welcome!");
    lcd.setCursor(0,1);
    lcd.print("Slots left :");
    lcd.print(slots);
    open_close();
    lcd.clear();
    lcd.print("Smart Parking!");
  }
  delay(1000);
}

void open_close()
{
  for(int i=0;i<90;i++)
    {
      servo.write(i);
      delay(20);
    }
    delay(1000);
    for(int i=90;i>=0;i--)
    {
      servo.write(i);
      delay(20);
    }
}