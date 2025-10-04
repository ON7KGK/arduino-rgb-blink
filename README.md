# Arduino RGB Blink - Effet Arc-en-ciel 🌈

Projet Arduino qui fait clignoter une LED RGB avec un effet arc-en-ciel sur l'Arduino Uno R4 WiFi.

## 📋 Description

Ce programme fait passer une LED RGB par 7 couleurs différentes (rouge, vert, bleu, jaune, cyan, magenta, blanc) avec une pause d'1 seconde entre chaque couleur. Le code est entièrement commenté en français pour faciliter la compréhension.

## 🔧 Matériel requis

- **Arduino Uno R4 WiFi** (ou autre carte Arduino compatible)
- **LED RGB à cathode commune** (1 unité)
- **Résistances 220Ω** (3 unités)
- **Breadboard** (plaque d'essai)
- **Fils de connexion** (jumper wires)

> **Note importante**: L'Arduino Uno R4 WiFi n'a **pas** de LED RGB intégrée. Il dispose d'une matrice LED rouge (12x8). Ce projet utilise donc une LED RGB externe connectée aux broches PWM de l'Arduino.

## 🔌 Schéma de câblage

### Connexions

```
LED RGB (Cathode commune)
├── Broche R (Rouge)   -> Pin 9  (via résistance 220Ω)
├── Broche G (Verte)   -> Pin 10 (via résistance 220Ω)
├── Broche B (Bleue)   -> Pin 11 (via résistance 220Ω)
└── Cathode (-)        -> GND
```

### Schéma textuel

```
Arduino Uno R4          Résistances          LED RGB (Cathode commune)

Pin 9  (PWM) ----[220Ω]-------------------- R (Rouge)
Pin 10 (PWM) ----[220Ω]-------------------- G (Vert)
Pin 11 (PWM) ----[220Ω]-------------------- B (Bleu)
GND ---------------------------------------- Cathode (patte la plus longue)
```

### Points importants

- ⚠️ **LED à cathode commune** : La cathode (patte commune, généralement la plus longue) va au GND
- 🔌 **Broches PWM** : Les pins 9, 10 et 11 sont des broches PWM nécessaires pour contrôler l'intensité
- 🛡️ **Résistances obligatoires** : Protègent la LED et l'Arduino (220Ω recommandées)

## 🚀 Installation et utilisation

### Prérequis

1. **Installer l'IDE Arduino** : [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
2. **Installer le support pour Arduino Uno R4** :
   - Ouvrir l'IDE Arduino
   - Aller dans `Outils` → `Type de carte` → `Gestionnaire de cartes`
   - Rechercher "Arduino UNO R4 Boards"
   - Installer le package

### Téléversement du code

1. **Ouvrir le fichier** : `arduino-rgb-blink.ino`
2. **Sélectionner la carte** :
   - `Outils` → `Type de carte` → `Arduino UNO R4 Boards` → `Arduino UNO R4 WiFi`
3. **Sélectionner le port** :
   - `Outils` → `Port` → Sélectionner le port COM de votre Arduino
4. **Compiler et téléverser** :
   - Cliquer sur le bouton "Téléverser" (→)
5. **Ouvrir le moniteur série** (optionnel) :
   - `Outils` → `Moniteur série`
   - Configurer le débit à 9600 bauds
   - Vous verrez les noms des couleurs s'afficher

### Utilisation avec Arduino CLI

```bash
# Compiler le sketch
arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi arduino-rgb-blink

# Téléverser sur la carte (remplacer COM3 par votre port)
arduino-cli upload -p COM3 --fqbn arduino:renesas_uno:unor4wifi arduino-rgb-blink

# Moniteur série
arduino-cli monitor -p COM3 -c baudrate=9600
```

## 🎨 Couleurs de l'arc-en-ciel

Le programme affiche les couleurs suivantes en boucle :

| Ordre | Couleur  | Rouge | Vert | Bleu | Durée |
|-------|----------|-------|------|------|-------|
| 1     | Rouge    | 255   | 0    | 0    | 1s    |
| 2     | Vert     | 0     | 255  | 0    | 1s    |
| 3     | Bleu     | 0     | 0    | 255  | 1s    |
| 4     | Jaune    | 255   | 255  | 0    | 1s    |
| 5     | Cyan     | 0     | 255  | 255  | 1s    |
| 6     | Magenta  | 255   | 0    | 255  | 1s    |
| 7     | Blanc    | 255   | 255  | 255  | 1s    |

## ⚙️ Personnalisation

### Modifier la durée d'affichage

Changez la valeur de `DELAI_COULEUR` dans le code (en millisecondes) :

```cpp
const int DELAI_COULEUR = 1000; // 1000 ms = 1 seconde
```

### Ajouter ou modifier des couleurs

Modifiez le tableau `couleurs[]` :

```cpp
const Couleur couleurs[] = {
  {255, 0,   0,   "Rouge"},
  {255, 165, 0,   "Orange"}, // Nouvelle couleur
  // ... autres couleurs
};
```

N'oubliez pas de mettre à jour `NOMBRE_COULEURS` !

### Changer les broches utilisées

Modifiez les constantes en haut du code :

```cpp
const int PIN_ROUGE = 9;   // Changez selon vos besoins
const int PIN_VERT = 10;
const int PIN_BLEU = 11;
```

> ⚠️ **Important** : Utilisez uniquement des broches PWM (marquées ~ sur l'Arduino)

## 📖 Fonctionnement du code

### Structure du programme

1. **setup()** : Exécuté une fois au démarrage
   - Configure les broches en mode sortie
   - Initialise la communication série
   - Éteint la LED

2. **loop()** : Exécuté en boucle infinie
   - Affiche chaque couleur pendant 1 seconde
   - Passe à la couleur suivante
   - Recommence au début après la dernière couleur

3. **afficherCouleur()** : Fonction utilitaire
   - Contrôle les 3 broches RGB avec PWM
   - Paramètres : intensités rouge, vert, bleu (0-255)

### Principe PWM (Modulation de Largeur d'Impulsion)

Le PWM permet de contrôler l'intensité lumineuse en variant la durée des impulsions :
- **0** = LED éteinte
- **255** = Intensité maximale
- **Valeurs intermédiaires** = Intensité proportionnelle

## 🐛 Dépannage

| Problème | Solution |
|----------|----------|
| La LED ne s'allume pas | Vérifiez les connexions et l'orientation de la LED |
| Couleurs incorrectes | Vérifiez que vous utilisez une LED à **cathode commune** |
| Une couleur manquante | Vérifiez la résistance et la connexion de cette broche |
| Erreur de compilation | Assurez-vous d'avoir installé le package "Arduino UNO R4 Boards" |
| Port non détecté | Installez les pilotes USB pour l'Arduino Uno R4 WiFi |

## 📚 Ressources

- [Arduino UNO R4 WiFi - Documentation officielle](https://docs.arduino.cc/hardware/uno-r4-wifi)
- [Référence PWM Arduino](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)
- [Guide LED RGB](https://www.arduino.cc/en/Tutorial/Foundations/RGBLED)

## 📝 Licence

Ce projet est libre d'utilisation pour l'apprentissage et les projets personnels.

## 👨‍💻 Auteur

Créé avec Claude Code pour l'apprentissage de la programmation Arduino.

---

**Amusez-vous bien avec votre LED RGB arc-en-ciel ! 🌈✨**
