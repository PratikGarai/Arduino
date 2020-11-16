int trig = 2;   // can be a digital only pin
int echo = 3;   // has to be a PWM
float timeduration, distance;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  timeduration = pulseIn(echo, HIGH);   // finds the time of pulse in pin 
  // in this case LOW-HIGH-LOW pulse
  distance = 0.034*timeduration/2;
  Serial.print("Distance in cm : ");
  Serial.println(distance);
  delay(100);
}