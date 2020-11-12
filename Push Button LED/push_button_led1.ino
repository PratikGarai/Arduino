void setup()
{
  pinMode(4, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  if(digitalRead(4)==HIGH)
  {
    digitalWrite(2,HIGH);
  	digitalWrite(3,LOW);
    delay(10000);
  }
}