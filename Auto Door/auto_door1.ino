// If someone is at the door, open it for 3 seconds 
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop()
{
  int v = digitalRead(3);
  if(v==HIGH)
  {
    digitalWrite(2,HIGH);
    delay(3000);
  }
  digitalWrite(2,LOW);
}