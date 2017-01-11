#include <SoftwareSerial.h>
char BTcmd;
SoftwareSerial BT(8,9); // Arduino RX/TX

void setup() {
  for(int i=3;i<7;i++)
  pinMode(i,OUTPUT);
  Serial.begin(9600);
  BT.begin(9600); // HC-06
}

void loop() {
if (BT.available())
{
  BTcmd=BT.read();
  switch(BTcmd)
  {
    case 'A':
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    break;
    case 'B':
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    break;
    case 'C':
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    break;
    case 'D':
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    break;
    default:
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    break;
  }
}
}


