#include "RTClib.h"

class Reloj {

public:
	int _day, _month, _year, _minute, _hour,_second,_dtw;
	DateTime _dt;
	char nameoftheday[7][3] = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"};
	char monthsNames[12][3] = { "Ene", "Feb", "Mar", "Abr", "May",  "Jun", "Jul","Ago","Sep","Oct","Nov","Dic" };
	Reloj();
	Reloj(RTC_DS3231 *rtc);
	int getDay();
	int getMonth();
	int getYear();
	int getMinute();
	int getSecond();
	int getDiaSemana();
	int getHour();
	DateTime getDateTime();
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setMinute(int minute);
	void setSecond(int second);
	void setDiaSemana(int dow);
	void setHour(int hour);
};
