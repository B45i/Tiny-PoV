#define DELAY_TIME 1
#define CHAR_BREAK 2

uint8_t leds[] = { 0, 1, 2, 3, 4 };
uint8_t keys[] = { 1, 2, 4, 8, 16 };

void setup() {
  for (uint8_t i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }

  //    uint8_t x = 1;
  //  while(1) {
  //       for (uint8_t i = 0; i < 5; i++) {
  //    digitalWrite(leds[i], x);
  //    delay(100);
  //  }
  //  x = !x;
  //  }
}

const PROGMEM uint8_t alphabets[][5] = {
  { 30, 5, 5, 30, 0 },
  { 31, 21, 21, 10, 0 },
  { 14, 17, 17, 10, 0 },
  { 31, 17, 17, 14, 0 },
  { 31, 21, 21, 17, 0 },
  { 31, 20, 20, 16, 0 },
  { 14, 17, 19, 10, 0 },
  { 31, 4, 4, 4, 31 },
  { 0, 17, 31, 17, 0 },
  { 0, 17, 30, 16, 0 },
  { 31, 4, 10, 17, 0 },
  { 31, 1, 1, 1, 0 },
  { 31, 12, 3, 12, 31 },
  { 31, 12, 3, 31, 0 },
  { 14, 17, 17, 14, 0 },
  { 31, 20, 20, 8, 0 },
  { 14, 17, 19, 14, 2 },
  { 31, 20, 22, 9, 0 },
  { 8, 21, 21, 2, 0 },
  { 16, 16, 31, 16, 16 },
  { 30, 1, 1, 30, 0 },
  { 24, 6, 1, 6, 24 },
  { 28, 3, 12, 3, 28 },
  { 17, 10, 4, 10, 17 },
  { 17, 10, 4, 8, 16 },
  { 19, 21, 21, 25, 0 }
};

void displayLine(uint8_t line) {
  for (uint8_t i = 0; i < 5; i++) {
    digitalWrite(leds[i], (line & keys[i]) == keys[i]);
  }
}

void displayLetter(uint8_t n) {
  for (uint8_t i = 0; i < 5; i++) {
    displayLine(alphabets[n][i]);
    delay(DELAY_TIME);
  }
  displayLine(0);
}

void displayString(char *s) {
  for (uint8_t i = 0; i <= strlen(s); i++) {
    uint8_t charCode = (uint8_t)toupper(s[i]);
    displayLetter((uint8_t)charCode - 97);
    delay(CHAR_BREAK);
  }
}

void loop() {
  displayString("Hello");
}
