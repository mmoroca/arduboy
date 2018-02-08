#include <Arduboy2.h>
Arduboy2 arduboy;

PROGMEM unsigned const int puntos=6;
PROGMEM unsigned const int retardo=100;
PROGMEM const String mensaje="@mmoroca";

unsigned int tablaxy[puntos][2];
int i;
char coordenadas[10];

void setup() {
  arduboy.boot();
  //Serial.begin(9600);
  randomSeed(analogRead(1));
  
  for (i=-16; i<(64-6)/2; i++) {
    arduboy.clear();
    arduboy.setCursor((128-(mensaje.length()*6))/2, i);
    arduboy.print(mensaje);
    arduboy.delayShort(retardo/10);
    arduboy.display();
  }

  arduboy.delayShort(retardo*10);

  for (i=0; i<puntos; i++) {
    tablaxy[i][0]=random(128);
    tablaxy[i][1]=random(64);
  }
}

void loop() {
  arduboy.clear();
  
  for(i=0; i<puntos-2; i++) {
    arduboy.drawLine(tablaxy[i][0], tablaxy[i][1], tablaxy[i+1][0], tablaxy[i+1][1], WHITE);
  }
    
  arduboy.delayShort(retardo);
  
  for(i=0; i<puntos-1; i++) {
    tablaxy[i][0]=tablaxy[i+1][0];
    tablaxy[i][1]=tablaxy[i+1][1];
    //sprintf(coordenadas,"%d-%d\n", tablaxy[i][0], tablaxy[i][1]);
    //arduboy.print(coordenadas);
  }  
  arduboy.display();

  tablaxy[puntos-1][0]=random(128);
  tablaxy[puntos-1][1]=random(64);
}
