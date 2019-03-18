#include <PietteTech_DHT.h>
#include <ESP8266WiFi.h>
#include <CayenneMQTTESP8266.h >
char ssid[] = "OnePlus2";
char password[] = "12345678";
char username[] = "3b3bc610-b718-11e6-82f1-ed3c04eeee58";
char cpassword[] = "12468cd46a49a278117c5a271241d757a2b19a83";
char clientid[] = "78ceae50-0688-11e8-a79c-af045a32c3da";
void dht_wrapper();
float t, h, d;
int acquireresult;
WiFiServer server(80);
PietteTech_DHT DHT(D2,DHT11,dht_wrapper);
void dht_wrapper() {
  DHT.isrCallback();
}
void setup() {
Cayenne.begin(username,cpassword,clientid,ssid,password);
pinMode(2,OUTPUT);
Serial.begin(9600);
pinMode(A0,INPUT);
  Serial.println(WiFi.localIP());
digitalWrite(2,HIGH); 
server.begin();
}

void loop() {  
  acquireresult = DHT.acquireAndWait(1000);
  if ( acquireresult == 0 ) {
    t = DHT.getCelsius();
    h = DHT.getHumidity();
    d = DHT.getDewPoint();
  }
  int b = 390;
Cayenne.virtualWrite(1,t,TYPE_TEMPERATURE,UNIT_CELSIUS);
Cayenne.virtualWrite(2,h,TYPE_RELATIVE_HUMIDITY,UNIT_PERCENT);
//Cayenne.virtualWrite(3,b,"analog_sensor","null");
 Cayenne.loop();
}
CAYENNE_IN(0)
{
int a = !getValue.asInt();
Serial.println(a);
digitalWrite(2,a);
}
