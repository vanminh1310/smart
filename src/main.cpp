#include<Arduino.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include<ESP8266HTTPClient.h>

// Set these to run example.
#define FIREBASE_HOST "vvvvv-dc879.firebaseio.com"
#define FIREBASE_AUTH "nxmBtoTekhlNsEViv9IIgbl73AVcZaHwVZQj8U82"
#define WIFI_SSID "Joy"
#define WIFI_PASSWORD "012345678"
int rd = 5;
int gr = 4;
int yl = 0;

void setup() {
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
  pinMode(rd, OUTPUT);
  pinMode(gr, OUTPUT);
  pinMode(yl, OUTPUT);
  Serial.print("Traffic Light");
}
void red() {
  digitalWrite(rd, HIGH);
  digitalWrite(yl, LOW);
  digitalWrite(gr, LOW);
}
void green() {
  digitalWrite(rd, LOW);
  digitalWrite(gr, HIGH);
  digitalWrite(yl, LOW);
}
void yello() {
  digitalWrite(rd, LOW);
  digitalWrite(gr, LOW);
  digitalWrite(yl, HIGH);
}

void loop() {
  Serial.print("\n Den do \n");
  red();
  for (int i = 15; i >=0; i--) {
    Serial.println(i);
    Firebase.setFloat("Đèn đỏ", i); // gui thay the khong tao chuoi random
    delay(1000);
  }
  Serial.print("\n Den xanh \n");
  green();
  for (int i = 10; i >=0; i--) {
    Serial.println(i);
    Firebase.setFloat("Đèn xanh", i); // gui thay the khong tao chuoi random
    delay(1000);
  }
  
  Serial.print("\n Den vang\n ");
  yello();
  for (int i = 5; i >=0; i--) {
    Serial.println(i);
    Firebase.setFloat("Đèn vàng", i); // gui thay the khong tao chuoi random
    delay(1000);
  }



}
