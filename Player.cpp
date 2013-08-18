#include "Player.h"
#include <stdexcept>
#include <iostream>
using namespace std;
Player::Player(Deck* d, Pile* p, const std::string& name)
: name_(name)
{
  hand_ = new Hand(d, p);
  tc_ = new Table_Cards(d, p);
}
Player::~Player() noexcept
{
  delete hand_;
  delete tc_;
}
void Player::sort_hand()
{
  hand_->sort_hand();
}
void Player::take_card()
{
  hand_->add_card();
  sort_hand();
}
void Player::take_pile()
{
  hand_->add_card(false); // false fo """2r pile
  sort_hand();
}
string Player::get_name() const
{
  return name_;
}
void Player::lay_card(int index, int amount)
{
  if(index > 0 && index <= hand_->get_size())
  {
    for(int i = 0; i < amount; ++i)
    {
      if(!hand_->empty())
      {
        hand_->lay_card(index);
      }
      else if(!tc_->open_empty())
      {
        tc_->lay_open(index);
      }
      ++index;
    }
    if(hand_->empty() && tc_->open_empty() && index <= tc_->hidden_size())
      {
        tc_->lay_hidden(index);
      }
  }
  else
  {
    throw runtime_error("You enterd a incorrect index, try again.");
  }

}
string Player::hand_str() const
{
  return hand_->hand_str();
}
string Player::open_str() const
{
  return tc_->table_cards_open_str();
}
string Player::hidden_str() const
{
  return tc_->table_cards_hidden_str();
}
bool Player::open_empty() const
{
  return tc_->open_empty();
}
vector<Card>* Player::get_hand_ptr() const
{
  return hand_->get_vec_ptr();
}
vector<Card>* Player::get_open_ptr() const
{
return tc_->get_open_vec_ptr();
}
vector<Card>* Player::get_hidden_ptr() const
{
return tc_->get_open_vec_ptr();
}
