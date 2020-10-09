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

boolean statusLed = false;  // beim einschalten ist der Merker nicht gesetzt

byte led[8] = {2, 3, 4, 5, 6, 7, 8, 9};    //definierung der 2D for Schleife
byte ledZustand [9] [8] = {
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
      for (byte i = 0; i < 9; i++) //Zeilen           // Äußere For Schleife
      {
        for (byte j = 0; j < 8; j++)  //Spalten       // Innere For Schleife
        {
          digitalWrite(led[j], ledZustand[i][j]);
        }
        delay(80);                                   // Verzögerung der Einzelnen LEDs
      }

    }
  }
}

void Funktion_Taster()
{
  statusLed = !statusLed;                // Auszuführende Funktion (Merker wird gedreht)
}                                        // möglichst wenig Code bzw. nur Merker wenn es nicht anders geht
