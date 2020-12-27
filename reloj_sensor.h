#include "RTClib.h"


class Reloj {

public:
	int _day, _month, _year, _minute, _second,_dtw;
	String st;
	char nameoftheday[7][3] = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"};
	char monthsNames[12][3] = { "Ene", "Feb", "Mar", "Abr", "May",  "Jun", "Jul","Ago","Sep","Oct","Nov","Dic" };
	//RTC_DS3231 rtc;
	Reloj();
	DateTime getDateTime();
	int getDay();
	int getMonth();
	int getYear();
	int getMinute();
	int getSecond();
	int getDiaSemana();
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setMinute(int minute);
	void setSecond(int second);
	void setDiaSemana(int dow);
};
