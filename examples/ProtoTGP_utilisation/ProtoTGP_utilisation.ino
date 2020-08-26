/*
  Librairie TPG ProtoTGP - ProtoTGP_utilisation.ino

  ###DESCRIPTION

  Note: ###NOTE

*/

#include <ProtoTGP.h> //Pour utiliser la librairie ProtoTGP

ProtoTGP proto;

void setup()
{
  Serial.begin(115200);
  proto.begin(); //Permet le démarrage de la plateforme et l'initialisation de ses systèmes.
}

void loop()
{
  proto.refresh(); //Permet d'actualiser tout le système de la plateforme. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
  //delay(25);
  //Serial.println(proto.delRouge().get()?"TRUE":"FALSE");
  if (proto.haut().isPressed())
  {
    Serial.println("HAUT appuyé.");
    proto.rouge.set(true);  //POUR LA DEL LA FONCTION ROUGE() NE FONCTIONNE PAS.
    proto.verte.set(true);
    proto.screen.printSmall("Haut ");  // LA FONCTION ECRAN() NE FONCTIONNE PAS.

  }

  if (proto.bas().isPressed())
  {
    Serial.println("BAS appuyé.");
    proto.rouge.set(false);
    proto.verte.set(false);
    proto.screen.printSmall("Bas ");
  }
  if (proto.gauche().isPressed())
  {
    Serial.println("GAUCHE appuyé.");
    proto.rouge.setBlinking(!proto.rouge.getBlinking());

    proto.screen.printSmall("Gauche ");
  }
  if (proto.droite().isPressed())
  {
    Serial.println("DROITE appuyé.");
    proto.verte.setBlinking(!proto.verte.getBlinking());
    proto.screen.printSmall("Droite ");
  }
  if (proto.selection().isPressed())
  {
    Serial.println("SELECTION appuyé.");
    proto.screen.printSmall("Selection ");
  }
}