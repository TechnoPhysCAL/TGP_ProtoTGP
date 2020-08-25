#ifndef ProtoTGP_h
#define ProtoTGP_h

#include "Arduino.h"
#include "BoutonPin.h"
#include "DELPin.h"
#include "Ecran.h"

/******************************************************************************
* Definitions
******************************************************************************/
class ProtoTGP
{
public:
    ProtoTGP();
    void begin();
    void refresh();

    Bouton gauche();
    Bouton droite();
    Bouton haut();
    Bouton bas();
    Bouton selection();

    DELPin delRouge();
    DELPin delVerte();
    
    Ecran ecran();

private:
    DELPin r,v;
    Ecran scr;
    BoutonPin g, d, h, b, s;
};
#endif
