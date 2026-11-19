// Entrees A, B, C, D du decodeur 7447
const byte brochesBCD[] = {3, 2, 1, 0};

// Six transistors PNP, de gauche a droite : HH MM SS
const byte selections[] = {4, 5, 6, 7, 8, 9};

// false = horloge
// true  = afficher millis() pour diagnostiquer le temps
const bool testTemps = false;

// Heure de depart : 00:00:58
unsigned long secondesDuJour = 58;
unsigned long dernierTick = 0;

void eteindreAfficheurs() {
  for (byte i = 0; i < 6; i++) {
    digitalWrite(selections[i], HIGH);
  }
}

void afficherChiffre(byte chiffre, byte position) {
  eteindreAfficheurs();

  for (byte bit = 0; bit < 4; bit++) {
    digitalWrite(brochesBCD[bit], bitRead(chiffre, bit));
  }

  // Temps de stabilisation du decodeur
  delayMicroseconds(10);

  // LOW active le transistor PNP
  digitalWrite(selections[position], LOW);
  delayMicroseconds(1000);
  digitalWrite(selections[position], HIGH);
}

void setup() {
  for (byte i = 0; i < 6; i++) {
    digitalWrite(selections[i], HIGH);
    pinMode(selections[i], OUTPUT);
  }

  for (byte i = 0; i < 4; i++) {
    digitalWrite(brochesBCD[i], LOW);
    pinMode(brochesBCD[i], OUTPUT);
  }

  dernierTick = millis();
}

void loop() {
  unsigned long maintenant = millis();
  unsigned long tempsEcoule = maintenant - dernierTick;

  if (tempsEcoule >= 1000UL) {
    unsigned long secondesEcoulees = tempsEcoule / 1000UL;

    dernierTick += secondesEcoulees * 1000UL;
    secondesDuJour =
        (secondesDuJour + secondesEcoulees) % 86400UL;
  }

  unsigned long nombre;

  if (testTemps) {
    // Six derniers chiffres du temps en millisecondes
    nombre = maintenant % 1000000UL;
  } else {
    byte heures = secondesDuJour / 3600UL;
    byte minutes = (secondesDuJour / 60UL) % 60UL;
    byte secondes = secondesDuJour % 60UL;

    nombre = heures * 10000UL + minutes * 100UL + secondes;
  }

  byte chiffres[6];

  for (int i = 5; i >= 0; i--) {
    chiffres[i] = nombre % 10UL;
    nombre /= 10UL;
  }

  for (byte i = 0; i < 6; i++) {
    afficherChiffre(chiffres[i], i);
  }
}