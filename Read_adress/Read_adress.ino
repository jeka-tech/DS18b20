#include <OneWire.h>
#include <DallasTemperature.h>

// линия данных подключена к цифровому выводу 2 Arduino
#define ONE_WIRE_BUS 12

// настройка объекта oneWire для связи с любым устройством OneWire
OneWire oneWire(ONE_WIRE_BUS);

// передать ссылку на oneWire библиотеке DallasTemperature
DallasTemperature sensors(&oneWire);

// переменная для хранения адресов устройств
DeviceAddress Thermometer;

int deviceCount = 0;

void setup(void)
{
  // запустить последовательный порт
  Serial.begin(9600);

  // запустить библиотеку
  sensors.begin();

  // найти устройства на шине
  Serial.println("Locating devices...");
  Serial.print("Found ");
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");
  
  Serial.println("Printing addresses...");
  for (int i = 0;  i < deviceCount;  i++)
  {
    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(" : ");
    sensors.getAddress(Thermometer, i);
    printAddress(Thermometer);
  }
}

void loop(void)
{}

void printAddress(DeviceAddress deviceAddress)
{ 
  for (uint8_t i = 0; i < 8; i++)
  {
    Serial.print("0x");
    if (deviceAddress[i] < 0x10) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
    if (i < 7) Serial.print(", ");
  }
  Serial.println("");
}
