/*
  Funktion:
  Programierer: Ole Riehemann
  letzte Änderung: 15.09.2020
  Version: 0.0.1

  Hardware:

*/


#include <OneButton.h>
OneButton taster(10, true);
#define LED 13
boolean statusLed;



void setup()
{
  pinMode(13, OUTPUT);

  taster.attachClick(Funktion_Taster);

}

void loop()
{
  taster.tick();

  delay(10);

  {
    if (statusLed == HIGH)
    {
      digitalWrite(LED, LOW);
    }
    else
    {
      digitalWrite(LED, HIGH);
    }
  }
}

void Funktion_Taster()
{
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
}
