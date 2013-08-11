#
# Makefile för skitgubbe
#
# Filkatalog där andra delar av programet finns.
#EXPRESSION = ../Expression
#VARIABLE_TABLE = ../Variable_Table

# Kompilator
CCC = g++
#CCC = gccfilter -a -c g++

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra

# Länkflaggor för att fixa problem med nuvarande versioner av Solaris och 
# C++ länkbibliotek.
#LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
#CPPFLAGS += -I$(EXPRESSION) -I$(VARIABLE_TABLE)

# Objektkodsmoduler som ingår i skitgubbe.
OBJECTS = Player.o Human.o Cpu.o Hand.o Table_Cards.o Card.o Deck.o Pile.o main.o

# Huvudmål - skapas med kommandot 'make' eller 'make skitgubbe'.
skitgubbe: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -o skitgubbe $(OBJECTS) -lncurses

# Delmål (flaggan -c avbryter innan länkning)
main.o: Player.h Human.h Cpu.h Hand.h Table_Cards.h Deck.h Pile.h main.cpp 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c main.cpp

Player.o: Player.h Hand.h Table_Cards.h Deck.h Pile.h Player.cpp 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Player.cpp

Human.o:  Human.h Player.h Deck.h Pile.h  Human.cpp 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Human.cpp

Cpu.o: Player.h Deck.h Pile.h Cpu.h Cpu.cpp 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Cpu.cpp

Hand.o: Hand.h Deck.h Pile.h Card.h Hand.cpp 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Hand.cpp

Table_Cards.o: Table_Cards.h Deck.h Pile.h Card.h Table_Cards.cpp 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Table_Cards.cpp

Card.o: Card.h Card.cpp 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Card.cpp

Deck.o: Deck.h Card.h Deck.cpp 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Deck.cpp

Pile.o: Pile.h Card.h Pile.cpp 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Pile.cpp

# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o *.gch core

# 'make zap' tar även bort det körbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf skitgubbe *~

# '@' medför att kommandot inte skrivs ut på skärmen då det utförs av make.
# 'rm' är ett alias för 'rm -i' på IDA:s system, '\rm' innebär att "original-
# versionen", utan skyddsnätet '-i', används. Se upp vid ändring, '*' får 
# absolut inte finnas för sig!
