/*
* Author : Mohd Aman Ansari
* embed
* https://embed.org.in
*/
#include <WiFi.h>   //Include Library WiFi.h
#include <DHT.h>    //Include Library DHT.h

#define DHTPIN 15   // DHT11 Tempreture sensor PIN attach to ESP32 PIN 15   
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Your WiFi credentials
const char* ssid = "************";
const char* password = "***********";

int ledPin = 2; // pin to which the led is connected
float temperatureThreshold = 25; // temperature threshold value

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  pinMode(ledPin, OUTPUT);
}

void loop() {
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println("Failed to read temperature from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (temperature > temperatureThreshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}
