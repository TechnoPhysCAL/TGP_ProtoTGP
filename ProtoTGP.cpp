#include "ProtoTGP.h"

ProtoTGP::ProtoTGP() : g(PIN_BUTTON_GAUCHE),
                       d(PIN_BUTTON_DROITE),
                       h(PIN_BUTTON_HAUT),
                       b(PIN_BUTTON_BAS),
                       s(PIN_BUTTON_SELECTION),
                       r(PIN_DEL_ROUGE),
                       v(PIN_DEL_VERTE),
                       scr()
{

}

void ProtoTGP::begin()
{
  scr.begin();
}
void ProtoTGP::refresh()
{
  g.refresh();
  d.refresh();
  h.refresh();
  b.refresh();
  s.refresh();
  r.refresh();
  v.refresh();
}

BoutonPin ProtoTGP::gauche() { return g; }
BoutonPin ProtoTGP::droite() { return d; }
BoutonPin ProtoTGP::haut() { return h; }
BoutonPin ProtoTGP::bas() { return b; }
BoutonPin ProtoTGP::selection() { return s; }
DELPin ProtoTGP::delRouge() { return r; }
DELPin ProtoTGP::delVerte() { return v; }
Ecran ProtoTGP::ecran() { return scr; }