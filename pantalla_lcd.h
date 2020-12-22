#include <Wire.h>      // libreria de comunicacion por I2C
#include <LCD.h>      // libreria para funciones de LCD
#include <LiquidCrystal_I2C.h>    // libreria para LCD por I2C
#include "datos_app.h";

//
class Menu {

public:
	char option;
	DatosApp datos;
	Menu();
	void loadOption(LiquidCrystal_I2C *screen,char op=0);
	void showHome(LiquidCrystal_I2C *screen);
private:
	void showMenu(LiquidCrystal_I2C *screen);
	void clean(LiquidCrystal_I2C *screen);
	void showBar(LiquidCrystal_I2C *screen);
	
};