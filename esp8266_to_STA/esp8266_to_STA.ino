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

// MQTT Connection Details for SensorThings API
const char* sta_server = "ENTER_YOUR_IP_ADDRESS";
const int sta_port = 1883;
const char* temp_topic = "v1.1/Datastreams(temperature_readings_1)/Observations";
const char* hum_topic = "v1.1/Datastreams(humidity_readings_1)/Observations";

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
  client.setServer(sta_server, sta_port);

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

// Publish temperature readings to SensorThings API
void publishTemperature(float tempC) {
  if (!client.connected()) {
    reconnect();
  }

  String phenomenonTime = getISO8601Time();
  String resultTime = phenomenonTime;

  String jsonPayload = "{";
  jsonPayload += "\"phenomenonTime\": \"" + phenomenonTime + "\",";
  jsonPayload += "\"resultTime\": \"" + resultTime + "\",";
  jsonPayload += "\"result\": " + String(tempC);
  jsonPayload += "}";

  Serial.print(client.state());
  client.publish(temp_topic, jsonPayload.c_str());
}

// Publish humidity readings to SensorThings API
void publishHumidity(float hum) {
  if (!client.connected()) {
    reconnect();
  }

  String phenomenonTime = getISO8601Time();
  String resultTime = phenomenonTime;

  String jsonPayload = "{";
  jsonPayload += "\"phenomenonTime\": \"" + phenomenonTime + "\",";
  jsonPayload += "\"resultTime\": \"" + resultTime + "\",";
  jsonPayload += "\"result\": " + String(hum);
  jsonPayload += "}";

  Serial.print(client.state());
  client.publish(hum_topic, jsonPayload.c_str());
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float tempC = dht.readTemperature(false);
  float hum = dht.readHumidity();

  if (!isnan(tempC) && !isnan(hum)) {
    Serial.print("Temp: ");
    Serial.print(tempC);
    Serial.println(" C");
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.println(" %");

    // Publish both temperature and humidity data
    publishTemperature(tempC);
    publishHumidity(hum);
  } else {
    Serial.println("Failed to read from DHT sensor!");
  }

  delay(4000);
}
