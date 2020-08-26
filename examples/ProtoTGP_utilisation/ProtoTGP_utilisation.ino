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
  delay(50);
  Serial.println(proto.delRouge().get()?"TRUE":"FALSE");
  if (proto.haut().isPressed())
  {
    Serial.println("HAUT appuyé.");
    proto.delRouge().set(true);
    //proto.delVerte().set(true);
   // proto.ecran().printSmall("Haut");

  }

  if (proto.bas().isPressed())
  {
    Serial.println("BAS appuyé.");
    proto.delRouge().set(false);
   // proto.delVerte().set(false);
   // proto.ecran().printSmall("Bas");
  }
  if (proto.gauche().isPressed())
  {
    Serial.println("GAUCHE appuyé.");
    proto.delRouge().setBlinking(false);
   // proto.delVerte().setBlinking(false);
   // proto.ecran().printMedium("Gauche");
  }
  if (proto.droite().isPressed())
  {
    Serial.println("DROITE appuyé.");
    proto.delRouge().setBlinking(true);
   // proto.delVerte().setBlinking(true);
   // proto.ecran().printMedium("Droite");
  }
  if (proto.selection().isPressed())
  {
    Serial.println("SELECTION appuyé.");
    //proto.ecran().printLarge("Selection");
  }
}