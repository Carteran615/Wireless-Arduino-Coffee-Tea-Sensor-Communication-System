

// Pairing and recieving process adapted from:
// https://www.youtube.com/watch?v=U8ogrhu3qWo&t=1s


#include "Arduino_Bluetooth_Link_RX.h"
#include <SoftwareSerial.h>

SoftwareSerial sws(2, 3);

char buffer[100] = { '\0' };
char humidityBuffer[6] = {0,0,0,0,0,'\0'};
char celsiusBuffer[6] = {0,0,0,0,0,'\0'};
unsigned int bufCnt = 0;
float humidity, celsius, humiditySum, humidityAverage;
float humidityHistory[20] = {
  100, 100, 100, 100, 100,
  100, 100, 100, 100, 100,
  100, 100, 100, 100, 100,
  100, 100, 100, 100, 100};
bool done = false;

void setup()
{
	Serial.begin(9600);
	sws.begin(38400);
	Serial.println("Setup completed.");

  // LED pin 7
  pinMode(7, OUTPUT);
}

void loop()
{
	if (sws.available() && !done)
	{
		// Read the byte of data
		unsigned char btdata = sws.read();

		// End of string?
		if (btdata == 13)
		{
			// Add 'end of string' marker & print it out
			buffer[bufCnt] = '\0';
			
      for (int i=0; i<=4; i++) {
        humidityBuffer[i] = buffer[i];
        celsiusBuffer[i] = buffer[i+6];
      }
      humidity = atof(humidityBuffer);
      celsius = atof(celsiusBuffer);

      // Update humidity history
      humiditySum = humidity;
      humidityAverage = 0;
      for (int i=0; i<19; i++) {
        humidityHistory[i] = humidityHistory[i+1];
        humiditySum += humidityHistory[i];
      }
      humidityHistory[19] = humidity;
      humidityAverage = humiditySum / 20.0;
      Serial.print("humidity average: ");
      Serial.println(humidityAverage);


      Serial.print("Humidity (RH%):  ");
      Serial.println(humidity);
      Serial.print("Temperature (C): ");
      Serial.println(celsius);
      Serial.println();

      // I read somewhere that temp should be 60
      if (humidityAverage > 22) digitalWrite(7, LOW);
      else {
        digitalWrite(7, HIGH);
        done = true;
      }

      bufCnt = 0;
		} else
		{
			// If not a line feed (part of the ENTER key)
			if (btdata != 10)
			{
				buffer[bufCnt] = (char) btdata;
				bufCnt++;
			}
		}
	}
}