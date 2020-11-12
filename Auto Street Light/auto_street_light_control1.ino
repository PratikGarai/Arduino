// Relay connects the circuit if given a voltage... and disconnects if not
// We'll use PIN 2 to give that control voltage
void setup()
{
  pinMode(2, OUTPUT);
}

void loop()
{
  int v = analogRead(A0);
  if(v>300)
    digitalWrite(2,LOW);
  else
    digitalWrite(2,HIGH);
  delay(100);
}