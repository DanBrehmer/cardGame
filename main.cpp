#include <ncurses.h>
#include "Player.h"
#include "Human.h"
#include "Cpu.h"
#include "Deck.h"
#include "Pile.h"
#include "Gui.h"

using namespace std;


int main()
{
  Deck* dp = new Deck;
  Pile* pp = new Pile;
  Player* hum = new Human(dp, pp, "Dan");
  Player* cpu = new Cpu(dp, pp);
  Gui* myGui = new Gui();
  
  myGui->print_player(cpu);
  myGui->print_player(hum);
  myGui->print_deck(dp);
  myGui->print_pile(pp);
 
  getch();
  endwin();
 
  delete dp;
  delete pp;
  delete hum;
  delete cpu;
  delete myGui;
  
  return 0;
}

