void setup() {
  // Initialiser le pin digital LED_BUILTIN en tant que sortie
  pinMode(LED_BUILTIN, OUTPUT);
}

// La boucle fonctionne encore et encore indéfiniment
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Augmenter la luminosité en augmentant le voltage
  delay(3000);                       // Attendre une seconde
  digitalWrite(LED_BUILTIN, LOW);    // Diminuer la luminosité en diminuant le voltage
  delay(1000);
}                  
