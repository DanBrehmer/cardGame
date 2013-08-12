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
  refresh();
 
  // setting the positions for the windows
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

  // generating new windows at init so print func have someting to delete.
  // wrefresh() not nessesary

  create_new_win_(cpuWin_->win, cpuWin_->height, cpuWin_->width, cpuWin_->startY, cpuWin_->startX);
  create_new_win_(humWin_->win, humWin_->height, humWin_->width, humWin_->startY, humWin_->startX);
  create_new_win_(deckWin_->win, deckWin_->height, deckWin_->width, deckWin_->startY, deckWin_->startX);
  create_new_win_(pileWin_->win, pileWin_->height, pileWin_->width, pileWin_->startY, pileWin_->startX);
  
     
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
      // delete the old window
      delete_win_(cpuWin_->win);

      // make a new empty window
      create_new_win_(cpuWin_->win, cpuWin_->height, cpuWin_->width, cpuWin_->startY, cpuWin_->startX);
      
      // add content to the new window 
      mvwprintw(cpuWin_->win, cpuWin_->yCoord, cpuWin_->xCoord, "%s", plr->hand_str().c_str());
     
      if(plr->open_empty())
	{
          // adding content
	  mvwprintw(cpuWin_->win, cpuWin_->yCoord + 3, cpuWin_->xCoord, "%s", plr->hidden_str().c_str()); 
	}
      else
	{
          // or this content
	  mvwprintw(cpuWin_->win, cpuWin_->yCoord + 2, cpuWin_->xCoord, "%s", plr->open_str().c_str());
	  mvwprintw(cpuWin_->win, cpuWin_->yCoord + 3, cpuWin_->xCoord, "%s", "XX XX XX");
	}

      // show window with content
      wrefresh(cpuWin_->win);
    }
  else
    {
      // delete the old window
      delete_win_(humWin_->win);

      // make a new empty window
      create_new_win_(humWin_->win, humWin_->height, humWin_->width, humWin_->startY, humWin_->startX);
      
      // add content to the new window 
      mvwprintw(humWin_->win, humWin_->yCoord, humWin_->xCoord, "%s", plr->hand_str().c_str());
     
      if(plr->open_empty())
	{
          // adding content
	  mvwprintw(humWin_->win, humWin_->yCoord + 3, humWin_->xCoord, "%s", plr->hidden_str().c_str()); 
	}
      else
	{
          // or this content
	  mvwprintw(humWin_->win, humWin_->yCoord + 2, humWin_->xCoord, "%s", plr->open_str().c_str());
	  mvwprintw(humWin_->win, humWin_->yCoord + 3, humWin_->xCoord, "%s", "XX XX XX");
	}

      // show window with content
      wrefresh(humWin_->win);
    }
}
void Gui::print_deck(Deck* dp)
{
  delete_win_(deckWin_->win);
  create_new_win_(deckWin_->win, deckWin_->height, deckWin_->width, deckWin_->startY, deckWin_->startX);
   
  mvwprintw(deckWin_->win, deckWin_->yCoord, deckWin_->xCoord, "%s", "D D");
  mvwprintw(deckWin_->win, deckWin_->yCoord + 1, deckWin_->xCoord, "%s", dp->get_size_str().c_str());
  mvwprintw(deckWin_->win, deckWin_->yCoord + 2, deckWin_->xCoord, "%s", "D D");
  wrefresh(deckWin_->win);
}
void Gui::print_pile(Pile* pp)
{
  delete_win_(pileWin_->win);
  create_new_win_(pileWin_->win, pileWin_->height, pileWin_->width, pileWin_->startY, pileWin_->startX);
   
  mvwprintw(pileWin_->win, pileWin_->yCoord, pileWin_->xCoord, "%s", "P P");
  mvwprintw(pileWin_->win, pileWin_->yCoord + 1, pileWin_->xCoord, "%s", pp->get_size_str().c_str());
  mvwprintw(pileWin_->win, pileWin_->yCoord + 2, pileWin_->xCoord, "%s", "P P");
  wrefresh(pileWin_->win);
}

void Gui::delete_win_(WINDOW* win)
{
  wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wrefresh(win);
  delwin(win);   
}
