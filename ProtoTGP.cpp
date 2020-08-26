#include "ProtoTGP.h"

ProtoTGP::ProtoTGP() : g(PIN_BUTTON_GAUCHE),
                       d(PIN_BUTTON_DROITE),
                       h(PIN_BUTTON_HAUT),
                       b(PIN_BUTTON_BAS),
                       s(PIN_BUTTON_SELECTION),
                       rouge(PIN_DEL_ROUGE),
                       verte(PIN_DEL_VERTE),
                       screen()
{
}

void ProtoTGP::begin()
{
  screen.begin();
}
void ProtoTGP::refresh()
{
  g.refresh();
  d.refresh();
  h.refresh();
  b.refresh();
  s.refresh();
  rouge.refresh();
  verte.refresh();
}

BoutonPin ProtoTGP::gauche() { return g; }
BoutonPin ProtoTGP::droite() { return d; }
BoutonPin ProtoTGP::haut() { return h; }
BoutonPin ProtoTGP::bas() { return b; }
BoutonPin ProtoTGP::selection() { return s; }
DELPin ProtoTGP::delRouge() { return rouge; }
DELPin ProtoTGP::delVerte() { return verte; }
Ecran ProtoTGP::ecran() { return screen; }