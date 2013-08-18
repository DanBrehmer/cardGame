#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Pile.h"


class Hand
{
public:
  Hand(Deck* d, Pile* p);
  Hand(const Hand&) = delete;
  Hand& operator=(const Hand&) = delete;
  void add_card(bool from_deck = true);
  void lay_card(unsigned);
  std::string hand_str() const;
  void sort_hand();
  bool empty() const;
  int get_size() const;
  std::vector<Card>* get_vec_ptr();
private:
  std::vector<Card> hand_;
  Deck* deck_;
  Pile* pile_;

};



#endif // HAND_H_INCLUDED
