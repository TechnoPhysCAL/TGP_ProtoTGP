/*
  Librairie TPG ProtoTGP - ProtoTGP_utilisation.ino

  ### Démonstration de l'utilisation de la classe ProtoTGP.

  Note: ###NOTE

*/

#include <ProtoTGP.h> //Pour utiliser la librairie ProtoTGP

ProtoTGP proto; //Création de l'objet 'proto', de type ProtoTGP
 
void setup()
{
  Serial.begin(115200);
  proto.begin(); //Permet le démarrage de la plateforme et l'initialisation de ses systèmes.
}

void loop()
{
  proto.refresh(); //Permet d'actualiser tout le système de la plateforme. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
  
  if (proto.haut.isPressed()) 
  {
    Serial.println("HAUT appuyé.");
    
    proto.rouge.set(true);  //Allume la DEL rouge.
    proto.verte.set(true);  //Allume la DEL verte.
    
    proto.ecran.ecrire("Haut "); //Écrire le texte sur l'écran (la taille du texte par défaut est 1).

  }

  if (proto.bas.isPressed())
  {
    Serial.println("BAS appuyé.");
    
    proto.rouge.set(false); //Éteindre la DEL rouge.
    proto.verte.set(false); //Éteindre la DEL verte.
    
    proto.ecran.ecrire("Bas ",5); //Écrire le texte sur l'écran avec une taille de 5.
  }
  if (proto.gauche.isPressed())
  {    
    Serial.println("GAUCHE appuyé."); 
    
    proto.rouge.setBlinking(!proto.rouge.getBlinking()); //Inverser le mode clignotement de la DEL rouge.

    proto.ecran.ecrire("Gauche ",3); //Écrire le texte sur l'écran avec une taille de 3.
  }
  if (proto.droite.isPressed())
  {
    Serial.println("DROITE appuyé."); 
   
    proto.verte.setBlinking(!proto.verte.getBlinking()); //Inverser le mode clignotement de la DEL verte.
    
    proto.ecran.ecrire("Droite ",4); //Écrire le texte sur l'écran avec une taille de 4.
  }
  if (proto.selection.isPressed())
  {
    Serial.println("SELECTION appuyé.");
    
    proto.ecran.ecrire("Selection ",2); //Écrire le texte sur l'écran avec une taille de 2.
  }
}