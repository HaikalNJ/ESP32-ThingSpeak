# ESP32 Temperature and Humidity Monitoring

## Student Information

- Full Name: Omar_Majdi_Hammami
- University ID: 12323569

## Project Description

This project uses an ESP32 and a DHT22 sensor in Wokwi
to measure temperature and humidity.

The ESP32 connects to Wi-Fi and sends both readings
to ThingSpeak approximately every 20 seconds.

Temperature and humidity are displayed using the
built-in ThingSpeak charts.

The university ID is printed in the Serial Monitor.

## Project Links

- ThingSpeak Public Channel: https://thingspeak.mathworks.com/channels/3550044
- Wokwi Project: https://wokwi.com/projects/478889978558340097

## Components

- ESP32
- DHT22

## Wiring

- DHT22 VCC to ESP32 3V3
- DHT22 GND to ESP32 GND
- DHT22 SDA to ESP32 GPIO 15
- DHT22 NC is not connected

![Wiring diagram](screenshots/wiring.png)

## ThingSpeak Fields

- Field 1: Temperature in degrees Celsius
- Field 2: Humidity in percent

## Libraries

- DHT sensor library for ESPx
- ThingSpeak

## Running the Project

1. Open the Wokwi project.
2. Enter a valid Write API Key in the code.
3. Verify the Channel ID and University ID.
4. Start the simulation.
5. Check the Serial Monitor for result code 200.
6. Open the public ThingSpeak channel to view the charts.

The published source uses a placeholder for the
Write API Key.

## Results

![ThingSpeak charts](screenshots/thingspeak.png)

![Serial Monitor](screenshots/serial.png)