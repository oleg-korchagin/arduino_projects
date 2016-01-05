#include <MorseFlasher.h>

#define DOT_DELAY 200
#define LED_PIN 3

int led_pins[] = { LED_PIN };

MorseFlasher morseFlasher(led_pins, DOT_DELAY);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char ch;
  if (Serial.available() > 0) {
    ch = Serial.read();
    morseFlasher.flashChar(ch);
  }
}

