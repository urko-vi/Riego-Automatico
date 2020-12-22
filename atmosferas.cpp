#include "atmosferas.h";

Atmosferas::Atmosferas(){
	length = 1;
	Atmosfera atmosferas[] = {Atmosfera()};
}

void Atmosferas::setAtmosferas(Atmosfera atmos[],int len){
	length = len;
	atmosferas[len];
	for(int i = 0; i < len; i++){
		atmosferas[i] = atmos[i];
	}
}
void Atmosferas::addAtmosfera(Atmosfera atm){
	//int length = getLength();
	int len = length +1;

	Atmosfera aux[len];
	
	for(int i = 0; i< length; i++){
		aux[i] = atmosferas[i];
	}
	aux[length] = atm;
	length = len;
}
void Atmosferas::setLength(int len){
	length = len;
}
int Atmosferas::getLength(){
	return length;
}
