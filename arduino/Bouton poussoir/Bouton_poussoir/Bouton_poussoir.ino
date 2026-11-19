const int bouton = 2;
const int led = 13;
int etatPrecedent = HIGH;

void setup() {
  pinMode(bouton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  int etatActuel = digitalRead(bouton);

  if (etatPrecedent == HIGH && etatActuel == LOW) {
    digitalWrite(led, HIGH);
    delay(300);
    digitalWrite(led, LOW);
  }

  etatPrecedent = etatActuel;
}