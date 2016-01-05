#include <MorseFlasher.h>

#define DOT_DELAY 200
#define LED_PIN 13

int led_pins[] = { LED_PIN };

MorseFlasher morseFlasher(led_pins, DOT_DELAY);

void setup(){}

void loop()
{
    morseFlasher.flashMessage("Hello world");
}
