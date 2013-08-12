#include "Gui.h"
#include <string>
Gui::~Gui()
{
  delete humWin_;
  delete cpuWin_;
  delete deckWin_;
  delete pileWin_;
}
Gui::Gui() : humWin_(new Win), cpuWin_(new Win), deckWin_(new Win), pileWin_(new Win)
{
  initscr();
  
  cbreak();
  keypad(stdscr, TRUE);


  humWin_->height = 7;
  humWin_->width = 25;
  humWin_->startX = 20;
  humWin_->startY = 15;

  cpuWin_->height = 7;
  cpuWin_->width = 25;
  cpuWin_->startX = 20;
  cpuWin_->startY = 0;

  deckWin_->height = 5;
  deckWin_->width = 7;
  deckWin_->startX = 24;
  deckWin_->startY = 8;

  pileWin_->height = 5;
  pileWin_->width = 7;
  pileWin_->startX = 33;
  pileWin_->startY = 8; 

  //create_new_win_(humWin_->win, humWin_->height, humWin_->width, humWin_->startY, humWin_->startX);
  //create_new_win_(cpuWin_->win, cpuWin_->height, cpuWin_->width, cpuWin_->startY, cpuWin_->startX);
  //create_new_win_(deckWin_->win, deckWin_->height, deckWin_->width, deckWin_->startY, deckWin_->startX);
  //create_new_win_(pileWin_->win, pileWin_->height, pileWin_->width, pileWin_->startY, pileWin_->startX);  
}

void Gui::create_new_win_(WINDOW* win, int h, int w, int y, int x)
{
  win = newwin(h, w, y, x);
  box(win, 0, 0); //just to see what's going on.
  wrefresh(win);
}

void Gui::print_player(Player* plr)
{

  if(dynamic_cast<Cpu*>(plr) != nullptr)
    {
      delete_win_(cpuWin_->win);
      create_new_win_(cpuWin_->win, cpuWin_->height, cpuWin_->width, cpuWin_->startY, cpuWin_->startX);
      
      getyx(cpuWin_->win, y, x);
      yCoord = y + (cpuWin_->height / 2 - 1);
      xCoord = x + (cpuWin_->width  / 2 - 2);

      mvwprintw(cpuWin_->win, yCoord, xCoord, "%s", plr->hand_str().c_str());
 
      if(plr->open_empty())
	{
  
	  mvwprintw(cpuWin_->win, yCoord + 3, xCoord, "%s", plr->hidden_str().c_str()); 
	}
      else
	{
	  mvwprintw(cpuWin_->win, yCoord + 2, xCoord, "%s", plr->open_str().c_str());
	  mvwprintw(cpuWin_->win, yCoord + 3, xCoord, "%s", "XX XX XX");
	}
      wrefresh(cpuWin_->win);
    }
  else
    {
      delete_win_(humWin_->win);
      create_new_win_(humWin_->win, humWin_->height, humWin_->width, humWin_->startY, humWin_->startX);
      
      getyx(humWin_->win, y, x);
      yCoord = y + (humWin_->height / 2 - 1);
      xCoord = x + (humWin_->width  / 2 - 2);

      mvwprintw(humWin_->win, yCoord, xCoord, "%s", plr->hand_str().c_str());
 
      if(plr->open_empty())
	{
  
	  mvwprintw(humWin_->win, yCoord + 3, xCoord, "%s", plr->hidden_str().c_str()); 
	}
      else
	{
	  mvwprintw(humWin_->win, yCoord + 2, xCoord, "%s", plr->open_str().c_str());
	  mvwprintw(humWin_->win, yCoord + 3, xCoord, "%s", "XX XX XX");
	}
      wrefresh(humWin_->win);
    }

}
void Gui::print_deck(Deck* dp)
{
  delete_win_(deckWin_->win);
  create_new_win_(deckWin_->win, deckWin_->height, deckWin_->width, deckWin_->startY, deckWin_->startX);

  getyx(humWin_->win, y, x);
  yCoord = y + (deckWin_->height / 2);
  xCoord = x + (deckWin_->width  / 2);
    
  mvwprintw(deckWin_->win, yCoord, xCoord, "%s", "D D");
  mvwprintw(deckWin_->win, yCoord + 1, xCoord, "%s", dp->get_size_str().c_str());
  mvwprintw(deckWin_->win, yCoord + 2, xCoord, "%s", "D D");
  wrefresh(deckWin_->win);
}
void Gui::print_pile(Pile* pp)
{
  delete_win_(pileWin_->win);
  create_new_win_(pileWin_->win, pileWin_->height, pileWin_->width, pileWin_->startY, pileWin_->startX);

  getyx(humWin_->win, y, x);
  yCoord = y + (pileWin_->height / 2);
  xCoord = x + (pileWin_->width  / 2);
    
  mvwprintw(pileWin_->win, yCoord, xCoord, "%s", "P P");
  mvwprintw(pileWin_->win, yCoord + 1, xCoord, "%s", pp->get_size_str().c_str());
  mvwprintw(pileWin_->win, yCoord + 2, xCoord, "%s", "P P");
  wrefresh(pileWin_->win);
}

void Gui::delete_win_(WINDOW* local_win)
{
  //sparar detta tills jag tar bort bordern.

  /* box(local_win, ' ', ' '); : This won't produce the desired
   * result of erasing the window. It will leave it's four corners 
   * and so an ugly remnant of window. 
   */
  wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  /* The parameters taken are 
   * 1. win: the window on which to operate
   * 2. ls: character to be used for the left side of the window 
   * 3. rs: character to be used for the right side of the window 
   * 4. ts: character to be used for the top side of the window 
   * 5. bs: character to be used for the bottom side of the window 
   * 6. tl: character to be used for the top left corner of the window 
   * 7. tr: character to be used for the top right corner of the window 
   * 8. bl: character to be used for the bottom left corner of the window 
   * 9. br: character to be used for the bottom right corner of the window
   */
  delwin(local_win);  
  wrefresh(local_win);
  

}
