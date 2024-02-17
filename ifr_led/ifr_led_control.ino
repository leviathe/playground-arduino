//Programme Télécommande
#include <IRremote.h>
const char DIN_RECEPTEUR_INFRAROUGE = 2;
IRrecv monRecepteurInfraRouge (DIN_RECEPTEUR_INFRAROUGE);
decode_results messageRecu;
const int Led = 3;
void setup()
{
 Serial.begin(9600);
 monRecepteurInfraRouge.enableIRIn();
 monRecepteurInfraRouge.blink13(true);
 pinMode(Led,    OUTPUT);
}
void loop()
{
  if (monRecepteurInfraRouge.decode(&messageRecu))
  {
    if(messageRecu.value == 0x2758){digitalWrite(Led,HIGH);}
    if(messageRecu.value == 0x2759){digitalWrite(Led,LOW);}
    delay(10);
    monRecepteurInfraRouge.resume();
  }
  delay(1);
}
