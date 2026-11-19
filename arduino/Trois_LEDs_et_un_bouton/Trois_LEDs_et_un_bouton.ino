const byte bouton = 2;
const byte leds[] = {12, 11, 10};

enum Mode { FIXE, SYNCHRONE, CHENILLARD };
Mode mode = FIXE;

bool derniereLecture = HIGH;
bool etatStable = HIGH;
unsigned long dernierRebond = 0;
unsigned long debutMode = 0;

void setup() {
  pinMode(bouton, INPUT_PULLUP);
  for (byte broche : leds) {
    pinMode(broche, OUTPUT);
  }
}

void loop() {
  unsigned long maintenant = millis();
  bool lecture = digitalRead(bouton);

  if (lecture != derniereLecture) {
    derniereLecture = lecture;
    dernierRebond = maintenant;
  }

  if (lecture != etatStable && maintenant - dernierRebond >= 25) {
    etatStable = lecture;
    if (etatStable == LOW) {
      mode = (mode == SYNCHRONE) ? CHENILLARD : SYNCHRONE;
      debutMode = maintenant;
    }
  }

  unsigned long etape = (maintenant - debutMode) / 100;

  for (byte i = 0; i < 3; i++) {
    bool allumee = mode == FIXE
                || (mode == SYNCHRONE && etape % 2 == 0)
                || (mode == CHENILLARD && etape % 3 == i);
    digitalWrite(leds[i], allumee ? HIGH : LOW);
  }
}