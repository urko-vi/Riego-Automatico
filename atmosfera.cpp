#include "atmosfera.h";

Atmosfera::Atmosfera(){
    nombre = "";
    descripcion = "";
    humedad = 0.0;
    temperatura = 0.0;
}

void Atmosfera::setHumedad(float hum){
	humedad = hum;
}
float Atmosfera::getHumedad(){
    return humedad;
}
void Atmosfera::setTemperatura(float temp){
	temperatura = temp;
}
float Atmosfera::getTemperatura(){
    return temperatura;
}
