#include "momento.h";

Momento::Momento(){
	dia = 1;
	mes = 1;
	anyo= 2021;
	hora = 9;
	minutos= 0;
	segundos= 0;
	setHoraComp();
	setFechaComp();
}

void Momento::setDia(int day){
	dia = day;
}
void Momento::setMes(int temp){
	mes = temp;
}
void Momento::setAnyo(int year){
	anyo = year;
}
void Momento::setHora(int hour){
	hora = hour;
}
void Momento::setMinutos(int minutes){
	minutos = minutes;
}
void Momento::setSegundos(int seconds){
	segundos = seconds;
}
String Momento::getHoraComp(){
    return horaComp;
}
String Momento::getFechaComp(){
    return fechaComp;
}
String Momento::getHora(){
	String aux = "";
   if(hora > 9){
		aux += ""+hora;
	} else {
		aux += "0"+hora;
	}
	if(minutos > 9){
		aux += ":"+minutos;
	} else{
		aux += ":0"+minutos;
	}

   return aux;
}
void Momento::setHoraComp(){
	String aux ="";
	if(hora > 9){
		aux += ""+hora;
	} else {
		aux += "0"+hora;
	}
	if(minutos > 9){
		aux += ":"+minutos;
	} else{
		aux += ":0"+minutos;
	}
	if(segundos > 9){
		aux += ":"+segundos;
	} else{
		aux += ":0"+segundos;
	}
	horaComp = aux;
	
}
void Momento::setFechaComp(){
    String aux ="";

	if(dia > 9){
		aux += ""+dia;
	} else {
		aux += "0"+dia;
	}
	if(mes > 9){
		aux += "/"+mes;
	} else{
		aux += "/0"+mes;
	}

	aux += "/"+anyo;
	
	fechaComp = aux;
	
}
void Momento::setHoraComp(String hour){
    horaComp = hour;
}
void Momento::setFechaComp(String date){
    fechaComp = date;
}
