const byte led1 = 12;
const byte led2 = 11;

unsigned long dernierChangement1 = 0;
unsigned long dernierChangement2 = 0;

bool etat1 = LOW;
bool etat2 = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  unsigned long maintenant = millis();

  if (maintenant - dernierChangement1 >= 500) {
    dernierChangement1 = maintenant;
    etat1 = !etat1;
    digitalWrite(led1, etat1);
  }

  if (maintenant - dernierChangement2 >= 200) {
    dernierChangement2 = maintenant;
    etat2 = !etat2;
    digitalWrite(led2, etat2);
  }
}