#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif 

class MorseCoder
{
    public:
        MorseCoder(int* led_pins, int dot_delay);
        void flashMessage(char* message);
        void flashChar(char ch);
    private:
        int* _led_pins;
        int  _dot_delay;
        void flashDotOrDash(char dotOrDash);
        void flashSequence(char* sequence);
};
