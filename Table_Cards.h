#ifndef TABLE_CARDS_INCLUDED
#define TABLE_CARDS_INCLUDED
#include <vector>
#include <ostream>
#include <string>
#include <algorithm>
#include "Hand.h"
#include "Pile.h"
#include "Card.h"
#include "Deck.h"




class Table_Cards
{
public:
  Table_Cards(Deck* d, Pile* p)
    : deck_(d), pile_(p)
  {
    for(int i = 0; i < 3; ++i)
    {
      open_.push_back(deck_->get_card());
      hidden_.push_back(deck_->get_card());
    }
    sort(open_.begin(), open_.end(), [](Card a, Card b){return a.get_number() < b.get_number();});
  }
  Table_Cards(const Table_Cards&) = default;
  Table_Cards(Table_Cards&&) = default;
  void lay_open(unsigned index);
  void lay_hidden(unsigned index);
  bool open_empty() const;
  bool hidden_empty() const;
  int open_size() const;
  int hidden_size() const;
  std::string table_cards_open_str() const;
  std::string table_cards_hidden_str() const;

protected:
  Table_Cards& operator=(const Table_Cards&) = delete;

private:
  Deck* deck_;
  Pile* pile_;
  std::vector<Card> open_;
  std::vector<Card> hidden_;
};
#endif
