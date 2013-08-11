#include "Pile.h"
using namespace std;

void Pile::add_card(const Card& c)
{
    pile_.push_back(c);
}
void Pile::clean_pile()
{
    pile_.clear();
}
int Pile::get_size() const
{
    return pile_.size();
}
Card Pile::get_card()
{
  Card tmp = pile_.at(pile_.size() - 1);
  pile_.pop_back();
  return tmp;
}
bool Pile::empty() const
{
  return pile_.empty();
}
