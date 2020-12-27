#include "reloj_sensor.h";
#include <Arduino.h>

Reloj::Reloj(){
	//int _day, _month, _year, _minute, _second,_dtw;
	//String st;
	//RTC_DS3231 rtc;
	/*
	if (!rtc.begin()) {
		Serial.println(F("Couldn't find RTC"));
		//while (1);
	}
	if (rtc.lostPower()) {
		// Fijar a fecha y hora de compilacion
		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
		
		// Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
		// rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
	}
	*/
}
int Reloj::getDay(){
	return 0;
}
int Reloj::getMonth(){
	return 0;
}
int Reloj::getYear(){
	return 0;
}
int Reloj::getMinute(){
	return 0;
}
int Reloj::getSecond(){
	return 0;
}
int Reloj::getDiaSemana(){
	return 0;
}
void Reloj::setDay(int day){
	
}
void Reloj::setMonth(int month){
	
}
void Reloj::setYear(int year){
	
}
void Reloj::setMinute(int minute){
	
}
void Reloj::setSecond(int second){
	
}
void Reloj::setDiaSemana(int dow){
	
}
