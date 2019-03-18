int charger = 2, laptopcharger = 3, lamp = 4, extra = 5;int a,b;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int data;
  data = Serial.read();
  if(data=='F')
  {
   a=1;
    }
    if(data=='B')
  {
   a=0;
   }
   if(a==1)
   {
     digitalWrite(charger,HIGH);
   }
    else 
    digitalWrite(charger,LOW);
   
 if(data=='G')
  {
    b=0;}
    if(data=='L')
  {
    b=1;
    }
    if(b==1)
   {
     digitalWrite(lamp,HIGH);
   
    }
    else 
    digitalWrite(lamp,LOW);
}
