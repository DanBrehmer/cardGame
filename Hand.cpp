#include "Hand.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

Hand::Hand(Deck* d, Pile* p)
: deck_(d), pile_(p)
{
    for(int i = 0; i < 3; ++i)
    {
        add_card();
    }
    sort_hand();
}
void Hand::add_card(bool from_deck)
{
  if(from_deck)
  {
    hand_.push_back(deck_->get_card());
  }
  else
  {
    while(!pile_->empty());
    {
      hand_.push_back(pile_->get_card());
    }
  }
}
void Hand::lay_card(unsigned index)
{
  if(index > 0 && index <= hand_.size())
  {
    pile_->add_card(hand_.at(index - 1));
    hand_.erase(hand_.begin() + index - 1);
  }
}
string Hand::hand_str() const
{
  ostringstream os;

  for(auto i : hand_)
  {
    os << i.str() << " ";
  }

  return os.str();
}
void Hand::sort_hand()
{
  sort(hand_.begin(), hand_.end(), [](Card a, Card b){return a.get_number() < b.get_number();});
}
int Hand::get_size() const
{
return hand_.size();
}
bool Hand::empty() const
{
return hand_.empty();
}
