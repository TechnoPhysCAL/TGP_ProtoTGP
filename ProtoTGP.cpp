#include "ProtoTGP.h"

ProtoTGP::ProtoTGP() : gauche(PIN_BUTTON_GAUCHE),
                       droite(PIN_BUTTON_DROITE),
                       haut(PIN_BUTTON_HAUT),
                       bas(PIN_BUTTON_BAS),
                       selection(PIN_BUTTON_SELECTION),
                       rouge(PIN_DEL_ROUGE),
                       verte(PIN_DEL_VERTE),
                       ecran()
{
}

void ProtoTGP::setDebounceDelay(unsigned long delay)
{
  gauche.setDebounceDelay(delay);
  droite.setDebounceDelay(delay);
  haut.setDebounceDelay(delay);
  bas.setDebounceDelay(delay);
  selection.setDebounceDelay(delay);
}
void ProtoTGP::setLongPressDelay(unsigned long delay)
{
  gauche.setLongPressDelay(delay);
  droite.setLongPressDelay(delay);
  haut.setLongPressDelay(delay);
  bas.setLongPressDelay(delay);
  selection.setLongPressDelay(delay);
}
void ProtoTGP::setLongPressInterval(unsigned long interval)
{
  gauche.setLongPressInterval(interval);
  droite.setLongPressInterval(interval);
  haut.setLongPressInterval(interval);
  bas.setLongPressInterval(interval);
  selection.setLongPressInterval(interval);
}

void ProtoTGP::begin()
{
  ecran.begin();
  gauche.begin();
  droite.begin();
  haut.begin();
  bas.begin();
  selection.begin();
  rouge.begin();
  verte.begin();
}
void ProtoTGP::refresh()
{
  ecran.refresh();
  gauche.refresh();
  droite.refresh();
  haut.refresh();
  bas.refresh();
  selection.refresh();
  rouge.refresh();
  verte.refresh();
}
