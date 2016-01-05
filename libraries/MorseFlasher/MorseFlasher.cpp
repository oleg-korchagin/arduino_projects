#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif 
#include "MorseFlasher.h"

char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".",  // A-I
  "..-", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", // J-R
  "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--",  // S-Z
  "-..-", "-.--", "--.."
};
char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-", // 0-4
  ".....", "-....", "--...", "---..", "----."  // 5-9
};

MorseFlasher::MorseFlasher(int* led_pins, int dot_delay)
{
    _led_pins = led_pins;
    _dot_delay = dot_delay;
    for (int i = 0; i < sizeof(_led_pins); i++) {
        pinMode(_led_pins[i], OUTPUT);
    }
}

void MorseFlasher::flashMessage(char* message) {
  int i = 0;
  while (message[i] != '\0') {
    flashChar(message[i]);
    i++;
  }
}

void MorseFlasher::flashChar(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
      flashSequence(letters[ch - 'a']);
    } else if (ch >= 'A' && ch <= 'Z') {
      flashSequence(letters[ch - 'A']);
    } else if (ch >= '0' && ch <= '9') {
      flashSequence(letters[ch - '0']);
    } else if (ch == ' ') {
      delay(_dot_delay);
    }
}

void MorseFlasher::flashSequence(char* sequence)
{
  int i = 0;
  while (sequence[i] != '\0') {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(_dot_delay * 3);
}

void MorseFlasher::flashDotOrDash(char dotOrDash)
{
    for (int i = 0; i < sizeof(_led_pins); i++) {
        digitalWrite(_led_pins[i], HIGH);
    }
    if (dotOrDash == '.') {
        delay(_dot_delay);
    } else {
        delay(_dot_delay * 3);
    }
    for (int i = 0; i < sizeof(_led_pins); i++) {
        digitalWrite(_led_pins[i], LOW);
    }
    delay(_dot_delay);
}
