#include "Ecran.h"

Ecran::Ecran() : adafruit(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{
  _addI2C_OLED = DEFAULT_ADDRESS; //Adresse par défaut
}

Adafruit_SSD1306 Ecran::getAdafruit()
{
  return adafruit;
}

void Ecran::begin()
{
  if (initializeScreen())
  {
    Serial.println("> Affichage démarré.");
    clear();
    showSplashScreen();
    delay(1500);
    clear();
  }
  else
  {
    Serial.println("> Incapable de communiquer avec l'affichage'.");
  }
}
void Ecran::printSmall(const char msg[])
{
  setFont(FONT_SMALL);
  writeFromBeginning(msg);
}
void Ecran::printMedium(const char msg[])
{
  setFont(FONT_MEDIUM);
  writeFromBeginning(msg);
}
void Ecran::printLarge(const char msg[])
{
  setFont(FONT_LARGE);
  writeFromBeginning(msg);
}

void Ecran::clear()
{
  adafruit.clearDisplay();
  adafruit.display();
}

void Ecran::showSplashScreen()
{
  printMedium("ProtoTPhys\n   2V1\n  09-2020\n   CAL");
}

bool Ecran::initializeScreen()
{
  return adafruit.begin(SSD1306_SWITCHCAPVCC, _addI2C_OLED); // initialize with the I2C addr, et reset
}

void Ecran::setFont(int value)
{
  adafruit.setTextSize(value);
}

void Ecran::writeFromBeginning(const char msg[])
{
  adafruit.clearDisplay();
  adafruit.setCursor(0, 0);
  adafruit.print(msg);
  adafruit.display();
  Serial.println(msg);
}