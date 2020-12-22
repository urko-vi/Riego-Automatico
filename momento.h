#include <WString.h>


class Momento {
    public:
		Momento();
        String getHoraComp();
		String getHora();
        String getFechaComp();
		void setDia(int hour);
		void setMes(int month);
		void setAnyo(int year);
		void setHora(int hour);		
		void setMinutos(int minutes);
		void setSegundos(int seconds);
    private:
        String horaComp;
        String fechaComp;
		int dia;
		int mes;
		int anyo;
		int hora;
		int minutos;
		int segundos;
		void setHoraComp(String hour);
		void setFechaComp(String date);
		void setHoraComp();
		void setFechaComp();
};