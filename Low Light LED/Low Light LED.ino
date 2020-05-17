int ldr;
int state = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(2,OUTPUT);
}

void loop()
{
  ldr = analogRead(A0);
  if(ldr<100 && state==0)
  {
    digitalWrite(2,HIGH);
    state = 1;
  }
  if(ldr>=100 && state==1)
  {
    digitalWrite(2,LOW);
    state = 0;
  }
  Serial.println(ldr);
  delay(25);
}