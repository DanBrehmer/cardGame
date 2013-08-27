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
};

class Gui
{
 public:
  Gui();
  ~Gui();

  void print_player(Player*);
  void print_deck(Deck*);
  void print_pile(Pile*);
  void activate_card_set(Player*, int);
  void get_key_command();
  int get_key() const;
  int current_index() const;

 private:

  Win* humWin_; // holds WINDOW pointer and position info. See Win class.
  Win* cpuWin_;
  Win* deckWin_;
  Win* pileWin_;

  bool hand_active_ = false;
  bool open_active_ = false;
  bool hidden_active_ = false;

  const std::vector<Card>* vec_ptr_ = nullptr;
  void print_active_card_set(Player*);
  int key_ = 0;
  int index_ = 0;
};

#endif
