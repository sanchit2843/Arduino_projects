
#include <LiquidCrystal.h>
int hour=0,minut=0,second=0,timer=0,set,change,t=0,alarmh=5,alarmm=0,off = 10,buzzer=8,hourinp=0,minutinp=0,se=7,chang=6,alarm=0,flag=0,flag1=0,x,flag2=0,l=0,flag3;
String a= "am" , b="pm" ,c;
int pot1=A0,pot2=A1;
LiquidCrystal led (12,11,5,4,3,2);
void setup() {
led.begin(16,2);
pinMode(pot1,INPUT);
pinMode(pot2,INPUT);
pinMode(se,INPUT);
pinMode(chang,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}
void loop() {
second++;
flag1=0;
flag3=0;

timer++;
x=timer/3600;
if(timer==24)
{
  timer=0;
  flag=0;
  }
  
set=digitalRead(se);
change=digitalRead(chang);
if(second==60)
 {
  minut++;
  second = 0;
  }
 if(minut==60)
 {
  hour++;
  minut = 0;
  if(hour<=12 && flag==0)
  {
    c=a;
    }
  if (hour ==13)
    {
      hour=1;
      c=b;
      flag++;
    }   
  }
if(change == 1)
{
  t++;
  }
  
  if (set == 1)
  {
    l++;
    }
//Serial.print(change);
    while(t==1)
    {
          hourinp=analogRead(pot1);
          hourinp=hourinp-20;
          Serial.println(hourinp);
      int i=hourinp/40;
    for(int j=0;j<24;j++)
        {
          if(i==j)
            {
              hour = i;
              if(i==0)
              {
                hour=12;
                }
              }
              if(i<12)
              {
                c=a;
            
              }   
              if(i==12)
              {
                hour=12;
                c=b;
                }
              if(i>12)
              {
                c=b;
                hour=i-12;
                //flag++;
              }   
              
        }
                
        
        
              minutinp=analogRead(pot2);
      int k=minutinp/17;
      for(int j=0;j<61;j++)
        {
          if(k==j)
            {
              minut = k;
              }
        } 
        if(flag1==0){ 
delay(1000);}
flag1++;
change=digitalRead(chang);
  
//Serial.println(change);
       
       if (change == 1)
  {
    t=0;
    }
led.clear();
led.setCursor(0,0);
led.print("Time:");
led.print(hour);
led.print(":");
led.print(minut);
led.print(" ");
led.print(c);
}
     
 while (l==1)
      {
         hourinp=analogRead(pot1);
      int i=hourinp/42;
      for(int j=0;j<24;j++)
        {
          if(i==j)
            {
              alarmh = i;
              if(i==0)
              {
                alarmh=12;
                }
              }
              if(i<12)
              {
                c=a;
            
              }   
              if(i==12)
              {
                alarmh=12;
                c=b;
                }
              if(i>12)
              {
                c=b;
                alarmh=i-12;
                //flag++;
              }   
              
        }
        
              minutinp=analogRead(pot2);
      int k=minutinp/17;
      for(int j=0;j<60;j++)
        {
          if(k==j)
            {
              alarmm = k;
              }
        }    
        
        if(flag3==0){ 
delay(1000);
} 
flag3++;
set=digitalRead(se);
        if (set == 1)
  {
    l=0;
    }
    
//delay(500);

led.clear();
led.setCursor(0,0);
led.print("alarm:");
led.print(alarmh);
led.print(":");
led.print(alarmm);
led.print(" ");
led.print(c);
  }
  
if(alarmh==hour && alarmm==minut && flag2==0)
{
alarm=1;
}
if(alarmh==hour && alarmm==(minut+1))
{
flag2=0;
}
while (alarm==1)
{
  second++;
  if(second==60)
 {
  minut++;
  second = 0;
  }
 if(minut==60)
 {
  hour++;
  minut = 0;}
  if(hour<=12 && flag==0)
  {
    c=a;
    }
  if (hour ==13)
    {
      hour=1;
      c=b;
      flag++;
    }   

    delay(1000);
  int of=0;
  of=digitalRead(se);
  digitalWrite(buzzer,HIGH);
  if(of==1)
  {
    alarm=0;
    flag2++;
    }

led.clear();
led.setCursor(0,0);
led.print(hour);
led.print(":");
led.print(minut);
led.print(":");
led.print(second);
led.print("  ");
led.print(c);
}

  digitalWrite(buzzer,LOW);
delay(994);

led.clear();
led.setCursor(0,0);
led.print(hour);
led.print(":");
led.print(minut);
led.print(":");
led.print(second);
led.print("  ");
led.print(c);

}               
