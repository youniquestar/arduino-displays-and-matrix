// Define the pins for the 7 Segments (A-G)
const int segmentPins[] = {2, 3, 4, 5, 6, 8, 9}; // A, B, C, D, E, F, G

// Define the pins for the 4 Digits
const int digitPins[] = {10, 11, 12, 13}; // Digits 1, 2, 3, 4

// Segment patterns for numbers 0-9 (Common Cathode: 1 = ON, 0 = OFF)
const byte numPatterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

// Global Tracking Variables
int countdownNumber = 1000;      // Start number
unsigned long lastCountTime = 0; // Tracks the passage of time
const long interval = 1000;      // Countdown speed (1000ms = 1 second)

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH); // Turn off all digits (Common Cathode)
  }
}

void loop() {
  // 1. BACKGROUND TIMER: Check if 1 second has passed
  unsigned long currentMillis = millis();
  if (currentMillis - lastCountTime >= interval) {
    lastCountTime = currentMillis; // Reset timer
    
    countdownNumber--; // Count down by 1
    
    // Reset back to 1000 if the countdown hits 0
    if (countdownNumber < 1) {
      countdownNumber = 1000;
    }
  }

  // 2. MATH: Break the countdown number into 4 individual digits
  int thousands = countdownNumber / 1000;       
  int hundreds  = (countdownNumber / 100) % 10;  
  int tens      = (countdownNumber / 10) % 10;   
  int ones      = countdownNumber % 10;          

  // 3. FIXED MULTIPLEXING: Remapped digit position indices to match correct order
  if (countdownNumber >= 1000) {
    displayDigit(thousands, 0); // Thousands on Digit 1 (Index 0)
    delay(2);
  }
  
  if (countdownNumber >= 100) {
    displayDigit(hundreds, 1);  // Hundreds on Digit 2 (Index 1)
    delay(2);
  }
  
  if (countdownNumber >= 10) {
    displayDigit(tens, 2);      // Tens on Digit 3 (Index 2)
    delay(2);
  }
  
  displayDigit(ones, 3);        // Ones on Digit 4 (Index 3)
  delay(2);
}

// Helper function to handle the multiplexing logic
void displayDigit(int number, int digitPosition) {
  // Turn off all digits first to prevent overlapping shadow images ("ghosting")
  for (int i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], HIGH); 
  }

  // Map out the segments for the requested integer
  for (int seg = 0; seg < 7; seg++) {
    digitalWrite(segmentPins[seg], numPatterns[number][seg]);
  }

  // Turn on ONLY the specific single digit position (LOW is ON for Common Cathode)
  digitalWrite(digitPins[digitPosition], LOW);
}