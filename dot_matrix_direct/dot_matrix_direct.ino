// Define Row and Column Pin Arrays
const int rowPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int colPins[8] = {10, 11, 12, 13, A0, A1, A2, A3};

// Image Data Matrix (1 = LED ON, 0 = LED OFF)
// This creates a Smile Face pattern
const byte smileFace[8][8] = {
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0}
};

void setup() {
  // Configure all Row and Column pins as OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(rowPins[i], OUTPUT);
    pinMode(colPins[i], OUTPUT);
    
    // Set Initial Safe States
    digitalWrite(rowPins[i], HIGH); // Row-Cathode: HIGH turns row OFF
    digitalWrite(colPins[i], LOW);  // Col-Anode: LOW turns col OFF
  }
}

void loop() {
  // Run the multiplexing loop continuously
  refreshMatrix();
}

// Multiplexing Handler
void refreshMatrix() {
  for (int row = 0; row < 8; row++) {
    
    // 1. Prepare column states for the current row
    for (int col = 0; col < 8; col++) {
      if (smileFace[row][col] == 1) {
        digitalWrite(colPins[col], HIGH); // Turn Column ON
      } else {
        digitalWrite(colPins[col], LOW);  // Turn Column OFF
      }
    }

    // 2. Turn current Row ON (Pull it LOW to complete circuit)
    digitalWrite(rowPins[row], LOW);
    
    // 3. Wait a tiny fraction of time for eyes to see it
    delayMicroseconds(1500); 
    
    // 4. Clean up: Turn Row OFF before moving to prevent ghosting images
    digitalWrite(rowPins[row], HIGH);
  }
}