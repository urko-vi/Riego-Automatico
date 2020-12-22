#include "teclado.h"
#include "Arduino.h"
byte row[rowsCount] = { 13, 12, 11, 10 };
byte column[columsCount] = { 9, 8, 7 };

char claves[rowsCount][columsCount] = {
	   { '1','2','3' },
	   { '4','5','6' },
	   { '7','8','9' },
	   { '#','0','*' }
	};


Teclado::Teclado(): Keypad(makeKeymap(claves), row, column, rowsCount, columsCount) {
}


char Teclado::getText(){
	return this->getKey();
	 
}

