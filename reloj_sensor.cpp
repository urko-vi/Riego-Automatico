#include "reloj_sensor.h"
#include <Arduino.h>
Reloj::Reloj(){
	_day= 1;
	_month=1; 
	_year=1970;
	_minute=0;
	_hour=0;
	_second=0;
	_dtw = 0;
}
Reloj::Reloj(RTC_DS3231 *rtc){
//	int _day, _month, _year, _minute, _second,_dtw;
	Serial.println("Arduino RTC DS3231");

	
	if (!rtc->begin()) {
		Serial.println(F("Couldn't find RTC"));
		while (1);
	} else{
		Serial.println(F("find RTC"));	
	}
	
	
	if (rtc->lostPower()) {
		// Fijar a fecha y hora de compilacion
		rtc->adjust(DateTime(F(__DATE__), F(__TIME__)));
		
		// Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
		// rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
	}
	_dt = rtc->now();
	_day = _dt.day();
	_month = _dt.month();
	_year = _dt.year();
	_dtw = _dt.dayOfTheWeek();
	_hour= _dt.hour();
	_minute=_dt.minute();
	_second=_dt.second();
}
int Reloj::getDay(){
	return _day;
}
int Reloj::getMonth(){
	return _month;
}
int Reloj::getYear(){
	return _year;
}
int Reloj::getHour(){
	return _hour;
}
int Reloj::getMinute(){
	return _minute;
}
int Reloj::getSecond(){
	return _second;
}
int Reloj::getDiaSemana(){
	return _dtw;
}
DateTime Reloj::getDateTime(){
	return _dt;
}
void Reloj::setDay(int day){
	_day = day;
}
void Reloj::setMonth(int month){
	_month = month;
}
void Reloj::setYear(int year){
	_year = year;
}
void Reloj::setHour(int hour){
	_hour = hour;
}
void Reloj::setMinute(int minute){
	_minute = minute;
}
void Reloj::setSecond(int second){
	_second = second;
}
void Reloj::setDiaSemana(int dow){
	_dtw = dow;
}
