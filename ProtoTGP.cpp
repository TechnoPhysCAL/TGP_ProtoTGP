#include "ProtoTGP.h"

ProtoTGP::ProtoTGP() : g(33), d(39), h(34), b(35), s(36), r(4), v(2), scr()
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

Bouton ProtoTGP::gauche() { return g; }
Bouton ProtoTGP::droite() { return d; }
Bouton ProtoTGP::haut() { return h; }
Bouton ProtoTGP::bas() { return b; }
Bouton ProtoTGP::selection() { return s; }
DELPin ProtoTGP::delRouge() { return r; }
DELPin ProtoTGP::delVerte() { return v; }
Ecran ProtoTGP::ecran() { return scr; }