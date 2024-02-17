//Programme Télécommande
#include <IRremote.h>
const char DIN_RECEPTEUR_INFRAROUGE = 2;
IRrecv monRecepteurInfraRouge (DIN_RECEPTEUR_INFRAROUGE);
decode_results messageRecu;
void setup()
{
 Serial.begin(9600);
 monRecepteurInfraRouge.enableIRIn();
 monRecepteurInfraRouge.blink13(true);
}
void loop()
{
  if (monRecepteurInfraRouge.decode(&messageRecu))
  {
    if(messageRecu.value == 0x2758){Serial.println("touche HAUT");}
    if(messageRecu.value == 0x1275A){Serial.println("touche GAUCHE");}
    if(messageRecu.value == 0x2759){Serial.println("touche BAS");}
    if(messageRecu.value == 0x1275B){Serial.println("touche DROITE");}
    if(messageRecu.value == 0x275C ){Serial.println("touche OK");}
    delay(500);
    monRecepteurInfraRouge.resume();
  }
  delay(1);
}
