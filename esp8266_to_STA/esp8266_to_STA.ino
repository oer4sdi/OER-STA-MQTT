#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266HTTPClient.h>
#include <time.h>
#include "DHT.h"


#define DPIN 4              // Pin for DHT sensor (GPIO number) D2
#define DTYPE DHT11         // DHT11 sensor type
DHT dht(DPIN, DTYPE);


// WiFi connection details
const char* ssid = "ENTER_YOUR_WIFI_SSID";
const char* password = "ENTER_YOUR_WIFI_PASSWORD";

// MQTT Broker Connection Details for SensorThings API
const char* mqtt_server = "ENTER_YOUR_IP_ADDRESS";
const int mqtt_port = 1883;
const char* mqtt_topic = "v1.1/Datastreams(temperature_readings_1)/Observations";

// WiFi and MQTT client setup
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  // Set MQTT server for SensorThings API
  client.setServer(mqtt_server, mqtt_port);

  // Configure time with NTP servers
  configTime(3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("Time configured");
}

// Reconnect to MQTT broker if disconnected
void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP8266_Client")) {
      Serial.println("Connected to SensorThings MQTT broker");
    } else {
      Serial.print("*");
      Serial.print(client.state());
      delay(5000);  // Retry delay
    }
  }
}

// Get current time in ISO 8601 format
String getISO8601Time() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return "";
  }
 
  char isoTime[25];
  strftime(isoTime, sizeof(isoTime), "%Y-%m-%dT%H:%M:%SZ", &timeinfo);
  return String(isoTime);
}

// Publish to SensorThings API using MQTT with timestamps
void publishToSensorThings(float tempC) {
  if (!client.connected()) {
    reconnect();
  }

  // Obtain phenomenonTime and resultTime in ISO 8601 format
  String phenomenonTime = getISO8601Time();
  String resultTime = phenomenonTime;

  // Construct JSON payload with timestamps
  String jsonPayload = "{";
  jsonPayload += "\"phenomenonTime\": \"" + phenomenonTime + "\",";
  jsonPayload += "\"resultTime\": \"" + resultTime + "\",";
  jsonPayload += "\"result\": " + String(tempC);
  jsonPayload += "}";

  // Publish JSON payload to SensorThings API MQTT topic
  Serial.print(client.state());
  client.publish(mqtt_topic, jsonPayload.c_str());
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Read temperature and humidity
  float tempC = dht.readTemperature(false);
  float tempF = dht.readTemperature(true);   // Temperature in Fahrenheit
  float hum = dht.readHumidity();

  if (!isnan(tempC) || !isnan(tempF) || !isnan(hum)) {
    Serial.print("Temp: ");
    Serial.print(tempC);
    Serial.println(" C, ");
    Serial.print(tempF);
    Serial.print(" F, Hum: ");
    Serial.print(hum);
    Serial.println("%");

    // Publish temperature data to SensorThings API with timestamps
    publishToSensorThings(tempC);
  } else {
    Serial.println("Failed to read from DHT sensor!");
  }

  delay(4000);
}
