

#include <OneWire.h>
#include <DallasTemperature.h>

// линия данных подключена к цифровому выводу 2 Arduino
#define ONE_WIRE_BUS 2

// настройка объекта oneWire для связи с любым устройством OneWire
OneWire oneWire(ONE_WIRE_BUS);

// передать ссылку на oneWire библиотеке DallasTemperature
DallasTemperature sensors(&oneWire);

// адреса трех датчиков DS18B20
uint8_t sensor1[8] = { 0x28, 0xFF, 0xBC, 0x50, 0xB3, 0x16, 0x05, 0xDF };
uint8_t sensor2[8] = { 0x28, 0xFF, 0x69, 0xC4, 0xB3, 0x16, 0x04, 0xE2 };
uint8_t sensor3[8] = { 0x28, 0xFF, 0x46, 0x3B, 0xB3, 0x16, 0x05, 0xC0 };

int fanPin = 6;

void setup()
{
  Serial.begin(9600);
  sensors.begin();

  
  
  pinMode(fanPin, OUTPUT);
  analogWrite(fanPin, 15);
  
}

void loop()
{
  sensors.requestTemperatures();
  
  Serial.print("Sensor 1: ");
  printTemperature(sensor1);
  
  Serial.print("Sensor 2: ");
  printTemperature(sensor2);
  
  Serial.print("Sensor 3: ");
  printTemperature(sensor3);
  
  Serial.println();
  delay(1000);
}

void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print(tempC);
  Serial.print("C  ");
  
}
