#include "Deck.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Deck::Deck()
{
    for(int i = 1; i <= 4; ++i)
    {
        char c;
        if(i == 1)
        c = 'D';
        else if(i == 2)
        c = 'H';
        else if(i == 3)
        c = 'K';
        else
        c = 'S';

        for(int j = 1; j <= 13; ++j)
        {
            deck_.push_back(Card(c, j));
        }
    }
    shuffle();
}
void Deck::shuffle()
{
    srand(time(0));
    for(int i = 0; i < 1000; ++i)
    {
        int a = rand()%52;
        int b = rand()%52;
        if(a != b)
        {
            Card tmp = deck_.at(a);
            deck_.at(a) = deck_.at(b);
            deck_.at(b) = tmp;
        }
    }
}
Card Deck::get_card()
{
    if(!deck_.empty())
    {
        Card tmp = deck_.at(deck_.size() - 1);
        deck_.pop_back();
        return tmp;
    }
    else
    {
        throw out_of_range("Deck is empty");
    }

}
int Deck::get_size() const
{
    return deck_.size();
}
void Deck::show_card(ostream& os) const
{
    os << deck_.at(deck_.size() - 1).str() << "\n";
}
bool Deck::empty() const
{
  return deck_.empty();
}
