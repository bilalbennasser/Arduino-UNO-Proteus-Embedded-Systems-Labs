const byte feuA[] = {7, 6, 5};
const byte feuB[] = {4, 3, 2};

enum Couleur { ROUGE, ORANGE, VERT };

void afficher(const byte feu[], Couleur couleur) {
  for (byte i = 0; i < 3; i++) {
    digitalWrite(feu[i], i == couleur ? HIGH : LOW);
  }
}

void setup() {
  for (byte i = 0; i < 3; i++) {
    pinMode(feuA[i], OUTPUT);
    pinMode(feuB[i], OUTPUT);
  }
}

void loop() {
  afficher(feuA, ROUGE);
  afficher(feuB, VERT);
  delay(1000);

  afficher(feuA, ORANGE);
  afficher(feuB, ORANGE);
  delay(600);

  afficher(feuB, ROUGE);
  afficher(feuA, VERT);
  delay(1000);

  afficher(feuA, ORANGE);
  afficher(feuB, ORANGE);
  delay(600);
}