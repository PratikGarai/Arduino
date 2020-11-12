int s;    
double temp;         
 
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
 
}
void loop() {
  delay(25); 
  s = analogRead(A0);        
  temp = (double)s / 1024;   
  temp = temp * 5;                     
  temp = temp - 0.5;                  
  temp = temp * 100;                   
  Serial.println(temp);
 
}