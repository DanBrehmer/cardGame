#include "Table_Cards.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void Table_Cards::lay_open(unsigned index)
{
  if(index > 0 && index <= open_.size())
  {
    pile_->add_card(open_.at(index - 1));
    open_.erase(open_.begin() + index - 1);

  }
}
void Table_Cards::lay_hidden(unsigned index)
{
  if(index > 0 && index <= hidden_.size())
  {
    pile_->add_card(hidden_.at(index - 1));
    hidden_.erase(hidden_.begin() + index - 1);
  }
}
bool Table_Cards::open_empty() const
{
  return open_.empty();
}
bool Table_Cards::hidden_empty() const
{
  return hidden_.empty();
}
int Table_Cards::open_size() const
{
  return open_.size();
}
int Table_Cards::hidden_size() const
{
  return hidden_.size();
}
string Table_Cards::table_cards_open_str() const
{
  ostringstream os;
    for(auto i : open_)
    {
      os << i.str() << " ";
    }

  return os.str();
}
string Table_Cards::table_cards_hidden_str() const
{
  ostringstream os;
    for(auto i : hidden_)
    {
      os << i.str() << " ";
    }

  return os.str();
}
