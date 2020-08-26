#ifndef ProtoTGP_h
#define ProtoTGP_h

#include "Arduino.h"
#include "BoutonPin.h"
#include "DELPin.h"
#include "Ecran.h"

#define PIN_BUTTON_GAUCHE 33
#define PIN_BUTTON_HAUT 34
#define PIN_BUTTON_BAS 35
#define PIN_BUTTON_SELECTION 36
#define PIN_BUTTON_DROITE 39

#define PIN_DEL_ROUGE 4
#define PIN_DEL_VERTE 2

/******************************************************************************
* Definitions
******************************************************************************/
class ProtoTGP
{
public:
    ProtoTGP();
    void begin();
    void refresh();

    BoutonPin gauche();
    BoutonPin droite();
    BoutonPin haut();
    BoutonPin bas();
    BoutonPin selection();

    DELPin delRouge();
    DELPin delVerte();
    
    Ecran ecran();

private:
    DELPin r;
    DELPin v;
    Ecran scr;
    BoutonPin g, d, h, b, s;
};
#endif
