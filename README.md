# Basic-Plant-Watering-System 🌱
This is a basic plant watering system created on Arduino Uno using DHT11 Temperature and Humidity sensor.

DHT Sensor Library and Adafruit Unified Sensor libraries must be installed on Arduino IDE, because DHT sensors need them.
With the help of these libraries, temperature, heat index, and humidity can be calculated easily. 

In this project a water pump is created using a DC motor. When the motor is started, it pumps water to the plant. The motor starts or stops according to the heat index. 

_The heat index (HI) is an index that combines air temperature and relative humidity, in shaded areas, to posit a human-perceived equivalent temperature, as how hot it would feel if the humidity were some other value in the shade._ 

* If heat index is lower than 20 Celsius, the motor does not start.
* If heat index is between 20 and 25 Celsius, the motor starts with speed of 150 and pumps water for a few seconds. 
* If heat index is higher, the motor starts with speed of 200 and pumps water for a few seconds.

A counter is used to reduce the number of engine starts to avoid over-watering the plant. 

# Circuit Elements
The basic circuit elements that are used in the Basic Plant Watering System.
* Breadboard
* Arduino Uno
* Jumpers
* DHT11 Temperature and Humidity sensor
* 1N4007 Diode
* NPN Transistor
* 2 resistors including a 470K ohm and a 1K ohm

