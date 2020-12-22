#include <WString.h>
#include "planta.h";

class Plantas {
    public:
		Planta plantas[1];
		Plantas();
		void setPlantas(Planta plants[],int len);
		void addPlanta(Planta plant);
    private:
		int length;
		void setLength(int len);
		int getLength();
};