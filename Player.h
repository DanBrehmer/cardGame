#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
#include <iostream>
#include "Hand.h"
#include "Deck.h"
#include "Pile.h"
#include "Table_Cards.h"




class Player
{
public:
  virtual ~Player() noexcept;
  virtual Player* clone() const = 0;
  void lay_card(int index, int amount = 1);
  void sort_hand();
  void take_card();
  void take_pile();
  std::string get_name() const;
  std::string hand_str() const;
  std::string open_str() const;
  std::string hidden_str() const;
  bool open_empty() const;
  
protected:
  Player(Deck*, Pile*, const std::string&);
  Player(const Player&) = default;
  Player(Player&&) = default;
  
private:
  Hand* hand_;
  Table_Cards* tc_;
  const std::string name_;
};


#endif // PLAYER_H_INCLUDED
