#include<Arduino.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include<ESP8266HTTPClient.h>

// Set these to run example.
#define FIREBASE_HOST "vvvvv-dc879.firebaseio.com"
#define FIREBASE_AUTH "nxmBtoTekhlNsEViv9IIgbl73AVcZaHwVZQj8U82"
#define WIFI_SSID "TATUYÊN"
#define WIFI_PASSWORD "123123123"
int GREEN = 5;
int YELLOW = 4;
int RED = 0;

int i=10;
int b=5;
int c=8;
void setup(){
Serial.begin(9600);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}
void loop(){
     while (i!=0)
  {
    for (i; i>0; i--){
    digitalWrite(GREEN,HIGH);
    digitalWrite(YELLOW,LOW);
    digitalWrite(RED,LOW);
    delay(1000);
    Serial.println(i);
     Firebase.setFloat("Đèn xanh", i); // gui thay the khong tao chuoi random
   
  }};
   while (b!=0)
  {
    for (b; b>0; b--){
    digitalWrite(GREEN,LOW);
    digitalWrite(YELLOW,HIGH);
    digitalWrite(RED,LOW);
    delay(1000);
    Serial.println(b);
    Firebase.setFloat("Đèn vàng", b);
  }};
  while (c!=0)
  {
    for (c; c>=0; c--){
    digitalWrite(GREEN,LOW);
    digitalWrite(YELLOW,LOW);
    digitalWrite(RED,HIGH);
    delay(1000);
    Serial.println(c);
    Firebase.setFloat("Đèn Đỏ", c);
  }};

}