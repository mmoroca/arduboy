#include <Arduboy2.h>
Arduboy2 arduboy;

int i;
unsigned int x1;
unsigned int y1;
unsigned int x2;
unsigned int y2;

PROGMEM const String mensaje="@mmoroca";
PROGMEM unsigned const int retardo=100;

void setup() {
  arduboy.boot();
  randomSeed(analogRead(1));
  //Serial.begin(9600);
  
  for (i=-16; i<(64-6)/2; i++) {
    arduboy.clear();
    arduboy.setCursor((128-(mensaje.length()*6))/2, i);
    arduboy.print(mensaje);
    arduboy.delayShort(retardo/10);
    arduboy.display();
  }

  arduboy.delayShort(retardo*10);
}

void loop() {
  x1=random(128);
  y1=random(64);
  x2=random(128);
  y2=random(64);
  
  arduboy.drawLine(x1,y1,x2,y2,WHITE);
  
  arduboy.display();
}
