#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED
#include "Player.h"
#include "Pile.h"
#include "Deck.h"

class Human : public Player
{
public:
    virtual ~Human() noexcept = default;
    Human(Deck* d, Pile* p, const std::string& name) : Player(d, p, name) {}
    virtual Human* clone() const override;


protected:
    Human(const Human&) = default;
    Human(Human&&) = default;
    Human& operator=(const Human&) = delete;
};

#endif // HUMAN_H_INCLUDED

