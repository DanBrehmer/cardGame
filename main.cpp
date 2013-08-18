#include <iostream>
#include <ncurses.h>
#include "Player.h"
#include "Human.h"
#include "Cpu.h"
#include "Deck.h"
#include "Pile.h"
#include "Gui.h"
#include <string>

using namespace std;


int main()
{
  Deck dp;
  Pile pp;
  Player*  hum = new Human(&dp, &pp, "Dan");
  Player* cpu = new Cpu(&dp, &pp);
  Gui myGui; 
  myGui.print_player(cpu);
  myGui.print_player(hum);
  myGui.print_deck(&dp);
  myGui.print_pile(&pp);
 
  getch();
  endwin();
  
  return 0;
}

