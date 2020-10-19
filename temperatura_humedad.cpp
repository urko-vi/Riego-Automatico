#include <Arduino.h>
#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
const int DHTPin = 5;
DHT dht(DHTPin, DHTTYPE);

void setup_sensor_temperatura_humedad(){
	dht.begin();
}
float medir_temperatura(){
   float t = dht.readTemperature();
   if (isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return 0.0;
   }
   return t;
}
float medir_humedad(){
	float h = dht.readHumidity();
	if (isnan(h)) {
      Serial.println("Failed to read from DHT sensor!");
      return 0.0;
   }
	return h;
}