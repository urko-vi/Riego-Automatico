#include "momento.h"
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
void  Momento::setMomento(DateTime *dt){
	dia = dt->day();
	
	mes = dt->month();
	anyo = dt->year();
	hora= dt->hour();
	minutos=dt->minute();
	segundos=dt->second();
	//Serial.print(hora);	
	//Serial.print(minutos);	

	setHoraComp();
	setFechaComp();	
	
/*	
 Serial.print(dt.year(), DEC);
  Serial.print('/');
  Serial.print(dt.month(), DEC);
  Serial.print('/');
  */
  
 // Serial.print(dia);
  /*
  Serial.print("\t");
  Serial.print(dt.hour(), DEC);
  Serial.print(':');
  Serial.print(dt.minute(), DEC);
  Serial.print(':');
  Serial.print(dt.second(), DEC);
  */
  //Serial.println();
}
String Momento::getHoraComp(){
    return horaComp;
}
String Momento::getFechaComp(){
    return fechaComp;
}
String Momento::getHora(){
	String aux = "";
	//Serial.print(""+hora);
		//Serial.print(":"+minutos);
		//Serial.println(":"+segundos);
   if(hora > 9){
		aux += ""+String(hora,DEC);
	} else {
		String hour = hora == 0?"0":""+String(hora,DEC);
		aux += "0"+hour;
	}
	if(minutos > 9){
		aux += ":"+String(minutos,DEC);
	} else{
		String minutes = minutos == 0?"0":""+String(minutos,DEC);
		aux += ":0"+minutes;
	}

   return aux;
}
void Momento::setHoraComp(){
	String aux ="";
	
	//Serial.println(hora);
	if(hora > 9){
		aux = String(hora,DEC);
		//Serial.println("Hora 2 digit"+aux);	
	} else {
		String hour = hora == 0?"0":""+String(hora,DEC);
		aux = "0"+hour;
	//	Serial.println("Hora 1 digits"+aux);	
	}
	//Serial.println(minutos);	
	if(minutos > 9){
		aux += ":"+String(minutos,DEC);
		//Serial.println("Min 2 digit"+aux);	
	} else{
		String minutes = minutos == 0?"0":""+String(minutos,DEC);
		aux += ":0"+minutes;
		//Serial.println("Min 1 digits"+aux);	
	}
	
	if(segundos > 9){
		aux += ":"+String(segundos,DEC);
	} else{
		String seconds = segundos == 0?"0":""+String(segundos,DEC);
		aux += ":0"+seconds;
	}
	
	//Serial.print("\t");
	//Serial.println(aux);	
	horaComp = aux;
	
}
void Momento::setFechaComp(){
    String aux ="";

	if(dia > 9){
		aux += ""+String(dia,DEC);
	} else {
		aux += "0"+String(dia,DEC);
	}
	if(mes > 9){
		aux += "/"+String(mes,DEC);
	} else{
		aux += "/0"+String(mes,DEC);
	}

	aux += "/"+String(anyo,DEC);
	//Serial.println(aux);	
	fechaComp = aux;
	
}
void Momento::setHoraComp(String hour){
    horaComp = hour;
}
void Momento::setFechaComp(String date){
    fechaComp = date;
}
