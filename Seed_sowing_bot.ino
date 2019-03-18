#include <Servo.h>
int lir,rir,bir,lmotor1=1,rmotor1=3,lmotor2=2,rmotor2=4,bmotor=5,c =6,d=7,e=8;
Servo servo1;
void setup() {
  pinMode(lir,INPUT);
  pinMode(rir,INPUT);
    pinMode(bir,INPUT);  
    pinMode(lmotor1,OUTPUT);   
    pinMode(rmotor1,OUTPUT);   
    pinMode(lmotor2,OUTPUT);   
    pinMode(rmotor2,OUTPUT);
    servo1.attach(bmotor);
   // Serial.begin(9600);
}
void loop() {
 lir = digitalRead(c);
  rir = digitalRead(d);
  bir = digitalRead(e);
 // Serial.print(rir);
if(lir ==1 && rir==1)
{
  digitalWrite(lmotor1,HIGH);
  digitalWrite(rmotor1,HIGH);
  digitalWrite(lmotor2,LOW);
  digitalWrite(rmotor2,LOW);
  }
if(lir ==0 && rir==1)
{
  digitalWrite(lmotor1,LOW);
  digitalWrite(rmotor1,HIGH);
  digitalWrite(lmotor2,LOW);
  digitalWrite(rmotor2,LOW);
  }
if(lir ==1 && rir==0)
{
  digitalWrite(lmotor1,HIGH);
  digitalWrite(rmotor1,LOW);
  digitalWrite(lmotor2,LOW);
  digitalWrite(rmotor2,LOW);
  }
if(lir ==0 && rir==0)
{
  digitalWrite(lmotor1,LOW);
  digitalWrite(rmotor1,LOW);
  digitalWrite(lmotor2,LOW);
  digitalWrite(rmotor2,LOW);
  }
if(bir == 0)
{
  servo1.write(50);
  delay(100);
  servo1.write(0);
  }
}
