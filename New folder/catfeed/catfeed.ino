
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiManager.h>
#define BLYNK_PRINT Serial

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

char blynk_token[] = "";

Servo myservo;
int nut;
const int servoPin = 9;

WidgetLCD lcd(V0);
BLYNK_WRITE(V1)
{
   nut = param.asInt();
}


void setup() {
  
  
  WiFiManager wifiManager;
   WiFiManagerParameter custom_blynk("Blynk", "blynk token", blynk_token,34);
   wifiManager.addParameter(&custom_blynk);
   
   wifiManager.autoConnect("Stupid cat feed (^..^)");
  Blynk.config(custom_blynk.getValue());
  
  myservo.attach(servoPin);
  myservo.write(180);
  delay(1000);
  myservo.detach();
}

void loop(){
  Blynk.run();
  lcd.clear();
    if(nut == 1) {
    myservo.attach(servoPin);
    myservo.write(30);
    delay(575);
    myservo.write(180);
    delay(1500);
    myservo.detach();
    lcd.print(0, 0, "Da cho meo an ^.-.^" );
    delay(5000);
  }
  delay(100);
  }
