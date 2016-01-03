#define DOT_DELAY 200
#define LED_PIN 3

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

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char ch;
  if (Serial.available() > 0) {
    ch = Serial.read();
    flashChar(ch);
  }
}

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
  digitalWrite(LED_PIN, HIGH);
  if (dotOrDash == '.') {
    delay(DOT_DELAY);
  } else {
    delay(DOT_DELAY * 3);
  }
  digitalWrite(LED_PIN, LOW);
  delay(DOT_DELAY);
}
