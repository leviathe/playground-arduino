#include <IRremote.h>

const char DIN_RECEPTEUR_INFRAROUGE = 2;
int vitesse=250;
int vitesse2=150;
IRrecv monRecepteurInfraRouge (DIN_RECEPTEUR_INFRAROUGE);

decode_results messageRecu;

//Moteur 1
const int mdbroche1  = 10;
const int mdbroche2  = 9;
//Moteur 2
const int mdbroche3  = 6;
const int mdbroche4  = 5;


void setup(){
//Configuration des broches en sortie
pinMode(mdbroche1, OUTPUT);
pinMode(mdbroche2, OUTPUT);
pinMode(mdbroche3, OUTPUT);
pinMode(mdbroche4, OUTPUT);
monRecepteurInfraRouge.enableIRIn();
monRecepteurInfraRouge.blink13(true);
}

void loop(){

if (monRecepteurInfraRouge.decode(&messageRecu))

  { 
    
if ((messageRecu.value==0x46F0DC1) || (messageRecu.value==0xFF00DA25)) {avant();}
if ((messageRecu.value==0x9D85DCE5) ||(messageRecu.value==0xFF00A25D)){arriere();}
if ((messageRecu.value==0x26E63EA5)|| (messageRecu.value==0xFF00807F)){droit();}
if ((messageRecu.value==0xEA21CEF5)|| (messageRecu.value==0xFF0050AF)){gauche();}
if ((messageRecu.value==0xE98F0789)|| (messageRecu.value==0xFF00629D)){arret();}
    delay(25);

    monRecepteurInfraRouge.resume();

  }

  delay(1);


}
/************ Sous programmes****************
*********************************************/

//+-+-+- sous programme avant +-+-+-+-
void avant(){
delay(1);
analogWrite(mdbroche1,vitesse);
analogWrite(mdbroche4,vitesse);
}
//+-+-+-+- sous programme arrière +-+-+-+-
void arriere(){
delay(1);
analogWrite(mdbroche2,vitesse);
analogWrite(mdbroche3,vitesse);
delay(1000);
analogWrite(mdbroche2,0);
analogWrite(mdbroche3,0);
}
//+-+-+-+- sous programme gauche +-+-+-+-
void gauche(){
analogWrite(mdbroche1,0);
analogWrite(mdbroche4,0);
analogWrite(mdbroche2,0);
analogWrite(mdbroche3,0);
delay(1);
analogWrite(mdbroche1,vitesse);
analogWrite(mdbroche4,vitesse2);
analogWrite(mdbroche1,0);
}
//+-+-+-+- sous programme droit +-+-+-+-
void droit(){
analogWrite(mdbroche1,0);
analogWrite(mdbroche4,0);
analogWrite(mdbroche2,0);
analogWrite(mdbroche3,0);
delay(1);
analogWrite(mdbroche4,vitesse);
analogWrite(mdbroche1,vitesse2);
analogWrite(mdbroche4,0);
}
//++-+-+-+- sous programme arret +-+-+-+-
void arret(){
analogWrite(mdbroche1,0);
analogWrite(mdbroche2,0);
analogWrite(mdbroche3,0);
analogWrite(mdbroche4,0);
delay(1000);
}
