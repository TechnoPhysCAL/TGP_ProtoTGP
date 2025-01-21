/*
  Librairie TPG ProtoTGP - ProtoTGP_sans_librairie.ino

  ### Démonstration de l'utilisation de la plateforme de développement ProtoTPhys sans la librairie ProtoTGP.

  Note: ###NOTE

*/

#include <BoutonPin.h> //Pour utiliser la librairie BoutonPin
#include <DelPin.h> //Pour utiliser la librairie DelPin
#include <Ecran.h> //Pour utiliser la librairie Ecran

#define PIN_BUTTON_GAUCHE 33
#define PIN_BUTTON_HAUT 34
#define PIN_BUTTON_BAS 35
#define PIN_BUTTON_SELECTION 36
#define PIN_BUTTON_DROITE 39

#define PIN_DEL_ROUGE 4
#define PIN_DEL_VERTE 2


Ecran ecran; 

BoutonPin gauche(PIN_BUTTON_GAUCHE); 
BoutonPin droite(PIN_BUTTON_DROITE);
BoutonPin haut(PIN_BUTTON_HAUT);
BoutonPin bas(PIN_BUTTON_BAS);
BoutonPin selection(PIN_BUTTON_SELECTION);

DelPin rouge(PIN_DEL_ROUGE);
DelPin verte(PIN_DEL_VERTE);


void setup()
{
  Serial.begin(115200);
  
  ecran.begin();

  gauche.begin();
  droite.begin();
  haut.begin();
  bas.begin();
  selection.begin();

  rouge.begin();
  verte.begin();
}

void loop()
{
  ecran.refresh();

  gauche.refresh();
  droite.refresh();
  haut.refresh();
  bas.refresh();
  selection.refresh();

  rouge.refresh();
  verte.refresh();
  

  if (haut.isPressed())
  {
    Serial.println("HAUT appuyé.");

    rouge.set(true); //Allume la DEL rouge.
    verte.set(true); //Allume la DEL verte.

    ecran.ecrire("Haut"); //Écrire le texte sur l'écran à la première ligne avec une taille de 1.
  }

  if (bas.isPressed())
  {
    Serial.println("BAS appuyé.");

    rouge.set(false); //Éteindre la DEL rouge.
    verte.set(false); //Éteindre la DEL verte.

    ecran.ecrire("Bas", 2); //Écrire le texte sur l'écran à la troisième ligne avec une taille de 1.
  }
  if (gauche.isPressed())
  {
    Serial.println("GAUCHE appuyé.");

    rouge.setBlinking(!rouge.getBlinking()); //Inverser le mode clignotement de la DEL rouge.

    ecran.ecrire("Gauche ", 1, 3); //Écrire le texte sur l'écran à la deuxième ligne avec une taille de 3.
  }
  if (droite.isPressed())
  {
    Serial.println("DROITE appuyé.");

    verte.setBlinking(!verte.getBlinking()); //Inverser le mode clignotement de la DEL verte.

    ecran.ecrire("Droite ", 3, 4); //Écrire le texte sur l'écran à la quatrième ligne avec une taille de 4.
  }
  if (selection.isPressed())
  {
    Serial.println("SELECTION appuyé.");

    ecran.ecrire("Sélection ", 0, 2); //Écrire le texte sur l'écran à la première ligne avec une taille de 2.
  }
}