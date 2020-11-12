char input = ' ';
int set = 0;
void setup()
{
  Serial.begin(9600);
  analogWrite(9, random(0,255));
  analogWrite(10, random(0,255));
  analogWrite(11, random(0,255));
}

void loop()
{
  if(Serial.available()>0)
  {
    set = 1;
  	input = (char)Serial.read();
  }
  
  if(input=='G')
  {
    Serial.println("Grey");
    analogWrite(9,128);
  	analogWrite(10,128);
  	analogWrite(11,128);
    delay(2000);
    input = ' ';
  }
  if(input=='T')
  {
    Serial.println("Teal");
    analogWrite(9,0);
  	analogWrite(10,128);
  	analogWrite(11,128);
    delay(2000);
    input = ' ';
  }
  if(input=='M')
  {
    Serial.println("Maroon");
    analogWrite(9,128);
  	analogWrite(10,0);
  	analogWrite(11,0);
    delay(2000);
    input = ' ';
  }
  if(input=='O')
  {
    Serial.println("Orange");
    analogWrite(9,255);
  	analogWrite(10,165);
  	analogWrite(11,0);
    delay(2000);
    input = ' ';
  }
  if(input=='P')
  {
    Serial.println("Purple");
    analogWrite(9,128);
  	analogWrite(10,0);
  	analogWrite(11,128);
    delay(2000);
    input = ' ';
  }
  if(set==1)
  {
    Serial.println("Random");
    set = 0;
    analogWrite(9, random(0,255));
  	analogWrite(10, random(0,255));
  	analogWrite(11, random(0,255));
  }
}