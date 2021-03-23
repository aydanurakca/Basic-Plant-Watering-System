#include "DHT.h"

#define DHTPIN 2     // The sensor is connected to the 2nd pin of arduino
#define MOTORPIN 3   // The motor is connected to the 3rd pin of arduino

#define DHTTYPE DHT11   // DHT 11 is the sensor that is used
int counter = 1; // This is for counting the number of times that loop() is iterated. When counter % 10 equals to zero, motor pumps water.

// Initializing DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHT11 test!");

  pinMode(MOTORPIN, OUTPUT);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  float humidity = dht.readHumidity();
  // Read temperature as Celsius
  float temperature = dht.readTemperature(false);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Computing heat index as Celsius
  float heatindex = dht.computeHeatIndex(temperature, humidity, false);

  Serial.print("Humidity: "); 
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(temperature);
  Serial.print(" *C ");
  Serial.print("Heat index: ");
  Serial.print(heatindex);
  Serial.println(" *C");

  if(heatindex < 20) 
  {
  analogWrite(MOTORPIN,0); //if heat index is less than 20 C, the motor stops.
  }
  else if(heatindex > 20 && heatindex < 25)
  {
    counter++;
    if(counter % 10 == 0){
      
      analogWrite(MOTORPIN,150); //if heat index is less than 25 C and more than 20 C, the motor runs with the speed of 150 and pumps water.
      Serial.println("Motor Runs with Speed of 150 and pumps water");
      delay(10000); 
      analogWrite(MOTORPIN,0);
    }
  }
  else
  {
    counter++;
    if(counter % 10 == 0){
      
      analogWrite(MOTORPIN,200); //if heat index is more than 25 C, the motor runs with the speed of 200 and pumps water faster.
      Serial.println("Motor Runs with Speed of 200 and pumps water"); 
      delay(10000);
      analogWrite(MOTORPIN,0);
    }
  }
  delay(1000); //Wait for few second and then continue the loop.
}
