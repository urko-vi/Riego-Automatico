#include "temperatura_humedad.h"
#include "tierra_humeda.h"
#include "common.h"
#include "teclado.h"
#include "RTClib.h"
#include "pantalla_lcd.h"

//RTC_DS1307 rtc;

Teclado teclado;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7);
Menu menu;
void setup() {
  teclado = Teclado();
  menu = Menu();
  Serial.begin(9600);
  /*
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }
  */
 // rtc.adjust(DateTime(2020, 10, 17, 18,48, 30));
}
/*
void printDate(DateTime date)
{
  Serial.print(date.year(), DEC);
  Serial.print('/');
  Serial.print(date.month(), DEC);
  Serial.print('/');
  Serial.print(date.day(), DEC);
  Serial.print("\t");
  Serial.print(date.hour(), DEC);
  Serial.print(':');
  Serial.print(date.minute(), DEC);
  Serial.print(':');
  Serial.print(date.second(), DEC);
  Serial.println();
}
*/
void loop() {

    /*
    lcd.setCursor(0, 0);   // ubica cursor en columna 0 y linea 0
    lcd.print("Hola, han pasado");  // escribe el texto
    lcd.setCursor(0, 1);    // ubica cursor en columna 0 y linea 1
    lcd.print(millis() / 1000);   // funcion millis() / 1000 para segundos transcurridos
    lcd.print(" seg.");     // escribe seg.
    
  // Print the uptime in millis
  */
  char key = teclado.getText();
  if (key){
    menu.loadOption(&lcd,key);
 
  }
   
  //DateTime now = rtc.now();
  //printDate(now);
  /*
  bool esNecesarioRegar = regar(A0);
  if (esNecesarioRegar) {
    Serial.println("Hay que regar");
  } else {
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
  */
  //delay(1000);
}
