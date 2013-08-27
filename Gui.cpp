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
  clear();  
  noecho();
  cbreak();
  curs_set(0);

  refresh();
 
  // setting the positions for the windows
  humWin_->height = 7;
  humWin_->width = 25;
  humWin_->startX = 20;
  humWin_->startY = 13;

  cpuWin_->height = 7;
  cpuWin_->width = 25;
  cpuWin_->startX = 20;
  cpuWin_->startY = 2;

  deckWin_->height = 5;
  deckWin_->width = 7;
  deckWin_->startX = 25;
  deckWin_->startY = 8;

  pileWin_->height = 5;
  pileWin_->width = 7;
  pileWin_->startX = 34;
  pileWin_->startY = 8;      
}

void Gui::print_player(Player* plr)
{

  if(dynamic_cast<Cpu*>(plr) != nullptr)
  {
    // delete the old window
    delwin(cpuWin_->win);
     
    // make a new empty window
    cpuWin_->win = newwin(cpuWin_->height, cpuWin_->width, cpuWin_->startY, cpuWin_->startX);
     

 
    // add content to the new window
    mvwprintw(cpuWin_->win, 0, 8, "%s", (plr->get_name()).c_str());
    
    if(!hand_active_)
    {
      mvwprintw(cpuWin_->win, 1, 8, "%s", plr->hand_str().c_str());
    }
    //wrefresh(cpuWin_->win);
    if(plr->open_empty())
    {
      if(!hidden_active_ || open_active_)
      {
        // adding content
        mvwprintw(cpuWin_->win, 4, 8, "%s", "XX XX XX");
      }
    }
    else
    {
      // or this content
      if(!open_active_)
      {
        mvwprintw(cpuWin_->win, 3, 8, "%s", plr->open_str().c_str());
        mvwprintw(cpuWin_->win, 4, 8, "%s", "XX XX XX");
      }
    }
    
    print_active_card_set(plr);
    
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
      mvwprintw(humWin_->win, 0, 8, "%s", (plr->get_name()).c_str());

      if(!hand_active_)
      {
        mvwprintw(humWin_->win, 1, 8, "%s", plr->hand_str().c_str());
      }

      if(plr->open_empty())
      {
      if(!hidden_active_ || open_active_)
	{
          // adding content
	  mvwprintw(humWin_->win, 4, 8, "%s", "XX XX XX"); 
	}
      }
      else
        if(!open_active_)
	{
          // or this content
	  mvwprintw(humWin_->win, 3, 8, "%s", plr->open_str().c_str());
	  mvwprintw(humWin_->win, 4, 8, "%s", "XX XX XX");
	}
      print_active_card_set(plr);

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
  if(pp->empty())
    {
      mvwprintw(pileWin_->win, 2, 2, "%s",("00"));
    }
  else
    {
      mvwprintw(pileWin_->win, 2, 2, "%s",(pp->show_top_card()).c_str());
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
void Gui::print_active_card_set(Player* plr)
{
  string card_str = "";
  //index will iterate up and down depending on keypress by user. how about cpu? index and getting the key should be in the "hum scetion"

  int y, str_length;
  int x = 8; 
  

  if(hand_active_)
    { 
      y = 1;
    }
  else if(open_active_)
    {
      y = 3;
    }
  else if(hidden_active_)
    {
      y = 4;
    }
  if(dynamic_cast<Cpu*>(plr) != nullptr)
    {
      for(int i = 0; i < vec_ptr_->size(); ++i)
	{
	  if(i == index_)
	    {
	      str_length = card_str.length();
	      mvwprintw(cpuWin_->win, y, x, "%s", card_str.c_str());
              
              wattron(cpuWin_->win, A_REVERSE);
	      mvwprintw(cpuWin_->win, y, x + str_length, "%s", (vec_ptr_->at(index_).str()).c_str());
              wattroff(cpuWin_->win, A_REVERSE);

              str_length += vec_ptr_->at(index_).str().length() + 1;
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
	  if(i == index_)
	    {
	      str_length = card_str.length();
	      mvwprintw(humWin_->win, y, x, "%s", card_str.c_str());

              wattron(humWin_->win, A_REVERSE);
              mvwprintw(humWin_->win, y, x + str_length, "%s", (vec_ptr_->at(i).str()).c_str());
              wattroff(humWin_->win, A_REVERSE);

              str_length += (vec_ptr_->at(i).str()).length() + 1;
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

void Gui::get_key_command()
{
  delwin(humWin_->win);
  keypad(stdscr, TRUE);
  key_ = getch();
  
  refresh();
  if(key_ == KEY_LEFT)
  {
    if(index_ > 0)
    {
      --index_;
    }
  }
  else if(key_ == KEY_RIGHT)
  {
    if(index_ < vec_ptr_->size() - 1)
    {
      ++index_;
    }
  }
// if key_ == 10 we got an enter. We will check for int in an other function.
//  addch(key_);
//  refresh();
}
int Gui::get_key() const
{
  return key_;
}
int Gui::current_index() const
{
  return index_;
}
  
