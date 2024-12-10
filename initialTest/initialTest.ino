#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"

#define DPIN 4              // Pin for DHT sensor (GPIO number) D2
#define DTYPE DHT11         // DHT11 sensor type
DHT dht(DPIN, DTYPE);

//Initialising the serial connection and the sensor
void setup() {
  Serial.begin(9600);
  dht.begin();
}

//This loop is continuously executed 
void loop() {

  //Reading temperature and humidity from the sensor
  float tempC = dht.readTemperature(false);
  float hum = dht.readHumidity();

  //Printing the values for temperature and humidity as an output
  if (!isnan(tempC) && !isnan(hum)) {
    Serial.print("Temp: ");
    Serial.print(tempC);
    Serial.println(" C");
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.println(" %");

  } else {
    Serial.println("Failed to read from DHT sensor!");
  }

  //wait 4000 milliseconds before reading the next sensor values
  delay(4000);
}