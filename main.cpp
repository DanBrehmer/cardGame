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
  //myGui.print_player(cpu);
  
 myGui.activate_card_set(cpu, 0);
 myGui.print_player(cpu);
 
 myGui.activate_card_set(hum, 0);
 myGui.print_player(hum);
 
 myGui.print_deck(&dp);
  myGui.print_pile(&pp);

  myGui.activate_card_set(hum, 0);
  while(myGui.get_key() != 10)
  {
    myGui.get_key_command();
    myGui.print_player(hum);
    //getch();
  }

  hum->lay_card(myGui.current_index());
  hum->take_card();
  myGui.print_pile(&pp);
  myGui.print_player(hum);
  myGui.print_deck(&dp);
 
  getch();
  endwin();
  
  return 0;
}

