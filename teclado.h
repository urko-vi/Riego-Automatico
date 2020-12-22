#include <Keypad.h>


const byte rowsCount = 4;
const byte columsCount = 3;

class Teclado : public Keypad{

public:		
	Teclado();
	
	char getText();

};

