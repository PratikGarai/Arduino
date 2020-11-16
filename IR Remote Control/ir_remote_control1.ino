#include <IRremote.h>

IRrecv irrecv(3);
decode_results results;
#define m11 6
#define m12 5
#define m21 11
#define m22 10

void setup()
{
  irrecv.enableIRIn(); 
  Serial.begin(9600);
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results)) 
  { 
    unsigned int value = results.value;
    switch(value)
    {
      case 34935 :
      	Serial.println("UP");
        digitalWrite(m11, HIGH);
      	digitalWrite(m12, LOW);
      	digitalWrite(m21, HIGH);
      	digitalWrite(m22, LOW);
      	break;
      case 26775 :
      	Serial.println("RIGHT");
      	digitalWrite(m11, HIGH);
      	digitalWrite(m12, LOW);
      	digitalWrite(m21, LOW);
      	digitalWrite(m22, LOW);
      	break;
      case 39015 :
      	Serial.println("DOWN");
      	digitalWrite(m11, LOW);
      	digitalWrite(m12, HIGH);
      	digitalWrite(m21, LOW);
      	digitalWrite(m22, HIGH);
      	break;
      case 10455 :
      	Serial.println("LEFT");
      	digitalWrite(m11, LOW);
      	digitalWrite(m12, LOW);
      	digitalWrite(m21, HIGH);
      	digitalWrite(m22, LOW);
      	break;
    }
    irrecv.resume();
  }
}