#include <LiquidCrystal.h>

// LCD 16x2: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// LM35: VOUT -> A0, alimentation 5 V, GND commun
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Thermometre");
  lcd.setCursor(0, 1);
  lcd.print("Numerique");

  for (byte i = 0; i < 5; i++) {
    lcd.display();
    delay(300);
    lcd.noDisplay();
    delay(300);
  }

  lcd.clear();
  lcd.display();
}

void loop() {
  int valeurCAN = analogRead(A0);
  // ADC 10 bits, Vref = 5 V; LM35 = 10 mV / degre C
  float temperature = valeurCAN * 500.0 / 1024.0;

  lcd.setCursor(0, 0);
  lcd.print("CAN = ");
  lcd.print(valeurCAN);
  lcd.print("          ");

  lcd.setCursor(0, 1);
  lcd.print("Temp = ");
  lcd.print(temperature, 1);
  lcd.print(" C       ");

  delay(500);
}
