
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "DRv8CDrd1KmmEhBpw2OlYcKILgRm9eDb";
char ssid[] = "kim yen";
char pass[] = "02112003";

Servo myservo;
int nut;
const int servoPin = 5;

BLYNK_WRITE(V1)
{
   nut = param.asInt();
}

void setup()
{

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  myservo.attach(servoPin);
  myservo.write(180);
  delay(1000);
  myservo.detach();
}

void loop()
{
  Blynk.run();
  Blynk.virtualWrite(V0, String("(^..^) Moa~"));
    if(nut == 1) { 
    myservo.attach(servoPin);
    myservo.write(30);
    delay(575);
    myservo.write(180);
    Blynk.virtualWrite(V0, String("Nhom nhom nhom"));
    delay(1500);
    myservo.detach();
    delay(5000);
  }
  delay(100);
}
