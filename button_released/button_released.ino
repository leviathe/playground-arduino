// les constantes ne changeront pas. Ils sont utilisés ici pour définir les numéros de broche:
const int buttonPin = 2;    // le numéro de la broche du bouton poussoir
const int ledPin = 10;      // le numéro de la broche de la DEL

// Variables will change:
int ledState = HIGH;         // l'état actuel de la broche de sortie
int buttonState;             // la lecture actuelle de la broche d'entrée
int lastButtonState = HIGH;   // la lecture précédente de la broche d'entrée


// les variables suivantes sont non signées longues car le temps, mesuré en
// millisecondes, deviendra rapidement un nombre plus grand que ce qui peut être stocké dans un int.
unsigned long lastDebounceTime = 0;  // la dernière fois que la broche de sortie a été basculée
unsigned long debounceDelay = 50;    // le temps de rebond; augmenter si la sortie scintille

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
 // lit l'état du commutateur dans une variable locale:
  int reading = digitalRead(buttonPin);

// vérifie si tu as juste appuyé sur le bouton, (l'entrée est passée de LOW à HIGH) et vous avez attendu assez longtemps depuis la dernière pression pour ignorer le bruit:

// Si le commutateur a changé, à cause du bruit ou en appuyant sur:
  if (reading != lastButtonState) {
    // réinitialiser le minuteur anti-rebond
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
// quelle que soit la lecture, il existe depuis plus longtemps que le rebond, delay, prenez-le comme l'état actuel:
    // si l'état du bouton a changé:
    if (reading != buttonState) {
      buttonState = reading;

      // n'inclue la LED que si le nouvel état du bouton est HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // régler le voyant:
  digitalWrite(ledPin, ledState);

  // sauvegarde la lecture. La prochaine fois dans la boucle, ce sera le lastButtonState:
  lastButtonState = reading;
}
