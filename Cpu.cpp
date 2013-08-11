#include "Cpu.h"
using namespace std;

Cpu* Cpu::clone() const
{
  return new Cpu(*this);
}
