#include <LiquidCrystal.h>

// LCD 16x2: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const byte buzzer = 8;         // Buzzer actif: signal sur D8
const float seuil = 27.0;     // Alarme si temperature > 27 degres C

void setup() {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  lcd.begin(16, 2);
}

void loop() {
  int valeurCAN = analogRead(A0);
  float temperature = valeurCAN * 500.0 / 1024.0;
  bool alarme = temperature > seuil;

  digitalWrite(buzzer, alarme ? HIGH : LOW);

  lcd.setCursor(0, 0);
  lcd.print("Temp = ");
  lcd.print(temperature, 1);
  lcd.print(" C      ");

  lcd.setCursor(0, 1);
  lcd.print(alarme ? "ALARME ACTIVE   " : "ALARME ARRETEE  ");

  delay(100);
}
