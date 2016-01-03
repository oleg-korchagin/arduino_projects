#define OUT_PIN_1 3
#define OUT_PIN_2 5
#define LIGHT_ON 200
#define LIGHT_OFF 0
#define DOT_DELAY 200

int delayPeriod = 1000;

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

char* messages[] = {
  "HAPPY NEW YEAR",
  "2016",
  "MARRY CHRISTMAS",
  "SODOMY IS SIN"
};

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
//  flash3(10, delayPeriod);
  flash_morse(messages[random(sizeof(messages))]);
}

void flash_morse(char* message) {
  int i = 0;
  while (message[i] != '\0') {
    flashChar(message[i]);
    i++;
  }
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

//void flash3(int numFlashes, int d)
//{
//  for (int i = 0; i < 3; i++)
//  {
//    analogWrite(OUT_PIN_1, LIGHT_ON);
//    analogWrite(OUT_PIN_2, LIGHT_ON);
//    delay(500);
//    analogWrite(OUT_PIN_1, LIGHT_OFF);
//    analogWrite(OUT_PIN_2, LIGHT_OFF);
//    delay(500);
//  }
//  delay(500);
//  for (int i = 0; i < 6; i++)
//  {
//    analogWrite(OUT_PIN_1, LIGHT_ON);
//    analogWrite(OUT_PIN_2, LIGHT_ON);
//    delay(200);
//    analogWrite(OUT_PIN_1, LIGHT_OFF);
//    analogWrite(OUT_PIN_2, LIGHT_OFF);
//    delay(200);
//  }
//  delay(500);
//}

void flashChar(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
      flashSequence(letters[ch - 'a']);
    } else if (ch >= 'A' && ch <= 'Z') {
      flashSequence(letters[ch - 'A']);
    } else if (ch >= '0' && ch <= '9') {
      flashSequence(letters[ch - '0']);
    } else if (ch == ' ') {
      delay(DOT_DELAY);
    }
}

void flashSequence(char* sequence)
{
  int i = 0;
  while (sequence[i] != '\0') {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(DOT_DELAY * 3);
}

void flashDotOrDash(char dotOrDash)
{
  digitalWrite(OUT_PIN_1, HIGH);
  digitalWrite(OUT_PIN_2, HIGH);
  if (dotOrDash == '.') {
    delay(DOT_DELAY);
  } else {
    delay(DOT_DELAY * 3);
  }
  digitalWrite(OUT_PIN_1, LOW);
  digitalWrite(OUT_PIN_2, LOW);
  delay(DOT_DELAY);
}
