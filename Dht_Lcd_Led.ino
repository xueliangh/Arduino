#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <dht.h> //溫度感測器函式庫
SoftwareSerial BT(2, 3);//TX, RX
#include <Wire.h>
dht DHT;
// 建立 LiquidCrystal 的變數 lcd
// LCD 接腳: rs, enable, d4, d5, d6, d7
// 對應到 Arduino 接腳: 12, 13, 7, 6, 5, 4
LiquidCrystal lcd(12, 13, 7, 6, 5, 4);
int R=9, G=10, B=11,r,g,b;
char BTcmd;
int temp,humi;

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  lcd.begin(16, 2); // 設定 LCD 的行列數目 (2 x 16)
  for (int i=9;i<=11;i++)
    pinMode(i,OUTPUT);
}

void loop()
{
  DHT.read11(A0); // 讀取溫度
  temp=DHT.temperature;
  humi=DHT.humidity;
  lcd.setCursor(0,0);

  if (temp!=0 && humi!=0)
  {
    lcd.print("Temp=");
    lcd.print(temp);
    lcd.print(" Humi=");
    lcd.print(humi);
    lcd.print("%");
    delay(650);
  }

  if (BT.available())
  {
    BTcmd=BT.read();
    BT.println(BTcmd);
  if(BTcmd=='R')
  {
    lcd.clear();
    analogWrite(R,255);
    analogWrite(G,0);
    analogWrite(B,0);
  }
  if(BTcmd=='G')
  {
    lcd.clear();
    analogWrite(R,0);
    analogWrite(G,255);
    analogWrite(B,0);
  }
  if(BTcmd=='B')
  {
    lcd.clear();
    analogWrite(R,0);
    analogWrite(G,0);
    analogWrite(B,255);
  }
  if(BTcmd=='O')
  {
    lcd.clear();
    analogWrite(R, 255);
    analogWrite(G, 10);
    analogWrite(B, 0);
  }
  if(BTcmd=='Y')
  {
    lcd.clear();
    analogWrite(R, 255);
    analogWrite(G, 30);
    analogWrite(B, 0);
  }
  if(BTcmd=='I')
  {
    lcd.clear();
    analogWrite(R, 100);
    analogWrite(G, 82);
    analogWrite(B, 121);
  }
  if(BTcmd=='P')
  {
    lcd.clear();
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 70);
  }
  if(BTcmd=='X')
  {
    lcd.clear();
    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);
    analogWrite(R, r);
    analogWrite(G, g);
    analogWrite(B, b);
    lcd.setCursor(0,1);
    lcd.print("R=");
    lcd.print(r);
    lcd.print(" G=");
    lcd.print(g);
    lcd.print(" B=");
    lcd.print(b);
    delay(100);
  }
  if(BTcmd=='S')
  {
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 0);
  }
}
}
