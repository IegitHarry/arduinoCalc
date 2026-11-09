# Arduino LCD Calculator

**A simple integer calculator built for Arduino** using a 4x4 matrix keypad and an I2C LCD screen (via the Adafruit LiquidCrystal library). This project captures sequential keypresses, parses basic arithmetic operations, and displays the input and results dynamically.

## 🚀 Features

*   **Four Basic Operations:** Supports addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`).
*   **Multi-digit Input:** Allows entering multi-digit integer numbers.
*   **Error Handling:** Basic division-by-zero protection (displays `ERR`).
*   **Dynamic LCD Output:** Line 1 shows the equation (e.g., `12+3=`), and Line 2 displays the computed result.

## 🛠️ Hardware Requirements

*   **Microcontroller:** Arduino Uno (or compatible board)
*   **Display:** 16x2 Character LCD with an I2C backpack
*   **Input:** 4x4 Matrix Keypad

## 📌 Pin Configuration

### 4x4 Keypad

| Keypad Pin | Arduino Digital Pin | Type |
| :--- | :--- | :--- |
| **Row 1** | 9 | Input |
| **Row 2** | 8 | Input |
| **Row 3** | 7 | Input |
| **Row 4** | 6 | Input |
| **Column 1** | 5 | Output |
| **Column 2** | 4 | Output |
| **Column 3** | 3 | Output |
| **Column 4** | 2 | Output |

### Keypad Layout
```text
[ 1 ]  [ 2 ]  [ 3 ]  [ + ]
[ 4 ]  [ 5 ]  [ 6 ]  [ - ]
[ 7 ]  [ 8 ]  [ 9 ]  [ * ]
[   ]  [ 0 ]  [ = ]  [ / ]
```

### I2C LCD Display
Connect your I2C LCD backpack to the standard hardware I2C pins of your Arduino (e.g., `A4` for SDA and `A5` for SCL on an Arduino Uno).

## 🗂️ Software Libraries Needed

Ensure you have the following libraries installed in your Arduino IDE:
*   `Adafruit LiquidCrystal`
*   `Keypad` (by Chris Dirocco)

## 💻 How It Works

1.  **First Number Entry:** The program waits for numeric inputs, updates the screen, and buffers the keystrokes until an operator (`+`, `-`, `*`, `/`) is pressed.
2.  **Second Number Entry:** The program captures the second set of numbers until the equals (`=`) key is pressed.
3.  **Calculation:** The system evaluates the mathematical operator using a `switch` block and prints the resulting integer to the second line of the display.
