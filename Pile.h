#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#include<vector>
#include "Card.h"
#include <string>

class Pile
{
  public:
  Pile() = default;
  Pile(const Pile&) = delete;
  Pile operator=(const Pile&) = delete;

  void add_card(const Card&);
  int get_size() const;
  std::string get_size_str() const;
  void clean_pile();
  Card get_card();
  bool empty() const;

private:
  std::vector<Card> pile_;
};

#endif // PILE_H_INCLUDED
