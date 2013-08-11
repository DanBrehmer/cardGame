#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#include<vector>
#include "Card.h"

class Pile
{
  public:
  Pile() = default;
  Pile(const Pile&) = delete;
  Pile operator=(const Pile&) = delete;

  void add_card(const Card&);
  int get_size() const;
  void clean_pile();
  Card get_card();
  bool empty() const;

private:
  std::vector<Card> pile_;
};

#endif // PILE_H_INCLUDED
