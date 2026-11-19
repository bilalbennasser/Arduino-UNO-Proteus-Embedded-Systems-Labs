#include <DHT.h>

DHT dht(2, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  float humidite = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidite) || isnan(temperature)) {
    Serial.println("Erreur de lecture DHT11");
    return;
  }

  Serial.print("Temperature = ");
  Serial.print(temperature, 1);
  Serial.print(" C   Humidite = ");
  Serial.print(humidite, 1);
  Serial.println(" %");
}