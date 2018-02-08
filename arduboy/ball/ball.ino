#include <Arduboy2.h>
Arduboy2 arduboy;

int i;
unsigned int x;
unsigned int y;
unsigned int radio;

unsigned int sube=0;
unsigned int lado=0;

unsigned int pixel;

PROGMEM const String mensaje="@mmoroca";
PROGMEM unsigned const int retardo=100;

void setup() {
  arduboy.boot();
  //Serial.begin(9600);

  randomSeed(analogRead(1));
  x=random(128);
  y=random(64);
  radio=1+random(16);

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
  arduboy.clear();
  arduboy.drawCircle(x,y, radio);

  if ((x>WIDTH-(radio)) || (x<(radio))) {
    sube=!sube;
  }
  
  if ((y>HEIGHT-(radio)) || (y<(radio))) {
    lado=!lado;
  }

  if (sube) { x=x+1; } else { x=x-1; }
  if (lado) { y=y+1; } else { y=y-1; }
  
  arduboy.delayShort(retardo/10);
  arduboy.display();
}
