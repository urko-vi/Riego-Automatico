#include <WString.h>
#include "momento.h"
#include "atmosferas.h"
#include "plantas.h"
#include "status.h"
class DatosApp {
    public:
		DatosApp();
		Atmosferas getAtmosferas();
		void setAtmosferas(Atmosferas atms);
		Momento getMomento();
		void setMomento(Momento moment);
		void setMomento(DateTime *dt);
		Plantas getPlantas();
		void setPlantas(Plantas plants);
		Status getStatus();
		void setStatus(Status stats);
    private:
		Atmosferas atmosferas;
		Momento momento;
		Plantas plantas;
		Status status;
};