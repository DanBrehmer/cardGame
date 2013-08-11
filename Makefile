#
# Makefile f�r skitgubbe
#
# Filkatalog d�r andra delar av programet finns.
#EXPRESSION = ../Expression
#VARIABLE_TABLE = ../Variable_Table

# Kompilator
CCC = g++
#CCC = gccfilter -a -c g++

# Kompilatorflaggor, l�gg till '-g' om kompilering f�r avlusning ska g�ras.
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra

# L�nkflaggor f�r att fixa problem med nuvarande versioner av Solaris och 
# C++ l�nkbibliotek.
#LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

# Preprocessorflaggor, -I l�gger till en filkatalog i inkluderingss�kv�gen.
#CPPFLAGS += -I$(EXPRESSION) -I$(VARIABLE_TABLE)

# Objektkodsmoduler som ing�r i skitgubbe.
OBJECTS = Player.o Human.o Cpu.o Hand.o Table_Cards.o Card.o Deck.o Pile.o main.o

# Huvudm�l - skapas med kommandot 'make' eller 'make skitgubbe'.
skitgubbe: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -o skitgubbe $(OBJECTS) -lncurses

# Delm�l (flaggan -c avbryter innan l�nkning)
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

# 'make zap' tar �ven bort det k�rbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf skitgubbe *~

# '@' medf�r att kommandot inte skrivs ut p� sk�rmen d� det utf�rs av make.
# 'rm' �r ett alias f�r 'rm -i' p� IDA:s system, '\rm' inneb�r att "original-
# versionen", utan skyddsn�tet '-i', anv�nds. Se upp vid �ndring, '*' f�r 
# absolut inte finnas f�r sig!
