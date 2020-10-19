#include "temperatura_humedad.h"
#include "tierra_humeda.h"
#include "common.h"

void setup() {
  setup_sensor_temperatura_humedad();
  Serial.begin(9600);
}

void loop() {
  bool esNecesarioRegar = regar(A0);
  if(esNecesarioRegar){
    Serial.println("Hay que regar");
  } else{
    Serial.println("NO Hay que regar");
  }
  float temp = medir_temperatura();
  float humedad = medir_humedad();

  Serial.print("Humidity: ");
  Serial.print(humedad);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" *C ");
  //wait(1000);
}
