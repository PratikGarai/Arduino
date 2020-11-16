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
int t1,t2,t3,t,tp,paused;

int controls[] = {13,12,3};
void setup()
{
  for(int i=0;i<8;i++)
  {
  	pinMode(segPins[i], OUTPUT);
  }
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,INPUT);
  pinMode(0,INPUT);
  paused = 0;
  showTime(0,0,0);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(0)==HIGH)
  {
    paused = 0;
  }
  if(digitalRead(0)==LOW)
  {
    paused = 1;
  }
  if(paused==0)
  	tp = tp+1;
  if(digitalRead(2)==HIGH)
    tp = 0;
  if(tp%10==0)
  {
  t = tp/10;
  t1 = t%10;
  t = t/10;
  t2 = t%10;
  t = t/10;
  t3 = t%10;
  }
  delay(10);
  showTime(t3,t2,t1);
}

void showTime(int a , int b, int c)
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(3,LOW);
  display(a);
  delay(5);
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(3,LOW);
  display(b);
  delay(5);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(3,HIGH);
  display(c);
  delay(5);
}

void display(int d)
{
  for(int i=0;i<8;i++)
    digitalWrite(segPins[i], segCode[d][i]);
}