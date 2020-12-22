#include "plantas.h";

Plantas::Plantas(){
	length = 1;
	Planta plantas[] = {Planta()};
}

void Plantas::setPlantas(Planta plants[],int len){
	length = len;
	plantas[len];
	for(int i = 0; i < len; i++){
		plantas[i] = plants[i];
	}
}
void Plantas::addPlanta(Planta plant){
	//int length = getLength();
	int len = length +1;

	Planta aux[len];
	
	for(int i = 0; i< length; i++){
		aux[i] = plantas[i];
	}
	aux[length] = plant;
	length = len;
}
void Plantas::setLength(int len){
	length = len;
}
int Plantas::getLength(){
	return length;
}
