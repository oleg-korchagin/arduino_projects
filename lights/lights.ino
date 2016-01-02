int outputPin = 3;
int LIGHT_ON = 150;
int LIGHT_OFF = 0;
int pause = 2000;

void setup()
{
  pinMode(outputPin, OUTPUT);
}

void loop()
{
//  for (int i=0; i <= 200; i += 10)
//  {
//    analogWrite(outputPin, i);
//    delay(50);
//  }
//  delay(300);
    analogWrite(outputPin, LIGHT_ON);
    delay(pause);
    analogWrite(outputPin, LIGHT_OFF);
    delay(pause);
}
