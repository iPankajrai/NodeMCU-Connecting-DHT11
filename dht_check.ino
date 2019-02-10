
#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT11


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");

  dht.begin();
}

void loop() 
{
  
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f))      // isnan ==> "is not a number"...returns 1 if " h  or t or f are not a number"     
    {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(" %\n");
  delay(2000);
 
}

