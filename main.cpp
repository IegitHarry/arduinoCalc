// C++ code
//
#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

Adafruit_LiquidCrystal lcd(0);

int nums[2];
bool calc = false;
char customKey;
char opr;

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'c', '0', '=', '/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void num1() {
	nums[0] = 0;
  	String temp = "";
  
	while (customKey != '+' && customKey != '-' && 
	customKey != '*' && customKey != '/' && customKey != '=') {
    	customKey = customKeypad.getKey();
      	if (customKey >= 48 && customKey <= 57) {
          	if (temp == "")
              lcd.clear();
    		temp += customKey;
        	lcd.print(customKey);
      	}
  	}
  	opr = customKey;
  	lcd.print(opr);
  	nums[0] = temp.toInt();
  	customKey = '\0';
}
void num2() {
	nums[1] = 0;
  	String temp = "";
  
	while (customKey != '=') {
    	customKey = customKeypad.getKey();
      	if (customKey >= 48 && customKey <= 57) {
    		temp += customKey;
      		lcd.print(customKey);
        }
  	}
  	lcd.print("=");
  	lcd.setCursor(0, 1);
  	nums[1] = temp.toInt();
  	customKey = '\0';
  	calc = true;
}
void setup(){
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  
  Serial.begin(9600);
}
  
void loop(){
  if (!calc) {
  	num1();
    num2();
  }
  else {
    switch(opr) {
      case '+':
      	lcd.print(nums[0] + nums[1]);
      	break;
      case '-':
      	lcd.print(nums[0] - nums[1]);
      	break;
      case '*':
      	lcd.print(nums[0] * nums[1]);
      	break;
      case '/':
      	if (nums[1] != 0)
      		lcd.print(nums[0] / nums[1]);
      	else
          lcd.print("ERR");
      	break;
    }
    calc = false;
    lcd.setCursor(0, 0);
  }
}
