#include <Wire.h>      // libreria de comunicacion por I2C
#include <LCD.h>      // libreria para funciones de LCD
#include <LiquidCrystal_I2C.h>    // libreria para LCD por I2C
#include "datos_app.h";
#include "teclado.h"
#include "reloj_sensor.h";

//
class Menu {

public:
	char option;
	DatosApp datos;
	Menu();
	Menu(LiquidCrystal_I2C *screen);
	char loadOption(LiquidCrystal_I2C *screen,char op=0);
	char showHome(LiquidCrystal_I2C *screen);
	char showFecha(LiquidCrystal_I2C *screen,Teclado keypad,Reloj reloj);
	char showHora(LiquidCrystal_I2C *screen,Teclado keypad,Reloj reloj);
	char showWifi(LiquidCrystal_I2C *screen,Teclado keypad);
private:
	void showMenu(LiquidCrystal_I2C *screen);
	void clean(LiquidCrystal_I2C *screen);
	void showBar(LiquidCrystal_I2C *screen);
};