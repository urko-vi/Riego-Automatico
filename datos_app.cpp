#include "datos_app.h"

DatosApp::DatosApp(){
	atmosferas = Atmosferas();
	momento = Momento();
	plantas = Plantas();
	status = Status();
}

Atmosferas DatosApp::getAtmosferas(){
	return atmosferas;
}
void DatosApp::setAtmosferas(Atmosferas atms){
	atmosferas = atms;
}
Momento DatosApp::getMomento(){
	return momento;
}
void DatosApp::setMomento(Momento moment){
	momento = moment;
}
void DatosApp::setMomento(DateTime *dt){
	momento.setMomento(dt);
}
Plantas DatosApp::getPlantas(){
	return plantas;
}
void DatosApp::setPlantas(Plantas plants){
	plantas = plants;
}	
Status DatosApp::getStatus(){
	return status;
}
void DatosApp::setStatus(Status stats){
	status = stats;
}		


