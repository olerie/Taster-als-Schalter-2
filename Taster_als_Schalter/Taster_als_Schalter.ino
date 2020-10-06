/*
  Funktion:
  Programierer: Ole Riehemann
  letzte Änderung: 04.10.2020
  Version: 0.0.1

  Hardware:

*/

#include <OneButton.h>
OneButton taster(2, true);
#define LED 13
boolean statusLed;

void setup()
{
  pinMode(13, OUTPUT);

  taster.attachClick(Funktion_Taster);
  Serial.begin(9600);

}

void loop()
{
  taster.tick();

  delay(10);

  {
    if (statusLed == HIGH)
    {
      digitalWrite(LED, LOW);
      Serial.println("LED AUS");
    }
    else
    {
      digitalWrite(LED, HIGH);
      Serial.println("LED AN");
    }
  }
}

void Funktion_Taster()
{
  if (statusLed == HIGH)
  {
    statusLed = 0;
  }
  else
  {
    statusLed = 1;
  }
}
