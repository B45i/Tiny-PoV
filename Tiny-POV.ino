int delayTime = 2;
int charBreak = 5;

int LED1 = 0;
int LED2 = 1;
int LED3 = 2;
int LED4 = 3;
int LED5 = 4;

void setup() {
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
	pinMode(LED5, OUTPUT);
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
	if (line == 16) {
		digitalWrite(LED1, HIGH);
		line -= 16;
	} else {
		digitalWrite(LED1, LOW);
	}
	if (line == 8) {
		digitalWrite(LED2, HIGH);
		line -= 8;
	} else {
		digitalWrite(LED2, LOW);
	}
	if (line == 4) {
		digitalWrite(LED3, HIGH);
		line -= 4;
	} else {
		digitalWrite(LED3, LOW);
	}
	if (line == 2) {
		digitalWrite(LED4, HIGH);
		line -= 2;
	} else {
		digitalWrite(LED4, LOW);
	}
	if (line == 1) {
		digitalWrite(LED5, HIGH);
		line -= 1;
	} else {
		digitalWrite(LED5, LOW);
	}
}

void displayLetter(int letter[5]) {
	for (int i = 0; i < 5; i++) {
		displayLine(letter[i]);
	}
	displayLine(0); // empty line b/w letters.
}

void displayString(String s) {
	s.toUpperCase(); // todo: support lower case as well
	for (int i = 0; i <= s.length(); i++) {
		if (isAlpha(s[i])) { // alphabet - display normally
			displayLetter(alphabets[(int)s[i] - 97]);
		}
		// TODO: handle numbers and special chars
		delay(charBreak);
	}
}

void loop() { displayString("Hello world"); }
