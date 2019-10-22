#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

// Code for HiPEAC Student Challenge VII, Bilbao, 28-30 October 2019

#include "DHT.h"
#include <SPI.h>
#include "RF24.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define SOILPIN1 A0   // Analog pin connected to the soil moisture sensor
#define SOILPIN2 A1   // Analog pin connected to the soil moisture sensor

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);
RF24 radio(9, 10);

byte addresses[6] = "1Node";
char temp[32];

int message_counter = 0;

void transmitMeasurements(int m1, int m2, int h, int t) {
  sprintf(temp, "%d, %d, %d, %d, %d\n", message_counter++, m1, m2, h, t);
  radio.write(temp, 64);
  Serial.println(temp);
}

int convertToPercent(int value) {
  int percentValue = 0;
  percentValue = map(value, 1023, 465, 0, 100);
  return percentValue;
}

void setup() {
  Serial.begin(9600);
  Serial.println(F("Hello World!\n"));
  dht.begin();
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(addresses);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  int t = dht.readTemperature();
  // Read soil humidity in percentage
  int m1 = analogRead(SOILPIN1);
  // Read soil humidity in percentage
  int m2 = analogRead(SOILPIN2);

  /*
  //float pt1 = map(m1,550,150,0,100);  //Map value : 400 will be 100 and 1023 will be 0
  float pt1 = map(m1,960,200,0,100);  //Map value : 400 will be 100 and 1023 will be 0
  float pt2 = map(m2,960,200,0,100);  //Map value : 400 will be 100 and 1023 will be 0

  Serial.print("Raw 1: ");
  Serial.println(m1);
  Serial.print("Raw 2: ");
  Serial.println(m2);
  
  Serial.print("Percent 1: ");
  Serial.println(pt1);
  Serial.print("Percent 2: ");
  Serial.println(pt2);
  */
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Check if any reads failed and exit early (to try again).
  if (isnan(m1) || isnan(m2)) {
    Serial.println(F("Failed to read from soil moisture sensor!"));
    return;
  }

  // Print results in monitor
  Serial.print(F("\n\nMoisture1: "));
  Serial.print(m1);
  Serial.print(F("  Moisture2: "));
  Serial.print(m2);
  Serial.print(F("  Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(F("\nTransmitting through nRF24 module...\n"));
  transmitMeasurements(m1, m2, h, t);
}
