#include <MorseFlasher.h>

#define OUT_PIN_1 3
#define OUT_PIN_2 5
#define LIGHT_ON 255
#define LIGHT_OFF 0
#define DOT_DELAY 200

int delayPeriod = 1000;
int led_pins[] = { OUT_PIN_1, OUT_PIN_2 };

char* messages[] = {
  "HAPPY NEW YEAR 2016",
  "MARRY CHRISTMAS",
  "SODOMY IS SIN"
};

MorseFlasher morseFlasher(led_pins, DOT_DELAY);

void setup()
{
  randomSeed(analogRead(0));
}

void loop()
{
  flash2(3, delayPeriod);
  flash(10, delayPeriod);
  morseFlasher.flashMessage(messages[random(sizeof(messages))]);
}

void flash(int numFlashes, int d)
{
  for (int i = 0; i < numFlashes; i++)
  {
    analogWrite(OUT_PIN_1, LIGHT_ON);
    delay(d);
    analogWrite(OUT_PIN_2, LIGHT_ON);
    delay(d);
    analogWrite(OUT_PIN_1, LIGHT_OFF);
    delay(d);
    analogWrite(OUT_PIN_2, LIGHT_OFF);
  }
}

void flash2(int numFlashes, int d)
{
  for (int k = 0; k < numFlashes; k++)
  {
    for (int i = 0; i <= LIGHT_ON; i += 5)
    {
      analogWrite(OUT_PIN_1, i);
      analogWrite(OUT_PIN_2, i);
      delay(50);
    }
    delay(d);  
    for (int i = LIGHT_ON; i >= 0; i -= 5)
    {
      analogWrite(OUT_PIN_1, i);
      analogWrite(OUT_PIN_2, i);
      delay(100);
    }
    delay(d);
  }
}

