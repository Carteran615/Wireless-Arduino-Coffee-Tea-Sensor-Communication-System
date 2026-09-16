

// Pairing and sending process adapted from:
// https://www.youtube.com/watch?v=U8ogrhu3qWo&t=1s


#include "Arduino_Bluetooth_Link_TX.h"
#include <SoftwareSerial.h>
#include "DHT.h"

SoftwareSerial sws(2, 3);

// pin 7
DHT dht(7, DHT11);

float humidity, celsius;

void setup()
{
	Serial.begin(9600);
	sws.begin(38400);
	Serial.println("TX Setup Completed.");
  dht.begin();
}

void loop()
{
	humidity = dht.readHumidity();
  celsius = dht.readTemperature();

  // Simple counter
	static unsigned long counter=0;
  
  Serial.print("Sending humidity and celsius: ");
  Serial.print(humidity);
  Serial.print(",");
  Serial.println(celsius);
  sws.print(humidity);
  sws.print(",");
  sws.println(celsius);

	// delay in ms
	delay(2000);
}