#include <Arduboy2.h>
Arduboy2 arduboy;

int i;
unsigned int x;
unsigned int y;
unsigned int pixel;
PROGMEM const String mensaje="@mmoroca";
PROGMEM unsigned const int retardo=100;

void setup() {
  arduboy.boot();
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
  x=random(128);
  y=random(64);

  pixel=arduboy.getPixel(x,y);
    
  arduboy.setCursor(x, y);
  arduboy.drawPixel(x, y, !pixel);
  
  arduboy.display();
}
