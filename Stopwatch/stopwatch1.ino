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
int counter = 0;
int paused = 0;
long timer = 0;

void setup()
{
  int i;
  for(i=0;i<8;i++)
  {
  	pinMode(segPins[i], OUTPUT);
  }
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}

void loop()
{
  displayDigit(counter);
  if(digitalRead(3)==HIGH)
  {
  	counter = 0;
    timer = 0;
  }
  else if(digitalRead(2)==HIGH)
  {
    if(paused==0)
      paused = 1;
    else
      paused = 0;
  }
  if(paused==0 && timer==2500)
  {
  	counter = counter + 1;
    if(counter==10)
    	counter = 0;
    timer = 0;
  }
  if(paused==0)
    timer += 1;
}

void displayDigit(int d)
{
  int i;
  for(i=0;i<8;i++)
  {
    digitalWrite(segPins[i], segCode[d][i]);
  }
}
