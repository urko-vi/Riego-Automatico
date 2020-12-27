#include <Arduino.h>
#include "pantalla_lcd.h"    // libreria para LCD por I2C


Menu::Menu(){
	option = '0';
	datos = DatosApp();
}

Menu::Menu(LiquidCrystal_I2C *screen){
	uint8_t waterOn[8]  = {0x04,0x04,0x0E,0x0E,0x1F,0x1F,0x1F,0x0E};
	uint8_t waterOff[8]  = {0x04,0x04,0x0A,0x0A,0x11,0x11,0x11,0x0E};
	uint8_t wifiOn[8]  = {0x00,0x01,0x03,0x07,0x0F,0x1F,0x1F,0x1F};
	uint8_t wifiOff[8]  = {0x00,0x00,0x00,0x01,0x03,0x17,0x0B,0x17};
	uint8_t bluetoothOn[8]  = {0x04,0x06,0x05,0x16,0x0E,0x15,0x06,0x04};
	uint8_t bluetoothOff[8]  = {0x00,0x02,0x0B,0x06,0x06,0x0B,0x02,0x00};
	uint8_t noNet[8] = {0x00,0x00,0x00,0x11,0x0A,0x04,0x0A,0x11};
	uint8_t sun[8] = {0x00,0x00,0x15,0x0E,0x1F,0x0E,0x15,0x00};
	
	screen->createChar(0, waterOn);
	screen->createChar(1, waterOff);
	screen->createChar(2, wifiOn);
	screen->createChar(3, wifiOff);
	screen->createChar(4, bluetoothOn);
	screen->createChar(5, bluetoothOff);
	screen->createChar(6, noNet);
	screen->createChar(7, sun);
}	

char Menu::loadOption(LiquidCrystal_I2C *screen,char op){
	option = op;

	char clave = '*';
	
	//Serial.println(option);
	switch (option){
		case '1':{ // home
			clean(screen);
			showBar(screen);
			clave = showHome(screen);
		}
		break;
		case '2':{ // ajuste fecha 
			clean(screen);
			//showFecha(screen);
			clave = '1';
			//Serial.println(option);
		}	
		break;		
		case '3':{// ajuste hora 
			clean(screen);
			//showHora(screen);
			clave = '2';
		}
		break;
		case '4':{// ajuste wifi
			clean(screen);
			//showWifi(screen);
			clave = '3';
		}
		break;
		case '/':{//Error
		}
		break;
	}
	return clave;
}
char Menu::showHome(LiquidCrystal_I2C *screen){
	screen->setCursor(0, 1);    // ubica cursor en columna 0 y linea 2
	screen->print("1.Principal  2.Fecha");
	screen->setCursor(0, 2);    // ubica cursor en columna 0 y linea 3
	screen->print("3.Hora       4.Wifi");	
	screen->setCursor(0, 3); // ubica cursor en columna 0 y linea 4 
	//screen->print("Pulse una tecla");  // escribe el texto
	return '*';
}
char Menu::showFecha(LiquidCrystal_I2C *screen,Teclado keypad,Reloj reloj){
	screen->setCursor(0, 0);    // ubica cursor en columna 0 y linea 2
	screen->print(" AJUSTE FECHA");
	screen->setCursor(0, 1);    // ubica cursor en columna 0 y linea 2
	screen->print("");
	screen->print("/00/");
	screen->print(" 2020");
	screen->setCursor(0, 2);    // ubica cursor en columna 0 y linea 3
	screen->print("");	
	screen->setCursor(0, 3); // ubica cursor en columna 0 y linea 4 
	screen->print("# Aceptar * Cancelar");  // escribe el texto
	char text = keypad.waitForKey();
	return text;
}
char Menu::showHora(LiquidCrystal_I2C *screen,Teclado keypad,Reloj reloj){
	screen->setCursor(0, 0);    // ubica cursor en columna 0 y linea 2
	screen->print(" AJUSTE HORA");
	screen->setCursor(0, 1);    // ubica cursor en columna 0 y linea 2
	//screen->print("");
	screen->setCursor(0, 2);    // ubica cursor en columna 0 y linea 3
	//screen->print("3.Wifi  4.");	
	screen->setCursor(0, 3); // ubica cursor en columna 0 y linea 4 
	screen->print("# Aceptar * Cancelar");  // escribe el texto
	char text = keypad.waitForKey();
	return text;
}
char Menu::showWifi(LiquidCrystal_I2C *screen,Teclado keypad){
	screen->setCursor(0, 0);    // ubica cursor en columna 0 y linea 2
	screen->print(" AJUSTE WIFI");
	screen->setCursor(0, 1);    // ubica cursor en columna 0 y linea 2
	//screen->print("");
	screen->setCursor(0, 2);    // ubica cursor en columna 0 y linea 3
	//screen->print("3.Wifi  4.");	
	screen->setCursor(0, 3); // ubica cursor en columna 0 y linea 4 
	screen->print("# Aceptar * Cancelar");  // escribe el texto
	char text = keypad.waitForKey();
	return text;
}
// Private :
//
void Menu::showBar(LiquidCrystal_I2C *screen){


	Atmosfera at = datos.getAtmosferas().atmosferas[0];
	String hora = datos.getMomento().getHora();
	Serial.println(""+hora+" "+at.getTemperatura()+"");
	
	screen->setCursor(0, 0);    // ubica cursor en columna 0 y linea 1

	screen->print(""+hora+" "+at.getTemperatura()+""+(char)223);
	if(!datos.getStatus().wifi){
	//	screen->write(6);
	} 
	uint8_t i = datos.getStatus().wifi? 2 : 3; 
	screen->write(i);
/*
	if(!datos.getStatus().bluetooth){
		//screen->write(6);
	}
	i = datos.getStatus().bluetooth? 4 : 5; 
	
	screen->write(i);
	*/
	i = datos.getStatus().agua? 0 : 1; 
	screen->write(i);
}
void Menu::clean(LiquidCrystal_I2C *screen){
	//screen->setBacklightPin(3,POSITIVE); // puerto P3 de PCF8574 como positivo
	//screen->setBacklight(HIGH);   // habilita iluminacion posterior de LCD
	//screen->begin(20, 4);     // 20 columnas por 4 lineas para LCD 
	screen->clear();      // limpia pantalla
	screen->setCursor(0, 0);
	
}
