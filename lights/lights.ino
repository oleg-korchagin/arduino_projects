#define OUT_PIN_1 3
#define OUT_PIN_2 5
#define LIGHT_ON 150
#define LIGHT_OFF 0

int delayPeriod = 1000;

void setup()
{
  pinMode(OUT_PIN_1, OUTPUT);
  pinMode(OUT_PIN_2, OUTPUT);
}

void loop()
{
//  int num = random(1, 10);
  flash2(3, delayPeriod);
  flash(10, delayPeriod);
  flash3(10, delayPeriod);
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
//    delay(d);
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
      delay(100);
    }
    delay(d);  
    for (int i = LIGHT_ON; i >= 0; i -= 5)
    {
      analogWrite(OUT_PIN_1, i);
      analogWrite(OUT_PIN_2, i);
      delay(200);
    }
    delay(d);
  }
}

void flash3(int numFlashes, int d)
{
  for (int i = 0; i < 3; i++)
  {
    analogWrite(OUT_PIN_1, LIGHT_ON);
    analogWrite(OUT_PIN_2, LIGHT_ON);
    delay(500);
    analogWrite(OUT_PIN_1, LIGHT_OFF);
    analogWrite(OUT_PIN_2, LIGHT_OFF);
    delay(500);
  }
  delay(500);
  for (int i = 0; i < 6; i++)
  {
    analogWrite(OUT_PIN_1, LIGHT_ON);
    analogWrite(OUT_PIN_2, LIGHT_ON);
    delay(200);
    analogWrite(OUT_PIN_1, LIGHT_OFF);
    analogWrite(OUT_PIN_2, LIGHT_OFF);
    delay(200);
  }
  delay(500);
}

