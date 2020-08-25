#ifndef Ecran_h
#define Ecran_h

#include "Arduino.h"
#include "Adafruit_SSD1306.h" //Pour l,affichage OLED
#include <Wire.h>             //Pour l'affichage OLED

#define DEFAULT_ADDRESS 0x3C

#define OLED_RESET -1    //Si pas nécessaire, il faut alors mettre <= 0
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define FONT_SMALL 1
#define FONT_MEDIUM 2
#define FONT_LARGE 4
/******************************************************************************
* Definitions
******************************************************************************/
class Ecran
{
public:
    Ecran();

    //Design oriented
    void begin();
    void clear();
    void showSplashScreen();
    void printSmall(const char[]);
    void printMedium(const char[]);
    void printLarge(const char[]);


    //Hardware oriented
    bool initializeScreen();
    void setFont(int);
    void writeFromBeginning(const char[]);

    Adafruit_SSD1306 getAdafruit();

private:
    Adafruit_SSD1306 adafruit;
    int _addI2C_OLED;
};
#endif
