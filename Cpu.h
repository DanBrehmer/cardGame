#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

#include "Player.h"
#include "Pile.h"
#include "Deck.h"
#include <string>

class Cpu : public Player
{
public:
  virtual ~Cpu() noexcept = default;
  Cpu(Deck* d, Pile* p, const std::string& str = "CPU") : Player(d, p, str) {}
  virtual Cpu* clone() const override;




protected:
  Cpu(const Cpu&)  = default;
  Cpu(Cpu&&) = default;
  Cpu& operator=(const Cpu&) = delete;
};

#endif


