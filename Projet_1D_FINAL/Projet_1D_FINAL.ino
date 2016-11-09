// Desmarais Beatrice, Machard-Garceau Tristan, Rodigue Mattis
// SERGE-JEAN TEMPO
// Concept: Inspiré de Tap Tap Revenge ou encore Guitar Hero, le joueur se retrouve devant un jeu où il doit appuyer sur le bon bouton au bon moment. Des lumières bleues et vertes défilent sur le
// long de la bande de DEL, certaines partant du côté gauche et d'autres du côté droit. Au centre, on retrouve deux lumières blanches qui délimitent la zone où il faut que le joueur appuie sur
// le bouton. Lorsqu'une DEL bleue passe la limite (la DEL blanche gauche) du côté gauche, c'est le moment où il faut appuyer sur le bouton gauche. Lorsqu'une DEL verte passe la limite (la DEL droite)
// du côté droit, c'est le moment où il faut appuyer sur le bouton droit.


// Importation de la librairie Chrono
#include <Chrono.h>

// Importation de la librairie NeoPixels
#include <Adafruit_NeoPixel.h>

// Déclaration des valeurs pour la sélection aléatoire
#define PIN 6
#define NUMPIXELS 60
#define VIDE 0
#define VIDE1 1
#define VIDE2 2
#define VIDE3 3
#define VIDE4 4
#define VIDE5 5
#define VERT 6
#define BLEU 7
#define VIDE8 8
#define VIDE9 9
#define VIDE10 10
#define VIDE11 11
#define VIDE12 12

// Déclaration des variables
int pointCentralGauche = 27;
int pointCentralDroit = 30;
int pointGauche = 28;
int pointDroit = 29;
int bright = 75;
int couleurs[60];
const int buttonPinVert = 7;
int buttonStateVert = 0;

Chrono myChrono;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(58, 6, NEO_GRB + NEO_KHZ800);


void setup() {
  // Déclaration du pinMode pour les deux boutons
  pinMode(7, INPUT);
  pinMode(9, INPUT);

  pixels.begin();
}


void loop() {
  //  Réglage des couleurs et de l'intensité de la luminosité
  couleurs[0] = random(0, 13);
  couleurs[59] = random(0, 13);
  pixels.setBrightness(5);
  //pixels.setPixelColor(pointCentralGauche, pixels.Color(bright, bright, bright));
  //pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 255, 255));

  int pointGauche = couleurs[pointCentralGauche];
  int pointDroit = couleurs[pointCentralDroit];

  // Début du Chrono
  if (myChrono.hasPassed(450)) {

    for ( int i = pointCentralGauche  ; i >= 0  ; i-- ) {
      couleurs[i + 1] = couleurs[i];
    }


    for ( int i = pointCentralDroit  ; i < 60 ; i++ ) {
      couleurs[i - 1] = couleurs[i];
    }


    for (int i = 0; i < 60; i++) {
      int c = couleurs[i];

      // Définition des couleurs des LED qui se promènent
      if ( c == VIDE ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VIDE1 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VIDE2 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VIDE3 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VIDE4 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VIDE5 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VERT ) {
        pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      } else if ( c == BLEU ) {
        pixels.setPixelColor(i, pixels.Color(12, 0, 129));
      } else if ( c == VIDE8 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VIDE9 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VIDE10 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VIDE11 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      } else if ( c == VIDE12 ) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }


    if (digitalRead(9) == 1 && (pointGauche == BLEU)) {
      int bright = 255;
      //digitalWrite(3, HIGH);
      pixels.setPixelColor(pointCentralGauche, pixels.Color(bright, bright, bright));

    } else if (digitalRead(9) == 0 && (pointGauche == BLEU)) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VERT) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE1) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE2) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE3) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE4) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE8) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE8) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE10) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE11) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else if (digitalRead(9) == 1 && pointGauche == VIDE12) {
      pixels.setPixelColor(pointCentralGauche, pixels.Color(255, 0, 0));

    } else {
      digitalWrite(3, LOW);
      pixels.setPixelColor(pointCentralGauche, pixels.Color(50, 50, 50));
    }


    if (digitalRead(7) == 1 && (pointDroit == VERT)) {
      int bright = 255;
      digitalWrite(3, HIGH);
      pixels.setPixelColor(pointCentralDroit, pixels.Color(bright, bright, bright));

    } else if (digitalRead(7) == 0 && (pointDroit == VERT)) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && (pointDroit == BLEU)) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE1) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE2) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE3) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE4) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE8) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE8) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE10) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE11) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else if (digitalRead(7) == 1 && pointDroit == VIDE12) {
      pixels.setPixelColor(pointCentralDroit, pixels.Color(255, 0, 0));

    } else {
      digitalWrite(3, LOW);
      pixels.setPixelColor(pointCentralDroit, pixels.Color(50, 50, 50));
    }

    pixels.show();

    myChrono.restart();
  }
}
