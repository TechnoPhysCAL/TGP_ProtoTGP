#ifndef ProtoTGP_h
#define ProtoTGP_h

#include "Arduino.h"
#include "BoutonPin.h"
#include "DelPin.h"
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

    void setDebounceDelay(unsigned long);
	void setLongPressDelay(unsigned long);
	void setLongPressInterval(unsigned long);

    BoutonPin gauche, droite, haut, bas, selection;
    DelPin rouge, verte;
    Ecran ecran;

private:
};
#endif
