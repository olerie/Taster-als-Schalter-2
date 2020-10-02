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
}

void Funktion_Taster()
{
  {
    if (statusLed == HIGH)
    {
      digitalWrite(LED, LOW);
      statusLed = 0;
    }
    else
    {
      digitalWrite(LED, HIGH);
      statusLed = 1;
    }
  }
}
