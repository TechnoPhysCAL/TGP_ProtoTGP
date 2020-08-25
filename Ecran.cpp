#include "Ecran.h"

Ecran::Ecran() : adafruit(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{
}

Adafruit_SSD1306 Ecran::getAdafruit()
{
  return adafruit;
}

void Ecran::begin(*stream)
{
  Serial.println("Démarrage de l'écran....");
  bool answer = initializeScreen();
  delay(500);
  if (answer)
  {
    Serial.println("...Affichage démarré.");
    clear();
    //showSplashScreen();
    //delay(1500);
    //clear();
  }
  else
  {
    Serial.println("....Incapable de communiquer avec l'affichage'.");
  }
}
/*void Ecran::printSmall(char *msg)
{
  setFont(FONT_SMALL);
  writeFromBeginning(msg);
}
void Ecran::printMedium(char *msg)
{
  setFont(FONT_MEDIUM);
  writeFromBeginning(msg);
}
void Ecran::printLarge(char *msg)
{
  setFont(FONT_LARGE);
  writeFromBeginning(msg);
}
void Ecran::showSplashScreen()
{
  //printMedium("ProtoTPhys\n   2V1\n  09-2020\n   CAL");
}*/
void Ecran::clear()
{
  adafruit.clearDisplay();
}

int16_t Ecran::width()
{
  return adafruit.width();
}
int16_t Ecran::height()
{
  return adafruit.height();
}

bool Ecran::initializeScreen()
{
  return adafruit.begin(SSD1306_SWITCHCAPVCC, DEFAULT_ADDRESS); // initialize with the I2C addr, et reset
}
/*
void Ecran::setFont(int value)
{
  adafruit.setTextSize(value);
}

void Ecran::writeFromBeginning(char *msg)
{
  String buffer = msg;
  adafruit.setTextColor(WHITE);
  //adafruit.setCursor(0, 0);
  adafruit.print(buffer);
  //adafruit.display();
  Serial.println(buffer);
}*/