#include <GoProControl.h>
#include "Secrets.h"

#define CAMERA HERO3

int ANALOG_PIN = A0;
int val = 0;

GoProControl gp(GOPRO_SSID, GOPRO_PASS, CAMERA);

void setup()
{
  //Camera setup
  gp.enableDebug(&Serial);
  gp.begin();
  gp.confirmPairing();

  //ADC and LED setup
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(ANALOG_PIN); //Measure voltage over button using ADC
  if (val >= 400) //If button is pressed
  {
    if (gp.isRecording()) //FIXME: This function does not work...
      gp.stopShoot();
    else
      gp.shoot();
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
    digitalWrite(LED_BUILTIN, LOW);
  delay(200); //Wait to not accidentially trigger too many pictures
}
