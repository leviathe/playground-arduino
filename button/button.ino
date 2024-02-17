// les constantes ne changeront pas. Ils sont utilisés ici pour définir les numéros de broche:

const int buttonPin = 2;     // le numéro du pin
const int ledPin =  10;      // Le numéro du pin de la DEL

// les variables vont changer:
int buttonState = 0;         // variable pour lire l'état du bouton

void setup() {
  // initialise la broche LED en tant que sortie:
  pinMode(ledPin, OUTPUT);
  // initialise le bouton-poussoir en tant qu'entrée:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // lit l'état de la valeur du bouton-poussoir:
  buttonState = digitalRead(buttonPin);

  // vérifie si le bouton-poussoir est enfoncé. Si c'est le cas, l'état du bouton est HAUT:
  if (buttonState == HIGH) {
    //DEL on:
    digitalWrite(ledPin, LOW);
  } else {
    //DEL off:
    digitalWrite(ledPin, HIGH);
  }
}
