#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Card.h"



class Deck
{
public:
  Deck();
  // Deck(const Deck&) = delete;
  //Deck& operator=(const Deck&) = delete;

  void shuffle();
  Card get_card();
  void show_card(std::ostream&) const;
  int get_size() const;
  std::string get_size_str();
  bool empty() const;


private:
    std::vector<Card> deck_;
};


#endif // DECK_H_INCLUDED
