/*
  Funktion:
  Programierer: Ole Riehemann
  letzte Änderung: 06.10.2020
  Version: 0.0.1

  Hardware:

*/

#include <OneButton.h>
OneButton taster(2, false);        // interner PullDown nicht mehr gesetzt
#define LED 13
boolean statusLed = false;  // beim einschalten ist der Merker nicht gesetzt

void setup()
{
  pinMode(13, OUTPUT);

  taster.attachClick(Funktion_Taster);
}

void loop()
{
  taster.tick();    // beobachtung ob taster gedrückt wird

  delay(10);
  
  digitalWrite(LED, statusLed);       // Zuweisung Led = Merker
}

void Funktion_Taster()
{
  statusLed = !statusLed;                // Auszuführende Funktion (Merker wird gedreht) 
}                                        // möglichst wenig Code bzw. nur Merker wenn nicht anders geht
