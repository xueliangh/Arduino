#include <dht.h>
dht DHT;
float temp;
float humi;
void setup()
{
Serial.begin(9600);
for(int i=4;i<=11;i++)
pinMode(i,OUTPUT);
}

void loop()
{
  DHT.read11(A0); // 讀取溫度
  temp=DHT.temperature;
  humi=DHT.humidity;
  Serial.print(“Humidity:");
  Serial.print(humi);
  Serial.print(“%, “);
  Serial.print(“Temperature:");
  Serial.println(temp);
  if(temp >= 28)
  {
    digitalWrite(8, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
  }
  else if (temp == 27)
  {
    digitalWrite(4, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
  }
  else if (temp <= 26)
  {
    digitalWrite(7, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
  }
  delay(500);
}
