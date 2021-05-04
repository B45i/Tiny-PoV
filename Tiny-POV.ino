int delayTime = 2;
int charBreak = 5;
int ledCount = 5;

int leds[] = {0, 1, 2, 3, 4};
int keys[] = {1, 2, 4, 8, 16};

void setup() {
	for (int i = 0; i < ledCount; i++) {
		pinMode(leds[i], OUTPUT);
	}
}

int alphabets[][5] = {
	{30, 5, 5, 30, 0},
	{31, 21, 21, 10, 0},
	{14, 17, 17, 10, 0},
	{31, 17, 17, 14, 0},
	{31, 21, 21, 17, 0},
	{31, 20, 20, 16, 0},
	{14, 17, 19, 10, 0},
	{31, 4, 4, 4, 31},
	{0, 17, 31, 17, 0},
	{0, 17, 30, 16, 0},
	{31, 4, 10, 17, 0},
	{31, 1, 1, 1, 0},
	{31, 12, 3, 12, 31},
	{31, 12, 3, 31, 0},
	{14, 17, 17, 14, 0},
	{31, 20, 20, 8, 0},
	{14, 17, 19, 14, 2},
	{31, 20, 22, 9, 0},
	{8, 21, 21, 2, 0},
	{16, 16, 31, 16, 16},
	{30, 1, 1, 30, 0},
	{24, 6, 1, 6, 24},
	{28, 3, 12, 3, 28},
	{17, 10, 4, 10, 17},
	{17, 10, 4, 8, 16},
	{19, 21, 21, 25, 0}};

void displayLine(int line) {
	for (int i = 0; i < ledCount; i++) {
		digitalWrite(leds[i], (line & keys[i]) == keys[i]);
	}
}

void displayLetter(int letter[5]) {
	for (int i = 0; i < 5; i++) {
		displayLine(letter[i]);
	}
	displayLine(0); // empty line b/w letters.
}

void displayString(String s) {
	s.toUpperCase(); // TODO: support lower case as well
	for (int i = 0; i <= s.length(); i++) {
		if (isAlpha(s[i])) { // alphabet - display normally
			displayLetter(alphabets[(int)s[i] - 97]);
		}
		// TODO: handle numbers and special chars
		delay(charBreak);
	}
}

void loop() {
	displayString("Hello world");
}
