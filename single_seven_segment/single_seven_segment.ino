// Define Arduino pins for each segment
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // A, B, C, D, E, F, G, DP

// Binary mapping for digits 0-9 (1 = LED ON, 0 = LED OFF)
// Order matching the array above: {A, B, C, D, E, F, G, DP}
const byte numPatterns[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}  // 9
};

void setup() {
  // Configure all segment pins as OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  // TEST 1: Chase sequence (Lights up individual segments one by one)
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], HIGH);
    delay(200);
    digitalWrite(segmentPins[i], LOW);
  }
  delay(1000);

  // TEST 2: Count from 0 to 9
  for (int digit = 0; digit < 10; digit++) {
    displayDigit(digit);
    delay(800);
  }
  delay(1500);
}

// Helper function to push the logic state to pins
void displayDigit(int num) {
  for (int segment = 0; segment < 8; segment++) {
    digitalWrite(segmentPins[segment], numPatterns[num][segment]);
  }
}