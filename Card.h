#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>
class Card
{
public:
    Card(char suit, int val)
        : suit_(suit), num_(val) {}
    Card(const Card&) = default;
    Card(Card&&) = default;
    Card& operator=(const Card&);
    Card& operator=(Card&&);

    char get_suit() const;
    int get_number() const;
    std::string str() const;

private:
    char suit_;
    int num_;

};
#endif // CARD_H_INCLUDED
