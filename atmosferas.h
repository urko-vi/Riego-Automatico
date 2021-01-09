#include <WString.h>
#include "atmosfera.h"

class Atmosferas {
    public:
		Atmosfera atmosferas[1];
		Atmosferas();
		void setAtmosferas(Atmosfera atmos[],int len);
		void addAtmosfera(Atmosfera atm);
    private:
		int length;
		void setLength(int len);
		int getLength();
};