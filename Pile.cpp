#include "Pile.h"
#include <string>
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
string Pile::get_size_str() const
{
  return to_string(get_size());
}
Card Pile::get_card()
{
  Card tmp = pile_.at(pile_.size() - 1);
  pile_.pop_back();
  return tmp;
}
string Pile::show_top_card() const
{
  return pile_.at(pile_.size() - 1).str();
}
bool Pile::empty() const
{
  return pile_.empty();
}
