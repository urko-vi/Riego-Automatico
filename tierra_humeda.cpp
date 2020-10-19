#include <Arduino.h>


bool regar(int puertoAnalalogico) {
	int lectura = analogRead(puertoAnalalogico);
	int lecturaPorcentaje = map(lectura,1023,0,0,100);
	bool regar = false;
	//Serial.print(lecturaPorcentaje);
	//Serial.println(" %");
	if (lecturaPorcentaje < 37){
		Serial.println("Hay que regar");
		regar = true;
	} /*else {
		Serial.println("NO Hay que regar");
	}
	*/
	return regar;
}

