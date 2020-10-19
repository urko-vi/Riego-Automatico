#include <Arduino.h>
void wait(int periodo){
  unsigned long tiempo = millis();
  while(millis() < (tiempo+periodo)){
  }
}