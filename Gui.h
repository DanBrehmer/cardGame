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
  WINDOW* win = nullptr;

  int height;
  int width;
  int startX;
  int startY;
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

  Win* humWin_;
  Win* cpuWin_;
  Win* deckWin_;
  Win* pileWin_;

  void create_new_win_(WINDOW*, int, int, int, int);
  void delete_win_(WINDOW*);

  int y, x, yCoord, xCoord;
};

#endif
