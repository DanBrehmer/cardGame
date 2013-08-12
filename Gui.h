#ifndef GUI_H
#define GUI_H
#include <ncurses.h>
#include "Player.h"
#include "Deck.h"
#include "Pile.h"
#include "Cpu.h"

class Win
{
public:
  Win() = default;
  ~Win(){delete win;}
  WINDOW* win = nullptr;  // pointer to the window

  int height; // height och window
  int width;  // width of window
  int startY; // were on screen window will start (y)
  int startX; // were on screen window will start (x)
  int yCoord = startY + height / 2; // were in window content will start (y)
  int xCoord = startX + width  / 2; // were in window content will start (x)
};

class Gui
{
 public:
  Gui();
  ~Gui();

  void print_player(Player*);
  void print_deck(Deck*);
  void print_pile(Pile*);

 private:

  Win* humWin_; // holds WINDOW pointer and position info. See Win class.
  Win* cpuWin_;
  Win* deckWin_;
  Win* pileWin_;

  void create_new_win_(WINDOW*, int, int, int, int);
  void delete_win_(WINDOW*);
};

#endif
