#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#define ONE_WIRE_BUS 2

SoftwareSerial BT(10,11); // Arduino RX/TX
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float NowTemp;

void setup(void)
{
  Serial.begin(9600);
  Serial.println(“Temperature Sensor");
  BT.begin(9600);
  sensors.begin();
}

void loop(void)
{
  sensors.requestTemperatures();
  Serial.println(sensors.getTempCByIndex(0));
  BT.print(sensors.getTempCByIndex(0));
  delay(300);
}
