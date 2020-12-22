#include <Arduino.h>
#include "pantalla_lcd.h"    // libreria para LCD por I2C

Menu::Menu(){
	option = '0';
	datos = DatosApp();
}	

void Menu::loadOption(LiquidCrystal_I2C *screen,char op){
	option = op;
	//
	
	//Serial.println(option);
	switch (option){
		case '0':{
			
			showHome(screen);
		}
		break;
		case '1':
		break;
		case '2':
		break;
		case '3':
		break;
	}
}
void Menu::showHome(LiquidCrystal_I2C *screen){


   
	/*
	Atmosfera at = atmosferas[0];
	screen->print(" T.:");   //
	screen->print(at.getTemperatura());   //
	screen->print((char)223);     // escribe seg.
	screen->print(" Hum:"); 
	screen->print(at.getHumedad());
	*/
	/*
	
	at = atmosferas[1];
	screen->print("T Ex:");   //
	screen->print(at.getTemperatura());   //
	screen->print((char)223); 
	screen->print("H In:"); 
	screen->print(at.getHumedad());
	*/
	screen->setCursor(0, 1);    // ubica cursor en columna 0 y linea 2
	screen->setCursor(0, 2);    // ubica cursor en columna 0 y linea 3	
	screen->setCursor(0, 3); // ubica cursor en columna 0 y linea 4 
	//screen->print("Pulse una tecla");  // escribe el texto
}
// Private :
//
void Menu::showBar(LiquidCrystal_I2C *screen){
	byte wifiOn[] = {
	  B00000,
	  B00001,
	  B00011,
	  B00111,
	  B01111,
	  B11111,
	  B11111,
	  B11111
	};
	byte wifiOff[] = {
	  B00001,
	  B00011,
	  B00011,
	  B00011,
	  B00011,
	  B10111,
	  B01011,
	  B10111
	};
	byte bluetoohOn[] = {
	  B00100,
	  B00110,
	  B10101,
	  B01110,
	  B01110,
	  B10101,
	  B00110,
	  B00100
	};


	byte bluetoohOff[] = {
	  B00100,
	  B00110,
	  B00101,
	  B00110,
	  B00101,
	  B10110,
	  B01000,
	  B10100
	};

	byte waterOn[] = {
	  B00100,
	  B00100,
	  B01110,
	  B01110,
	  B11111,
	  B11111,
	  B11111,
	  B01110
	};
	byte waterOff[] = {
		B00100, B00100, B01010, B01010, B10001, B10001, B10001, B01110
	};

	byte termometro[]={B00100, B01010, B01010, B01110, B01110, B11111, B11111, B01110}; //icon for termometer

	Atmosfera at = datos.getAtmosferas().atmosferas[0];
	String hora = datos.getMomento().getHora();
	byte wifi = datos.getStatus().wifi ? wifiOn : wifiOff;
	byte bluetooh = datos.getStatus().bluetooh ? wifiOn : wifiOff;
	byte water = datos.getStatus().agua ? waterOn : waterOff;
	clean(screen);
	
	
	screen->setCursor(0, 0);    // ubica cursor en columna 0 y linea 1
	screen->print(hora+" "+at.getTemperatura()+""+(char)223+" "+hora+" "+wifi+""+bluetooh+""+water);
}
void Menu::clean(LiquidCrystal_I2C *screen){
	screen->setBacklightPin(3,POSITIVE); // puerto P3 de PCF8574 como positivo
	screen->setBacklight(HIGH);   // habilita iluminacion posterior de LCD
	screen->begin(20, 4);     // 20 columnas por 4 lineas para LCD 
	screen->clear();      // limpia pantalla
	screen->setCursor(0, 0);
	
}
