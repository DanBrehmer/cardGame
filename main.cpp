#include <iostream>
#include <string>
#include <ncurses.h>
#include "Player.h"
#include "Human.h"
#include "Cpu.h"
#include "Deck.h"
#include "Pile.h"
#include "Gui.h"

using namespace std;

// class Gui
// {
// public:
//   void print_player(WINDOW*, Player*, int, int);
//   WINDOW* create_newwin(int, int, int, int);
// private:
//  int yCoord, xCoord;

// };
//void print_player(WINDOW*, Player*, int, int);
//WINDOW *create_newwin(int, int, int, int, Player*);
//void print_deck();
//void print_pile();
int main()
{
  Deck* dp = new Deck;
  Pile* pp = new Pile;
  Player* hum = new Human(dp, pp, "Dan");
  Player* cpu = new Cpu(dp, pp);
  Gui* myGui = new Gui();
  


  printw("Ett test");
  refresh();
  myGui->print_player(cpu);
  myGui->print_player(hum);
   myGui->print_deck(dp);
  myGui->print_pile(pp);
  //refresh();
  // print_player(win1, hum, height, width);
               
 
  getch();
  endwin();
   delete dp;
   delete pp;
   delete hum;
   delete cpu;
   delete myGui;
  // delete pile_win;
  // delete hum_win;
  // delete cpu_win;
  
  return 0;
}
// void print_player(WINDOW* win, Player* p, int yCoord, int xCoord)
// {
  
//   mvwprintw(win, yCoord, xCoord, "%s", p->hand_str().c_str());
 
//   if(p->open_empty())
//   {
  
//     mvwprintw(win, yCoord + 3, xCoord, "%s", p->hidden_str().c_str()); 
//   }
//   else
//   {
//     mvwprintw(win, yCoord + 2, xCoord, "%s", p->open_str().c_str());
//     mvwprintw(win, yCoord + 3, xCoord, "%s", "XX XX XX");
//   }
// }
// WINDOW* create_newwin(int height, int width, int starty, int startx, Player* hum)
// {	WINDOW *local_win;
//   int y, x;
//   local_win = newwin(height, width, starty, startx);
//   box(local_win, 0 , 0);		/* 0, 0 gives default characters 
// 					 * for the vertical and horizontal
// 					 * lines			*/
//   getyx(local_win, y, x);
//   print_player(local_win, hum,  y + (height / 2 - 1), x + (width / 2 - 2));
//   wrefresh(local_win);		/* Show that box 		*/

//   return local_win;
// }
