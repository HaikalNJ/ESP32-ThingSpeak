#include <WiFi.h>
#include <DHTesp.h>
#include <math.h>
#include <ThingSpeak.h>


const char* ssid = "Wokwi-GUEST";
const char* password = "";

const unsigned long channelID = 3550044;
const char* writeAPIKey = "YOUR_WRITE_API_KEY";
const char* universityID = "12323569";

const int dhtPin = 15;
const unsigned long updateInterval = 20000;


DHTesp dht;
WiFiClient client;


void connectWiFi() {
    if (WiFi.status() == WL_CONNECTED) {
        return;
    }

    Serial.print("Connecting to WiFi");

    WiFi.begin(ssid, password, 6);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi connected.");
}


void setup() {
    Serial.begin(115200);

    dht.setup(dhtPin, DHTesp::DHT22);

    WiFi.mode(WIFI_STA);
    connectWiFi();

    ThingSpeak.begin(client);

    delay(2000);
}


void loop() {
    connectWiFi();

    TempAndHumidity data = dht.getTempAndHumidity();

    if (isnan(data.temperature) || isnan(data.humidity)) {
        Serial.println("Failed to read the DHT22 sensor.");
        delay(2000);
        return;
    }

    Serial.println("----------------");

    Serial.print("University ID: ");
    Serial.println(universityID);

    Serial.print("Temperature: ");
    Serial.print(data.temperature, 1);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(data.humidity, 1);
    Serial.println(" %");

    ThingSpeak.setField(1, data.temperature);
    ThingSpeak.setField(2, data.humidity);

    int result = ThingSpeak.writeFields(channelID, writeAPIKey);

    Serial.print("Result code: ");
    Serial.println(result);

    if (result == 200) {
        Serial.println("Data sent successfully.");
    } else {
        Serial.println("Failed to send data to ThingSpeak.");
    }

    delay(updateInterval);
}