#include "momento.h";
#include <Arduino.h>
Momento::Momento(){
	dia = 1;
	mes = 1;
	anyo= 2021;
	hora = 0;
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
		Serial.print(""+hora);
		//Serial.print(":"+minutos);
		//Serial.println(":"+segundos);
   if(hora > 9){
		aux += ""+hora;
	} else {
		String hour = hora == 0?"0":""+hora;
		aux += "0"+hour;
	}
	if(minutos > 9){
		aux += ":"+minutos;
	} else{
		String minutes = minutos == 0?"0":""+minutos;
		aux += ":0"+minutes;
	}

   return aux;
}
void Momento::setHoraComp(){
	String aux ="";
	if(hora > 9){
		aux += ""+hora;
	} else {
		String hour = hora == 0?"0":""+hora;
		aux += "0"+hour;
	}
	if(minutos > 9){
		aux += ":"+minutos;
	} else{
		String minutes = minutos == 0?"0":""+minutos;
		aux += ":0"+minutes;
	}
	if(segundos > 9){
		aux += ":"+segundos;
	} else{
		String seconds = segundos == 0?"0":""+segundos;
		aux += ":0"+seconds;
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
