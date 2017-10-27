#include <SoftwareSerial.h>
#include <Minitel.h>

//Minitel m(6,7,4800);
// Objet représentant la connexion avec les valeurs 
// par défaut
Minitel m;

void setup() {
  // efface l'écran
  m.clearScreen();

  // mode texte
  m.textMode();
  // couleur avant-plan
  m.textColor(WHITE);
  // couleur arrière-plan
  m.bgColor(BLACK);
  // texte à la position courante
  m.text("Coucou le monde !");
  // taille élargie en hauteur et largeur
  m.charSize(SIZE_DOUBLE);
  // texte à une position donnée
  m.text("JE SUIS UN MINITEL", 1, 3);
  // taille normale du texte
  m.charSize(SIZE_NORMAL);
  // déplacement du curseur
  m.moveCursorTo(1, 4);
  // affiche le texte à la nouvelle position
  m.text("et je voudrais juste dire...");
  
  m.charSize(SIZE_DOUBLE);
  m.textColor(WHITE);
  m.bgColor(MAGENTA);
  m.text("  MERCI HACKABLE !  ", 1, 8);
  m.bgColor(BLACK);
  m.textColor(CYAN);
  m.text("     POUR CETTE", 1, 10);
  m.textColor(BLUE);
  m.text("    NOUVELLE VIE", 1, 12);
  m.textColor(GREEN);
  m.text("   <3 <3 <3 <3 <3", 1, 14);

  m.charSize(SIZE_NORMAL);
  m.textColor(WHITE);
  m.text("Vous aussi, adoptez un Minitel !", 1, 16);
  // l'affichage de texte déplace le curseur
  // Si on précise une position
  m.text("Nous sommes gentils, propres et très ", 1, 18);
  // le texte est mis au bout
  m.text("affectueux avec les humains, surtout ceux ");
  // et revient à la ligne automatiquement
  m.text("qui lisent Hackable :)");

  // mais il faut savoir où il s'arrète pour ne pas
  // ecraser le texte déjà affiché et écrire ensuite
  // au bon endroit
  m.textColor(BLUE);
  m.text("            Ceci était un message du CSM", 1, 22);
  m.text("        (Comité de Soutien des Minitel)", 1, 23);
}

void loop() {
  //m.moveCursorTo(1, 4);
  delay(2000);
}
