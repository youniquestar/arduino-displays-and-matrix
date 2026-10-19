# 🖥️ Arduino Display & Matrix Interface Suite

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-00979D.svg?logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-00599C.svg?logo=c%2B%2B&logoColor=white)](https://en.wikipedia.org/wiki/C%2B%2B)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Status: Tested](https://img.shields.io/badge/Hardware%20Status-Tested%20%26%20Verified-brightgreen.svg)]()

A comprehensive library of Arduino visual display drivers and interface implementations covering 8x8 LED dot matrices (direct GPIO, MAX7219 IC, software multiplexed), single & 4-digit 7-segment LED displays, and I2C 16x2 alphanumeric liquid crystal displays (LCD).

---

## 📋 Included Display Drivers

| Directory | Display Hardware | Interface Method | Required Libraries |
| :--- | :--- | :--- | :--- |
| [`dot_matrix_direct/`](dot_matrix_direct/) | 8x8 LED Dot Matrix | Direct Row/Col GPIO Scanning (Smile pattern) | None (Standard GPIO) |
| [`dot_matrix_max7219/`](dot_matrix_max7219/) | 8x8 Dot Matrix + MAX7219 IC | 3-Wire SPI-like Serial Interface | `LedControl.h` |
| [`dot_matrix_multiplexed/`](dot_matrix_multiplexed/) | 8x8 Discrete Matrix | High-frequency persistence-of-vision scan | None |
| [`single_seven_segment/`](single_seven_segment/) | 1-Digit 7-Segment LED (Common Cathode) | 8-Pin Parallel Segment Drive (0-9 counter) | None |
| [`four_digit_seven_segment/`](four_digit_seven_segment/) | 4-Digit 7-Segment LED | Time-division digit multiplexing (Pins 2-6, 8-13) | None |
| [`i2c_lcd_display/`](i2c_lcd_display/) | 16x2 HD44780 LCD via PCF8574 I2C Adapter | 2-Wire I2C Bus (`0x27` / `0x3F`) | `Wire.h`, `LiquidCrystal_I2C.h` |

---

## 🛠️ Hardware Specifications & BOM

| Component | Description | Suitable Parts |
| :--- | :--- | :--- |
| **Microcontroller** | Arduino Uno, Nano, Mega2560 | ATmega328P / ATmega2560 |
| **8x8 LED Matrix** | Common Anode or Cathode 8x8 matrix module | 1088AS, 1588AS |
| **MAX7219 Module** | Serial 8-digit/matrix LED driver IC | FC-16 MAX7219 Dot Matrix Module |
| **7-Segment Display (1-Digit)** | Common Cathode 0.56" 10-pin display | 5161AS |
| **7-Segment Display (4-Digit)** | Common Cathode 12-pin 4-digit module | 5461AS, 3461AS |
| **16x2 Character LCD** | 16-character 2-line LCD with soldered PCF8574 I2C backpack | 1602 LCD I2C Blue/Yellow-Green |
| **Current Limiting Resistors** | 220Ω, 330Ω 1/4W resistors | 8 to 16 pcs for direct LED driving |

---

## 🔌 Pinout Guides

### 1. MAX7219 8x8 Dot Matrix (`dot_matrix_max7219`):
| MAX7219 Pin | Arduino Pin | Description |
| :--- | :--- | :--- |
| **VCC** | 5V | 5V Power Supply |
| **GND** | GND | Ground |
| **DIN (Data In)** | Digital Pin 12 | Serial Data Input |
| **CLK (Clock)** | Digital Pin 11 | Synchronous Shift Clock |
| **CS / LOAD** | Digital Pin 10 | Chip Select / Latch |

### 2. 16x2 I2C Alphanumeric LCD (`i2c_lcd_display`):
| LCD Backpack Pin | Arduino Uno/Nano Pin | Arduino Mega Pin | Description |
| :--- | :--- | :--- | :--- |
| **GND** | GND | GND | Power Ground |
| **VCC** | 5V | 5V | +5V System Voltage |
| **SDA** | A4 | Pin 20 | I2C Serial Data |
| **SCL** | A5 | Pin 21 | I2C Serial Clock |

### 3. 4-Digit 7-Segment Display Multiplexer (`four_digit_seven_segment`):
- **Segment Pins (A-G)**: Pins `2, 3, 4, 5, 6, 8, 9` (with 220Ω series resistors)
- **Digit Select Pins (1-4)**: Pins `10, 11, 12, 13` (Active low / transistor sink)

---

## 📦 Required Software Libraries

For MAX7219 and I2C LCD sketches, install the following via **Arduino IDE > Sketch > Include Library > Manage Libraries...**:
1. `LedControl` by Eberhard Fahle
2. `LiquidCrystal I2C` by Marco Schwartz / Frank de Brabander

---

## 🚀 Installation & Upload

1. Clone this repository:
   ```bash
   git clone https://github.com/youniquestar/arduino-displays-and-matrix.git
   ```
2. Navigate to your desired sketch folder in Arduino IDE.
3. Verify wiring and I2C address (default `0x27`, or `0x3F`).
4. Upload to your connected board.

---

## 📜 License

Licensed under the [MIT License](LICENSE).
