int segPins[] = {4,5,7,8,9,11,10,6}; //{a b c d e f g .}
int segCode[16][8] = {
  // a,b,c,d,e,f,g,.
  	{0,0,0,0,0,0,1,1},  // 0
    {1,0,0,1,1,1,1,1},  // 1
    {0,0,1,0,0,1,0,1},  // 2
    {0,0,0,0,1,1,0,1},  // 3
    {1,0,0,1,1,0,0,1},  // 4
    {0,1,0,0,1,0,0,1},  // 5
    {0,1,0,0,0,0,0,1},  // 6
    {0,0,0,1,1,1,1,1},  // 7
    {0,0,0,0,0,0,0,1},  // 8
    {0,0,0,0,1,0,0,1},  // 9
    {0,0,0,0,0,1,0,1},  // a
    {1,1,0,0,0,0,0,1},  // b
    {0,1,1,0,0,0,1,1},  // c
    {1,0,0,0,0,1,0,1},  // d
    {0,0,1,0,0,0,0,1},  // e
    {0,1,1,1,0,0,0,1}   // f
};

int people = 0;

void setup()
{
  for(int i=0;i<8;i++)
  {
  	pinMode(segPins[i], OUTPUT);
  }
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(3,OUTPUT);
  displayDigit(people);
}

void loop()
{
  if(digitalRead(12)==HIGH)
  {
    if(people!=0)
    {
    	people--;
    }
  }
  if(digitalRead(13)==HIGH)
  {
    if(people!=9)
    {
    	people++;
    }
    else
    {
    	digitalWrite(3,HIGH);
    }
  }
    
  displayDigit(people);
  delay(1000);
}

void displayDigit(int d)
{
  int i;
  for(i=0;i<8;i++)
  {
    digitalWrite(segPins[i], segCode[d][i]);
  }
}