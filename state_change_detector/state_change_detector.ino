// cette constante ne changera pas:
const int  buttonPin = 2;    // l'épingle à laquelle le bouton-poussoir est attaché
const int ledPin = 10;       // la broche à laquelle la LED est attachée

// Variables will change:
int buttonPushCounter = 0;   // compteur du nombre de pressions sur les boutons
int buttonState = 0;         // état actuel du bouton
int lastButtonState = 0;     // état précédent du bouton

void setup() {
  // initialise la broche du bouton en tant qu'entrée:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialise la LED en tant que sortie:
  pinMode(ledPin, OUTPUT);
  // initialise la communication série:
  Serial.begin(9600);
}


void loop() {
  // lit la broche d'entrée du bouton-poussoir:
  buttonState = digitalRead(buttonPin);

  // compare le boutonState à son état précédent
  if (buttonState != lastButtonState) {
    // si l'état a changé, incrémente le compteur
    if (buttonState == HIGH) {
     // si l'état actuel est HIGH, le bouton est passé à on:
      buttonPushCounter++;
      Serial.println("on");
    } else {
      // si l'état actuel est BAS alors le bouton est passé à on:
      Serial.println("off");
    }
    // Retarde un peu pour éviter de rebondir
    delay(50);
  }
  // enregistre l'état actuel en tant que dernier état pour la prochaine fois dans la boucle
  lastButtonState = buttonState;

   // allume la LED tous les quatre boutons en vérifiant le modulo du bouton
   // bouton push counter. la fonction modulo vous donne le reste de la
   // division de deux nombres:
  if (buttonPushCounter % 5 == 0) {
    digitalWrite(ledPin, HIGH);
     Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
