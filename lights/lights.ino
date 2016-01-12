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
  flash2(led_pins, 3, delayPeriod);
  flash(led_pins, 10, delayPeriod);
  morseFlasher.flashMessage(messages[random(sizeof(messages))]);
  flash3(led_pins, 20, 50);
}

void flash(int* led_pins, int numFlashes, int d)
{
  for (int i = 0; i < numFlashes; i++)
  {
    for (int j = 0; j < sizeof(led_pins); j++) {
      digitalWrite(led_pins[j], HIGH);
      delay(d);
    }
    for (int j = 0; j < sizeof(led_pins); j++) {
      delay(d);
      digitalWrite(led_pins[j], LOW);
    }
  }
}

void flash2(int* led_pins, int numFlashes, int d)
{
  for (int k = 0; k < numFlashes; k++)
  {
    for (int i = 0; i <= LIGHT_ON; i += 5)
    {
      for (int j = 0; j < sizeof(led_pins); j++) { analogWrite(led_pins[j], i); }
      delay(100);
    }
    delay(d);  
    for (int i = LIGHT_ON; i >= 0; i -= 5)
    {
      for (int j = 0; j < sizeof(led_pins); j++) { analogWrite(led_pins[j], i); }
      delay(100);
    }
    delay(d);
  }
}

void flash3(int* led_pins, int numFlashes, int d)
{
  for (int k = 0; k < numFlashes; k++)
  {
    for (int j = 0; j < sizeof(led_pins); j++) {
      digitalWrite(led_pins[j], HIGH);
      delay(d);
    }
    for (int j = 0; j < sizeof(led_pins); j++) {
      digitalWrite(led_pins[j], LOW);
      delay(d);
    }
  }
}

