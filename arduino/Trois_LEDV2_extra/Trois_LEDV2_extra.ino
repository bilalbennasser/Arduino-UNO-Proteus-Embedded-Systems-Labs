const int bouton = 2;
const int led = 13;

void setup() {
  pinMode(bouton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(bouton) == LOW) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}