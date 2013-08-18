#include "Gui.h"
#include <string>
using namespace std;

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
  humWin_->startY = 13;

  cpuWin_->height = 7;
  cpuWin_->width = 25;
  cpuWin_->startX = 20;
  cpuWin_->startY = 1;

  deckWin_->height = 5;
  deckWin_->width = 7;
  deckWin_->startX = 25;
  deckWin_->startY = 8;

  pileWin_->height = 5;
  pileWin_->width = 7;
  pileWin_->startX = 34;
  pileWin_->startY = 8;      
}

void Gui::print_player(Player* plr, char ch)
{

  if(dynamic_cast<Cpu*>(plr) != nullptr)
    {
      // delete the old window
      delwin(cpuWin_->win);
     
      // make a new empty window
      cpuWin_->win = newwin(cpuWin_->height, cpuWin_->width, cpuWin_->startY, cpuWin_->startX);
     

 
      // add content to the new window 
      mvwprintw(cpuWin_->win, 2, 8, "%s", plr->hand_str().c_str());

      //wrefresh(cpuWin_->win);     
      if(plr->open_empty())
	{
          // adding content
	  mvwprintw(cpuWin_->win, cpuWin_->startY + 5, cpuWin_->startX, "%s", plr->hidden_str().c_str());
	}
      else
	{
          // or this content
	  mvwprintw(cpuWin_->win, 4, 8, "%s", plr->open_str().c_str());
	  mvwprintw(cpuWin_->win, 5, 8, "%s", "XX XX XX");
	}

      // show window with content
      wrefresh(cpuWin_->win);
    }
  else
    {
      // delete the old window
      delwin(humWin_->win);

      // make a new empty window
      humWin_->win = newwin(humWin_->height, humWin_->width, humWin_->startY, humWin_->startX);
   
      // add content to the new window 
      mvwprintw(humWin_->win, 1, 8, "%s", plr->hand_str().c_str());
     
      if(plr->open_empty())
	{
          // adding content
	  mvwprintw(humWin_->win, 4, 8, "%s", plr->hidden_str().c_str()); 
	}
      else
	{
          // or this content
	  mvwprintw(humWin_->win, 3, 8, "%s", plr->open_str().c_str());
	  mvwprintw(humWin_->win, 4, 8, "%s", "XX XX XX");
	}

      // show window with content
      wrefresh(humWin_->win);
    }
}
void Gui::print_deck(Deck* dp)
{
  delwin(deckWin_->win);
  deckWin_->win = newwin(deckWin_->height, deckWin_->width, deckWin_->startY, deckWin_->startX);
 
 
  mvwprintw(deckWin_->win, 1, 1, "%s", "D  D");
  if(dp->get_size() < 10)
    {
      mvwprintw(deckWin_->win, 2, 2, "%s", ("0" + dp->get_size_str()).c_str());
    }  
  else
    {
      mvwprintw(deckWin_->win, 2, 2, "%s", dp->get_size_str().c_str());
    }
      mvwprintw(deckWin_->win, 3, 1, "%s", "D  D");
  wrefresh(deckWin_->win);
}
void Gui::print_pile(Pile* pp)
{
  delwin(pileWin_->win);
  pileWin_->win = newwin(pileWin_->height, pileWin_->width, pileWin_->startY, pileWin_->startX);
 

  mvwprintw(pileWin_->win, 1, 1, "%s", "P  P");
  if(pp->get_size() < 10)
    {
      mvwprintw(pileWin_->win, 2, 2, "%s",("0" + pp->get_size_str()).c_str());
    }
  else
    {
      mvwprintw(pileWin_->win, 2, 2, "%s",( pp->get_size_str()).c_str());
    }  
mvwprintw(pileWin_->win, 3, 1, "%s", "P  P");
  wrefresh(pileWin_->win);
}

void Gui::activate_card_set(Player* plr, int set)
{
  switch(set)
    {
    case 0:
      open_active_ = false;
      hidden_active_ = false;
      vec_ptr_ = plr->get_hand_ptr();
      hand_active_ = true;
      break;

    case 1:
      hand_active_ = false;
      hidden_active_ = false;
      vec_ptr_ = plr->get_open_ptr();
      open_active_ = true;
      break;

    case 2:
      hand_active_ = false;
      hidden_active_ = false;
      vec_ptr_ = plr->get_hidden_ptr();
      hidden_active_ = true;
      break;
    }
}
void Gui::print_active_card_set(char ch)
{
  string card_str = "";
  int index = 0;
  int y, str_length;
  int x = cpuWin_->width / 2 - vec_ptr_->size() / 2; 
  

  if(hand_active_)
    { 
      y = 2;
    }
  else if(open_active_)
    {
      y = 4;
    }
  else if(hidden_active_)
    {
      y = 5;
    }
  if(dynamic_cast<Cpu*>(plr) != nullptr)
    {
      for(int i = 0; i < vec_ptr_->size(); ++i)
	{
	  if(i == index)
	    {
	      str_length = card_str.length() + 1;
	      mvwprintw(cpuWin_->win, y, x, "%s", card_str.c_str());
	      mvwprintw(cpuWin_->win, y, x + str_length, "%s", (vec_ptr_->at(index).str() + " ").c_str());
	      str_lenght += vec_ptr_->at(index).str().length() + 1;
	      card_str = "";
	    }
	  else
	    {
	      card_str.append(vec_ptr_->at(i).str() + " ");
	    }
	}    
      mvwprintw(cpuWin_->win, y, x + str_length, "%s", card_str.c_str());
    }
  else
{
      for(int i = 0; i < vec_ptr_->size(); ++i)
	{
	  if(i == index)
	    {
	      str_length = card_str.length() + 1;
	      mvwprintw(humWin_->win, y, x, "%s", card_str.c_str());
	      mvwprintw(humWin_->win, y, x + str_length, "%s", (vec_ptr_->at(index).str() + " ").c_str());
	      str_length += vec_ptr_->at(index).str().length() + 1;
	      card_str = "";
	    }
	  else
	    {
	      card_str.append(vec_ptr_->at(i).str() + " ");
	    }
	}    
      mvwprintw(humWin_->win, y, x + str_length, "%s", card_str.c_str());
    }
}

void Gui::get_key_command(Player* plr)
{
  if(dynamic_cast<Cpu*>(plr) != nullptr)
    {
      keypad(cpuWin_->win, TRUE);
      key_ = wgetch(cpuWin_->win);
    }
  else
    {
      keypad(humWin_->win, TRUE);
      key_ = wgetch(humWin_->win);
    }
}
