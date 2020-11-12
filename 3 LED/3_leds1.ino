void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
}