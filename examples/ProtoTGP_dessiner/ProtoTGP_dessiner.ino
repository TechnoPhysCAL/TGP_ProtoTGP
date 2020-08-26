/*
  Librairie TPG ProtoTGP - ProtoTGP_dessiner.ino

  ### Démonstration de l'utilisation de la classe ProtoTGP en implémentant une planche à dessin de type "Etch-A-Sketch".
  ### On déplace le curseur dans l'écran avec les boutons (GAUCHE, DROITE, HAUT, BAS);
  ### On peut effacer le dessin en appuyant longuement sur le bouton Selection. La DEL rouge nous avertira de l'effacement imminent du dessin.
  
  Note: ###NOTE

*/

#include <ProtoTGP.h> //Pour utiliser la librairie ProtoTGP

ProtoTGP proto; //Création de l'objet 'proto', de type ProtoTGP

//On initialise les coordonnées du curseur (x,y) dans l'image, au centre.
int x = 64;
int y = 32;

void setup()
{
  Serial.begin(115200);
  proto.begin(); //Permet le démarrage de la plateforme et l'initialisation de ses systèmes.

  proto.rouge.setBlinking(true);       //La DEL rouge sera en mode clignotement.
  proto.rouge.setBlinkingInterval(50); //La DEL rouge aura un délai de clignotement de 50 millisecondes.

  proto.setLongPressDelay(250);   //Ajuster le délai avant le long clic à 250 millisecondes pour tous les boutons.
  proto.setLongPressInterval(50); //Ajuster l'intervalle des longs clics à 50 millisecondes pour tous les boutons.

  proto.selection.setLongPressDelay(1000); //Pour le bouton SELECTION seulement, ajuster le délai avant le long clic à 1000 millisecondes.

  proto.ecran.ecrire("GAUCHE, DROITE, HAUT,\nBAS => deplacer le\ncurseur.\n\nSELECTION => effacer.", 1); //Afficher un texte explicatif.
  delay(5000);
  proto.ecran.ecrire(" A votre\n tour de\n dessiner!", 2); //Afficher un texte invitant.
  delay(2000);                                             //Attendre que l'utilisateur lise le texte
  proto.ecran.effacer();                                   //Effacer l'écran
  imprimerXY();                                            //Imprimer le premier point
}

void loop()
{
  proto.refresh(); //Permet d'actualiser tout le système de la plateforme. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  if (proto.gauche.isPressed() || proto.gauche.isLongPressed()) //Si le bouton GAUCHE est appuyé ou longuement appuyé:
  {
    x -= 1; //Soustraire 1 de la coordonnée x;
    if (x < 0)
    {
      x = 0;
    } //Empêcher x d'être inférieur à 0.
    imprimerXY();
  }

  if (proto.droite.isPressed() || proto.droite.isLongPressed()) //Si le bouton DROITE est appuyé ou longuement appuyé:
  {
    x += 1; //Ajouter 1 de la coordonnée x;
    if (x >= proto.ecran.width())
    {
      x = proto.ecran.width() - 1;
    } //Empêcher x d'être supérieur à la largeur maximale-1.
    imprimerXY();
  }
  if (proto.haut.isPressed() || proto.haut.isLongPressed()) //Si le bouton HAUT est appuyé ou longuement appuyé:
  {
    y -= 1; //Soustraire 1 de la coordonnée y;
    if (y < 0)
    {
      y = 0;
    } //Empêcher y d'être inférieur à 0.
    imprimerXY();
  }

  if (proto.bas.isPressed() || proto.bas.isLongPressed()) //Si le bouton BAS est appuyé ou longuement appuyé:
  {
    y += 1; //Ajouter 1 de la coordonnée y;
    if (y >= proto.ecran.height())
    {
      y = proto.ecran.height() - 1;
    } //Empêcher y d'être supérieur à la hauteur maximale-1.
    imprimerXY();
  }

  if (proto.selection.isPressed())
  {                        //Si le bouton SELECTION est appuyé
    proto.rouge.set(true); //Allumer la DEL rouge.
  }

  if (proto.selection.isReleased())
  {                                //Si le bouton SELECTION est relaché
    proto.rouge.set(false);        //Éteindre la DEL rouge.
    proto.rouge.setBlinking(true); //Activer le mode clignotement.
    imprimerXY();                   //Imprimer le premier point.
  }

  if (proto.selection.isLongPressed())
  {                                 //Si le bouton SELECTION est longuement appuyé
    proto.ecran.effacer();          //Effacer l'écran
    proto.rouge.setBlinking(false); //Désactiver le mode clignotement.
    
  }
}

void imprimerXY()
{
  proto.ecran.dessinerPixel(x, y); //Ajouter un pixel sur l'écran, à la coordonnée du curseur.

  //Pour les fins de débogage, envoyer la coordonnée sur le port Série.
  char msg[20];                  //Créer une chaîne de caractère de taille 100.
  sprintf(msg, "(%d,%d)", x, y); //Formater le message sous la forme (x,y).
  Serial.println(msg);           //Envoyer le message sur le port Série.
}
