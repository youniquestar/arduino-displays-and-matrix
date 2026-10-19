#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// (If 0x27 doesn't work, try 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.init();
  
  // Turn on the blacklight
  lcd.backlight();
  
  // Print a message to the LCD (Starts at Column 0, Row 0 by default)
  lcd.print("Hello, World!");
  
  // Set the cursor to Column 0, Row 1 (the second line)
  lcd.setCursor(0, 1);
  lcd.print("LCD Code Ready");
}

void loop() {
  // Put code here if you want to update the screen continuously
}