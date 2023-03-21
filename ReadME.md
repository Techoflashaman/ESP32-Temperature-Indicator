
# ESP32 Based Temperature Indication using an LED

This project work on when the temprature value crosses the thresold limit which we set (25), then the LED is "ON". We use DHT11 sensor.



## Components Used


1. ESP32 Dev kit
2. LED
3. DHT11 Sensor
4. 4.7K Resistor
5. Power Supply 

## Schematic 

<img src="https://firebasestorage.googleapis.com/v0/b/esp32-temp-indicator.appspot.com/o/schematic.PNG?alt=media&token=370718b6-3ec2-47f0-af1c-cd0009cbfbda"></img>

## Result

<img src="https://firebasestorage.googleapis.com/v0/b/esp32-temp-indicator.appspot.com/o/Img4.jpeg?alt=media&token=d3819ef9-109a-4ecb-816b-d31f372b1423"></img>

<img src="https://firebasestorage.googleapis.com/v0/b/esp32-temp-indicator.appspot.com/o/Img1.jpeg?alt=media&token=c97011a8-fa8f-4727-9a05-0fdfa2e015b9"></img>

<img src="https://firebasestorage.googleapis.com/v0/b/esp32-temp-indicator.appspot.com/o/Img3.jpeg?alt=media&token=797c55c8-9fe9-452c-a3ff-fb957b74c928"></img>

<img src="https://firebasestorage.googleapis.com/v0/b/esp32-temp-indicator.appspot.com/o/Img2.jpeg?alt=media&token=ea925b81-c11a-4df3-a456-c8fcc991c12f"></img>









## Code 

```javascript
/*
* Author : Mohd Aman Ansari
* embed
* https://embed.org.in
*/

#include <WiFi.h>   //Include Library WiFi.h
#include <DHT.h>    //Include Library DHT.h

#define DHTPIN 15
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

