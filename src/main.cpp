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
int a = 0;
int b= 0;
int c= 0;

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
  for ( int a=Firebase.getInt("a"); a >=0; a--) {
    Serial.println(a);
    Firebase.setFloat("Đèn đỏ", a); // gui thay the khong tao chuoi random
    delay(1000);
  }
  Serial.print("\n Den xanh \n");
  green();
  for (int b= Firebase.getInt("b") ; b >=0; b--) {
    Serial.println(b);
    Firebase.setFloat("Đèn xanh", b); // gui thay the khong tao chuoi random
    delay(1000);
  }
  
  Serial.print("\n Den vang\n ");
  yello();
  for (int c =Firebase.getInt("c") ; c >=0; c--) {
    Serial.println(c);
    Firebase.setFloat("Đèn vàng", c); // gui thay the khong tao chuoi random
    delay(1000);
  }



}
