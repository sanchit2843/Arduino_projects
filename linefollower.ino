int motor_right=3,motor_left=5,lir=A0,lcir=A1,cir=A2,rcir=A3,rir=A4,rfir=A5,ledleft=1,ledright=2,trigf=6,echof=7,trigr=8,echor=9;
long sensorAverage;
int sensorSum;
int position;
int proportional=0,integral=0,derivative=0,last_proportional=0;
int setpoint=0,a=0;
float Kp=0.05,Ki=1/10000,Kd=1.5;
int right_speed,left_speed,max_speed=255;
int duration1,duration2,distance1,distance2;
int error_value=0;
long sensors[]={0,0,0,0,0,0};
void setup() {
 pinMode(motor_right,OUTPUT);
 pinMode(motor_left,OUTPUT);
 pinMode(lir,INPUT);
 pinMode(lcir,INPUT);
 pinMode(cir,INPUT);
 pinMode(rir,INPUT);
 pinMode(rcir,INPUT);
 pinMode(rfir,INPUT);
 pinMode(ledleft,OUTPUT);
 pinMode(ledright,OUTPUT);
 pinMode(trigf,OUTPUT);
 pinMode(trigr,OUTPUT);
 pinMode(echof,INPUT);
 pinMode(echor,INPUT);
 
 }

void loop() {
digitalWrite(ledleft,LOW);
digitalWrite(ledright,LOW);
digitalWrite(trigf,LOW);
delay(5);
digitalWrite(trigf,HIGH);
delay(10);
duration1= pulseIn(echof, HIGH);
distance1 = (duration1/2) / 29.1;
if(distance1<=10)
{
 a=1; 
}
while(a=1)
{
  follow_obstacle();
  }
sensor_value();
pid_calc();
calc_turn();
motor_drive(right_speed,left_speed);
}
void sensor_value()
{
  sensorAverage=0;
sensorSum=0;
for(int i=0;i<6;i++)
{
  sensors[i]=analogRead(i);
  sensorAverage=sensorAverage+sensors[i]*i*1000;
  sensorSum=sensorSum+int(sensors[i]);
}
if(2825000<sensorAverage<3325000 || 6625000<sensorAverage<7125000)
{
  sensorAverage=171000;
  sensorSum = 1860;
  }
if(7325000<sensorAverage<7825000)
{
  sensorAverage=6120000;
  sensorSum=7590;
  }
  }
void pid_calc()
{
  position = int(sensorAverage/sensorSum);
  proportional = position-setpoint;
  integral = integral+proportional;
  derivative = proportional-last_proportional;
  last_proportional = proportional;
  error_value = int(proportional*Kp+derivative*Kd+integral*Ki);
  //messeage 'hello sanchit' after reading this program in techfest group and don't tell anyone else why you have written that message
  }
  void calc_turn()
  {
    if(error_value<-256)
    {
      error_value=-256;
      }
      if(error_value>256)
    {
      error_value= 256;
      }

      if(error_value<0)
      {
        right_speed = max_speed+error_value;
        left_speed = max_speed;
        digitalWrite(ledright,HIGH);
        }
        else
        {
        right_speed = max_speed;
        left_speed = max_speed-error_value;
        digitalWrite(ledleft,HIGH);
          }
          if(sensorAverage>10000000)
    {
      right_speed=0;
      left_speed=0;
      }
    }
    void motor_drive(int right_speed,int left_speed)
    {
      analogWrite(motor_right,right_speed);
      analogWrite(motor_left,left_speed);  
      }
      void ultrasonic_value()
      {
        sensor_value();
        pid_calc();
  position = int(sensorAverage/sensorSum);
        digitalWrite(trigf,LOW);
delay(5);
digitalWrite(trigf,HIGH);
delay(10);
duration1= pulseIn(echof, HIGH);
distance1 = (duration1/2) / 29.1;
digitalWrite(trigr,LOW);
delay(5);
digitalWrite(trigr,HIGH);
delay(10);
duration2= pulseIn(echor, HIGH);
distance2 = (duration2/2) / 29.1;
        }
 void follow_obstacle()
      { 
        ultrasonic_value();
if(distance1<=10)
{
  digitalWrite(motor_right,HIGH);
  digitalWrite(motor_left,LOW);
  }
if(distance2<=15)
{
  digitalWrite(motor_right,HIGH);
  digitalWrite(motor_left,HIGH); 
  }
  if(distance2<=6)
{
  digitalWrite(motor_right,HIGH);
  analogWrite(motor_left,200); 
  }
  if(distance1>15 && distance2>15 && proportional<0)
  {
    digitalWrite(motor_left,HIGH); 
  analogWrite(motor_right,150);
    }
    if(distance1>15 && proportional>0)
    {
      a=0;
      }
      
        }
