//Programme tests moteurs
//Moteur 1
const int mdbroche1 = 10;
const int mdbroche2 = 9;
//Moteur 2
const int mdbroche3 = 6;
const int mdbroche4 = 5;

int vitesse = 180;//Réglage de la vitesse

void setup(){
//Configuration des broches en sorties
pinMode(mdbroche1, OUTPUT);
pinMode(mdbroche2, OUTPUT);
pinMode(mdbroche3, OUTPUT);
pinMode(mdbroche4, OUTPUT);

//Contrôle du moteur 1 dans les deux directions
analogWrite(mdbroche1, vitesse);
delay(1000);
analogWrite(mdbroche1, 0);
delay(1000);
analogWrite(mdbroche2, vitesse);
delay(1000);
analogWrite(mdbroche2, 0);
delay(1000);

//Contrôle du moteur 2 dans les deux directions
analogWrite(mdbroche3, vitesse);
delay(1000);
analogWrite(mdbroche3, 0);
delay(1000);
analogWrite(mdbroche4, vitesse);
delay(1000);
analogWrite(mdbroche4, 0);
}
void loop(){
}
