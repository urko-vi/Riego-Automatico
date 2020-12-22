#include <WString.h>


class Atmosfera {
    public:
		Atmosfera();
        void setHumedad(float hum);
        float getHumedad();
        void setTemperatura(float temp);
        float getTemperatura();
    private:
        String nombre;
        String descripcion;
        float humedad;
        float temperatura;

};