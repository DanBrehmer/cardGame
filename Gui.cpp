#include "Gui.h"
Gui::~Gui()
{
  delete humWin;
  delete cpuWin;
  delete deckWin;
  delete pileWin;
}
Gui::Gui()
{
  humWin_->height = 7;
  humWin_->width = 25;
  humWin_->startX = 20;
  humWin_->startY = 15;

  cpuWin_->height = 7;
  cpuWin_->width = 25;
  cpuWin_->startX = 20;
  cpuWin_->startY = 0;

  deckWin_->height = 5;
  deckWin_->width = 5;
  deckWin_->startX = 12;
  deckWin_->startY = 9;

  pileWin_->height = 5;
  pileWin_->width = 5;
  pilekWin_->startX = 12;
  pileWin_->startY = 9; 

  create_new_win(humWin_->, humWin_->height, humWin_->widht, humWin_->startY, humWin_->startX);
  create_new_win(cpuWin_->, cpuWin_->height, cpuWin_->widht, cpuWin_->startY, cpuWin_->startX);
  create_new_win(deckWin_->, deckWin_->height, deckWin_->widht, deckWin_->startY, deckWin_->startX);
  create_new_win(pileWin_->, pileWin_->height, pileWin_->widht, pileWin_->startY, pileWin_->startX);
  
  
  
}
void Gui::create_new_win(WINDOW* win, int h, int w, int y, int x)
{
  win = newwin(h, w, y, x);
  box(win, 0, 0); //just to see what's going on.
}
void Gui::print_player(Player* p)
{

}
