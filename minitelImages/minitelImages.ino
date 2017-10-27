#include <SoftwareSerial.h>
#include <Minitel.h>
#include "image.h"
#include "dalek.h"

Minitel m;

// fonction d'affichage d'un image alphamosaique
void afficheImg(const byte *data, int l, int h, int posx, int posy) {
  for (int y=0; y<h; y++) {
    m.moveCursorTo(posx, posy+y);
    for (int x=0; x<l; x++) {
      m.textByte(pgm_read_byte_near(data+(y*l)+x));
    }
  }
}

void setup() {
  m.clearScreen();
  m.textMode();
  m.textColor(WHITE);
  m.bgColor(RED);

  // 3516 EXTERMINATE
  m.text(" (c) 1984 - Davros", 1, 1);
  m.bgColor(BLACK);
  m.text("EXTERMINAAAAAAAAAAAAAAAAAAAAAAAAAAAAATE", 2, 2);
  m.graphicMode();
  m.textColor(CYAN);
  m.bgColor(RED);
  
  afficheImg(dalek, L_dalek, H_dalek, 2,3);
  
  m.textMode();
  m.charSize(SIZE_DOUBLE);
  m.text("3615 EXTERMINATE ", 4, 21);
  m.charSize(SIZE_NORMAL);

/*
  // 3516 HACKABLE
  m.text(" (c) 1984 - Diamond éditions ", 1, 1);
  m.bgColor(BLACK);
  m.text("DEMONTEZ  COMPRENEZ  ADAPTEZ  PARTAGEZ", 2, 2);
  
  afficheImg(logo, L_logo, H_logo, 5, 3);
  
  m.textMode();
  m.textColor(WHITE);
  m.bgColor(BLACK);  
  m.charSize(SIZE_DOUBLE);
  m.text(" 3615 HACKABLE ", 6, 21);
  m.charSize(SIZE_NORMAL);
*/  

  m.invertVideo();
  m.textColor(MAGENTA);
  m.bgColor(WHITE);
  m.text(" Tapez votre prénom ou un pseudo : ", 1, 23);
  m.standardVideo();
  m.textColor(WHITE);
  m.bgColor(BLACK);
  m.text("...............................", 2, 24);
  m.textChar('+', 34, 24);
  m.invertVideo();
  m.text("Envoi", 36, 24);
  
  m.standardVideo();
  m.textColor(WHITE);
  m.moveCursorTo(2, 24);
  m.cursor();
}

void loop() {
}


