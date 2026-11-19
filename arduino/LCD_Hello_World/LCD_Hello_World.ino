#include <LiquidCrystal.h>

// LCD 16x2: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello World");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000UL);
  delay(100);
}
