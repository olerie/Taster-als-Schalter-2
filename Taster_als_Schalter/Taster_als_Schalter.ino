/*
  Funktion: Mit einem Taster soll ein Lauflicht an- bzw. ausschalten
  Programierer: Ole Riehemann
  letzte Änderung: 07.10.2020
  Version: 0.0.1
  Bibliothek:
  Hardware:1x taster; 8x LED; 8x 280Ohm Widerstand

*/

#include <OneButton.h>
OneButton taster(10, false);        // mit "false" wird der interne PullDown nicht mehr gesetzt

/*********************Einstellung Bibliothek*****************/
long unsigned int start;            // Startwert des Zählers
long unsigned int intervall = 95;   // wechselzeit der LEDs
boolean statusLed = false;          // durch "false" wird beim einschalten der Merker nicht gesetzt
byte zeile = 0;                     // ersatzwert für erste Forschleife
byte led [8] = {2, 3, 4, 5, 6, 7, 8, 9};
byte ledZustand [9][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
};


void setup()
{
  taster.attachClick(Funktion_Taster);
  Serial.begin(9600);

  for (byte i = 0; i < 9; i++)
  {
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{
  taster.tick();    // beobachtung ob taster gedrückt wird
  delay(10);

  {
    if (statusLed == true)
    {
      Serial.println("Taster gedrueckt");         // ueberpruefung ob Signal kommt

      if ((millis() - start) >= intervall)        // blink takt
      {
        Serial.println("Takt");                   // Signalueberpruefung
        start = millis();
        {
          for (byte i = 0; i < 9; i++)         // Innere For Schleife
          {
            digitalWrite(led[i], ledZustand[zeile][i]);
            Serial.println(zeile);             // ueberprüfung Zeilenwert
          }
          zeile++;  // nächste Zeile

          if (zeile == 9)                      // Nullen des Zählwertes nach durchlauf
          {
            zeile = 0;
          }
          
        }
      }
    }
    else                                     // wenn Taster nicht gedrückt wird
    {
      for (byte i = 0; i < 9; i ++)            //Alle LEDs werden ausgeschaltet
      {
        digitalWrite(led[i], LOW);
        zeile = 0;
      }
    }
  }
}

void Funktion_Taster()
{
  statusLed = !statusLed;                // Auszuführende Funktion, wenn Taster gedrückt wird (Merker wird gedreht)
}                                        // möglichst wenig Code bzw. nur Merker wenn es nicht anders geht
