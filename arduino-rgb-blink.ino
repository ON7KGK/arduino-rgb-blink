/*
 * Arduino RGB LED Rainbow Effect
 *
 * Ce programme fait clignoter une LED RGB avec un effet arc-en-ciel.
 * Il passe par 7 couleurs différentes (rouge, vert, bleu, jaune, cyan, magenta, blanc)
 * avec une pause d'1 seconde entre chaque couleur.
 *
 * Compatible avec: Arduino Uno R4 WiFi (et autres cartes Arduino)
 *
 * Matériel requis:
 * - Arduino Uno R4 WiFi
 * - LED RGB à cathode commune
 * - 3 résistances de 220Ω
 * - Fils de connexion
 * - Breadboard
 *
 * Connexions:
 * - Broche Rouge (R) -> Pin 9 (via résistance 220Ω)
 * - Broche Verte (G) -> Pin 10 (via résistance 220Ω)
 * - Broche Bleue (B) -> Pin 11 (via résistance 220Ω)
 * - Cathode commune -> GND
 */

// Définition des broches pour les couleurs RGB
const int PIN_ROUGE = 9;   // Broche PWM pour le rouge
const int PIN_VERT = 10;   // Broche PWM pour le vert
const int PIN_BLEU = 11;   // Broche PWM pour le bleu

// Délai entre chaque couleur (en millisecondes)
const int DELAI_COULEUR = 1000; // 1 seconde

// Structure pour stocker les valeurs RGB d'une couleur
struct Couleur {
  int rouge;
  int vert;
  int bleu;
  const char* nom;
};

// Tableau des 7 couleurs de l'arc-en-ciel
// Valeurs de 0 (éteint) à 255 (maximum)
const Couleur couleurs[] = {
  {255, 0,   0,   "Rouge"},   // Rouge pur
  {0,   255, 0,   "Vert"},    // Vert pur
  {0,   0,   255, "Bleu"},    // Bleu pur
  {255, 255, 0,   "Jaune"},   // Rouge + Vert = Jaune
  {0,   255, 255, "Cyan"},    // Vert + Bleu = Cyan
  {255, 0,   255, "Magenta"}, // Rouge + Bleu = Magenta
  {255, 255, 255, "Blanc"}    // Toutes les couleurs = Blanc
};

// Nombre de couleurs dans le tableau
const int NOMBRE_COULEURS = 7;

// Index de la couleur actuelle
int indexCouleur = 0;

/**
 * Fonction setup() - Exécutée une seule fois au démarrage
 * Configure les broches en mode sortie et initialise la communication série
 */
void setup() {
  // Configuration des broches RGB en mode sortie
  pinMode(PIN_ROUGE, OUTPUT);
  pinMode(PIN_VERT, OUTPUT);
  pinMode(PIN_BLEU, OUTPUT);

  // Initialisation de la communication série pour le débogage
  // Permet de voir les messages dans le moniteur série
  Serial.begin(9600);

  // Message de démarrage
  Serial.println("=================================");
  Serial.println("Programme RGB Rainbow démarré!");
  Serial.println("=================================");
  Serial.println();

  // Éteindre la LED au démarrage
  afficherCouleur(0, 0, 0);
}

/**
 * Fonction loop() - Exécutée en boucle infinie
 * Affiche chaque couleur de l'arc-en-ciel en séquence
 */
void loop() {
  // Récupérer la couleur actuelle du tableau
  Couleur couleurActuelle = couleurs[indexCouleur];

  // Afficher le nom de la couleur dans le moniteur série
  Serial.print("Couleur: ");
  Serial.println(couleurActuelle.nom);

  // Afficher la couleur sur la LED RGB
  afficherCouleur(couleurActuelle.rouge,
                  couleurActuelle.vert,
                  couleurActuelle.bleu);

  // Attendre 1 seconde avant de passer à la couleur suivante
  delay(DELAI_COULEUR);

  // Passer à la couleur suivante
  indexCouleur++;

  // Si on a atteint la fin du tableau, revenir au début
  if (indexCouleur >= NOMBRE_COULEURS) {
    indexCouleur = 0;
    Serial.println("--- Cycle terminé, redémarrage ---");
    Serial.println();
  }
}

/**
 * Fonction afficherCouleur()
 * Affiche une couleur sur la LED RGB en utilisant PWM
 *
 * @param rouge Intensité du rouge (0-255)
 * @param vert  Intensité du vert (0-255)
 * @param bleu  Intensité du bleu (0-255)
 *
 * PWM (Pulse Width Modulation) permet de contrôler l'intensité lumineuse
 * en variant la durée des impulsions électriques.
 * 0 = éteint, 255 = intensité maximale
 */
void afficherCouleur(int rouge, int vert, int bleu) {
  analogWrite(PIN_ROUGE, rouge);
  analogWrite(PIN_VERT, vert);
  analogWrite(PIN_BLEU, bleu);
}
