#include "planta.h";

Planta::Planta(){
    nombre = "";
    descripcion = "";
    humedad = 0.0;
}

void Planta::setHumedad(float hum){
	humedad = hum;
}
float Planta::getHumedad(){
    return humedad;
}