// https://github.com/B45i/Tiny-PoV
// App to calculate array values: https://pov-display-calc.vercel.app/
// Preact app source: https://github.com/B45i/pov-display-calc

#include <avr/pgmspace.h>

#define DELAY_TIME 1
#define CHAR_BREAK 2

uint8_t leds[] = { 0, 1, 2, 3, 4 };
uint8_t keys[] = { 1, 2, 4, 8, 16 };

void setup() {
  for (uint8_t i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

const PROGMEM uint8_t alphabets[][5] = {
  { 0, 0, 0, 0, 0 },       // Space
  { 30, 5, 5, 30, 0 },     // A
  { 31, 21, 21, 10, 0 },   // B
  { 14, 17, 17, 10, 0 },   // C
  { 31, 17, 17, 14, 0 },   // D
  { 31, 21, 21, 17, 0 },   // E
  { 31, 20, 20, 16, 0 },   // F
  { 14, 17, 19, 10, 0 },   // G
  { 31, 4, 4, 4, 31 },     // H
  { 0, 17, 31, 17, 0 },    // I
  { 0, 17, 30, 16, 0 },    // J
  { 31, 4, 10, 17, 0 },    // K
  { 31, 1, 1, 1, 0 },      // L
  { 31, 12, 3, 12, 31 },   // M
  { 31, 12, 3, 31, 0 },    // N
  { 14, 17, 17, 14, 0 },   // O
  { 31, 20, 20, 8, 0 },    // P
  { 14, 17, 19, 14, 2 },   // Q
  { 31, 20, 22, 9, 0 },    // R
  { 8, 21, 21, 2, 0 },     // S
  { 16, 16, 31, 16, 16 },  // T
  { 30, 1, 1, 30, 0 },     // U
  { 24, 6, 1, 6, 24 },     // V
  { 28, 3, 12, 3, 28 },    // W
  { 17, 10, 4, 10, 17 },   // X
  { 17, 10, 4, 8, 16 },    // Y
  { 19, 21, 21, 25, 0 },   // Z
  { 31, 17, 31, 0, 0 },    // 0
  { 18, 31, 16, 0, 0 },    // 1
  { 29, 21, 23, 0, 0 },    // 2
  { 21, 21, 31, 0, 0 },    // 3
  { 7, 4, 31, 4, 0 },      // 4
  { 23, 21, 29, 0, 0 },    // 5
  { 31, 21, 29, 0, 0 },    // 6
  { 1, 1, 31, 0, 0 },      // 7
  { 31, 21, 31, 0, 0 },    // 8
  { 23, 21, 31, 0, 0 },    // 9
};

void displayLine(uint8_t line) {
  for (uint8_t i = 0; i < 5; i++) {
    digitalWrite(leds[i], (line & keys[i]) == keys[i]);
  }
}

void displayLetter(uint8_t n) {
  for (uint8_t i = 0; i < 5; i++) {
    displayLine(pgm_read_word_near(alphabets[n] + i));
    delay(DELAY_TIME);
  }
  displayLine(0);
}

void displayString(char *s) {
  for (uint8_t i = 0; i < strlen(s); i++) {
    uint8_t index;

    if (s[i] == ' ') {
      index = 0;
    } else if (isalpha(s[i])) {
      index = (uint8_t)toupper(s[i]) - 64;
    } else if (isdigit(s[i])) {
      index = (uint8_t)(s[i]) - 21;
    }

    displayLetter(index);
    delay(CHAR_BREAK);
  }
}

void loop() {
  displayString("HELLO 123 ");
}
