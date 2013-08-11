#include "Card.h"

using namespace std;

Card& Card::operator=(const Card& rhs)
{
    suit_ = rhs.suit_;
    num_ = rhs.num_;

    return *this;
}
Card& Card::operator=(Card&& rhs)
{
    suit_ = rhs.suit_;
    num_ = rhs.num_;

    return *this;
}
int Card::get_number() const
{
    return num_;
}
char Card::get_suit() const
{
    return suit_;
}
string Card::str() const
{
return suit_ + to_string(num_);

}
