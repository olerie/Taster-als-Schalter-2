/*
  Funktion:
  Programierer: Ole Riehemann
  letzte Änderung: 06.10.2020
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
  taster.tick();    // beobachtung ob taster gedrückt wird

  delay(10);

  {
    if (statusLed == HIGH)         // Funktion für LED anschalten
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
  statusLed = !statusLed;
}
