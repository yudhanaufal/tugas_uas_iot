#define BLYNK_TEMPLATE_ID "TMPL6VxqfitB0"
#define BLYNK_TEMPLATE_NAME "coba"
#define BLYNK_AUTH_TOKEN "yikj18_yP8Tn70rzFjBYTp_LxwwGMXDU"
#define BLYNK_PRINT SwSerial
#include <SoftwareSerial.h>

SoftwareSerial SwSerial(10, 11); 
#include <BlynkSimpleStream.h>
#include <DHT.h>
char auth[] = BLYNK_AUTH_TOKEN;

#define DHTPIN 2
#define DHTTYPE DHT11       // DHT 11
// #define DHTTYPE DHT22    // DHT 22, AM2302, AM2321
// #define DHTTYPE DHT21    // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
int h;
int t;
// unsigned long starMillisReadData;
// int sencondsDisplay = 500;

void sendSensor(){
  h = dht.readHumidity();
  t = dht.readTemperature();
//}
//void readValue()
//{
  Blynk.virtualWrite(V1, h); 
  Blynk.virtualWrite(V0, t); 
}

void setup(){ //inisialisasi
  SwSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  dht.begin();
  timer.setInterval(1000L,sendSensor); 
}

void loop()
{
  Blynk.run();
  timer.run();
  sendSensor();
}