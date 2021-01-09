#include "temperatura_humedad.h"
#include "tierra_humeda.h"
#include "common.h"
#include "pantalla_lcd.h"
RTC_DS3231 rtc;
Teclado teclado;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7);
Menu menu;
Reloj reloj;
void setup() {
//  teclado = Teclado();
  lcd.setBacklightPin(3,POSITIVE);  // puerto P3 de PCF8574 como positivo
  lcd.setBacklight(HIGH);   // habilita iluminacion posterior de LCD
  lcd.begin(20, 4);     // 16 columnas por 2 lineas para LCD 1602A
  lcd.clear();      // limpia pantalla
  menu = Menu(&lcd);
  Serial.begin(9600);
  delay(2000); 
  reloj = Reloj(&rtc);
 // menu.setFechaHora(&rtc.now());
/*
   if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  } 
  
  
  if (rtc.lostPower()) {
    // Fijar a fecha y hora de compilacion
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    
    // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
    // rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
  }
  */
 // 
/*
  
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }
  */
 // rtc.adjust(DateTime(2020, 10, 17, 18,48, 30));
}

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

void loop() {
   //getText(
  
  char key;
  //key = teclado.waitForKey();
 //key=teclado.getKey();//instruccion para leer tecla 
 // printDate(rtc.now());
  //if(key){
  while(key == NO_KEY){
    key=teclado.getKey();
    //aqui hay que hacer el nucleo del programa
    //1.actualizar la fecha y la hora
    menu.setFechaHora(&rtc.now());
    //2.actualizar los datos de temperatura
    //3.lecturas de humedad de la tierra y en su caso regar.
    //4.acceder a internet y a los SW's
    menu.loadOption(&lcd,'1');    
    Serial.println(key);
    delay(100);
  }
  
  //  while(key !=' '){
    //  key = teclado.getKey();
  if(key == '1'  || key == '2' || key == '3'||key =='4'){
        Serial.println("Clave");
        Serial.println(key);
        key = menu.loadOption(&lcd,key);
         Serial.println(key);
        switch(key){
          case '1': // fecha
           // key = ' ';
            while(key !='*'){
             // DateTime dt = rtc.now();
              key =menu.showFecha(&lcd,teclado,reloj,&rtc);
            }
          break;
          case '2':// hora
            while(key !='*'){
              // DateTime dt = rtc.now();
              key =menu.showHora(&lcd,teclado,reloj,&rtc);
            }
          break;
          case '3': //wifi
            while(key !='*'){
              key =menu.showWifi(&lcd,teclado);
            }
          break;
          
        }
        key = '1';
        menu.loadOption(&lcd,key);
        //Serial.println(key);
      } else {
        Serial.println("No clave");

        key = '1';
        Serial.println(key);
    }
    //}
  //}
  
    // Serial.println(key);
//  if(menu=='1'){
  //  key = menu;
 // } 
   
  //menu.loadOption(&lcd,key);
  //
  //Serial.println(key);
  //if (key && teclas[0] == '*' && teclas[1]=='*'){
  
 //   menu.loadOption(&lcd,key);
 
  //}
  
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
