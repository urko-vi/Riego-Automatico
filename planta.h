#include <WString.h>


class Planta {
	
    public:
		Planta();
        void setHumedad(float hum);
        float getHumedad();

    private:
        String nombre;
        String descripcion;
        String tipo;
        String perfil;
        float humedad;

};