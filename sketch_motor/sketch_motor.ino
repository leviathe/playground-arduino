//Programme commande moteurs
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


}

void loop(){
avant();
droit();
avant();
arret();
arriere();
gauche();
arret2();
}

//+-+-+- sous programme avant +-+-+-+-
void avant(){
analogWrite(mdbroche1,0); //sécurité
analogWrite(mdbroche2,0); //sécurité
analogWrite(mdbroche3,0); //sécurité
analogWrite(mdbroche4,0); //sécurité
delay(200);
analogWrite(mdbroche1,vitesse);
analogWrite(mdbroche4,vitesse);
delay(5000);

}
//+-+-+-+- sous programme arrière +-+-+-+-
void arriere(){
analogWrite(mdbroche1,0);
analogWrite(mdbroche2,0);
analogWrite(mdbroche3,0);
analogWrite(mdbroche4,0);
delay(200);
analogWrite(mdbroche2,vitesse);
analogWrite(mdbroche3,vitesse);
delay(3000);

}
//+-+-+-+- sous programme gauche +-+-+-+-
void gauche(){
analogWrite(mdbroche1,0);
analogWrite(mdbroche2,0);
analogWrite(mdbroche3,0);
analogWrite(mdbroche4,0);
delay(200);
analogWrite(mdbroche4,vitesse);
delay(2000);

}
//+-+-+-+- sous programme droit +-+-+-+-
void droit(){
analogWrite(mdbroche1,0);
analogWrite(mdbroche2,0);
analogWrite(mdbroche3,0);
analogWrite(mdbroche4,0);
delay(200);
analogWrite(mdbroche1,vitesse);
delay(2000);

}
//++-+-+-+- sous programme arret +-+-+-+-
void arret(){
analogWrite(mdbroche1,0);
analogWrite(mdbroche2,0);
analogWrite(mdbroche3,0);
analogWrite(mdbroche4,0);
delay(2000);

}
//++-+-+-+- sous programme arret2 +-+-+-+-
void arret2(){
analogWrite(mdbroche1,0);
analogWrite(mdbroche2,0);
analogWrite(mdbroche3,0);
analogWrite(mdbroche4,0);
delay(10000);
}
