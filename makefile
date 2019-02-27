CC    = g++
FLAGS = -g -c -Wall -std=c++11
INCL  = includes
TEST  = tests

main.exe: $(INCL)/stdafx.h.gch $(INCL)/all.h.gch $(INCL)/exits.h.gch $(INCL)/color.o $(INCL)/colors.o $(INCL)/console.o $(INCL)/join.o $(INCL)/list.o $(INCL)/os.o $(INCL)/pause.o $(INCL)/string.o
	$(CC) -g -Wall -std=c++11 -o main.exe main.cpp $(INCL)/color.o $(INCL)/colors.o $(INCL)/console.o $(INCL)/join.o $(INCL)/list.o $(INCL)/os.o $(INCL)/pause.o $(INCL)/string.o

$(INCL)/stdafx.h.gch:
	$(CC) $(FLAGS) -o $(INCL)/stdafx.h.gch $(INCL)/stdafx.h

$(INCL)/all.h.gch: $(INCL)/exits.h.gch
	$(CC) $(FLAGS) -o $(INCL)/all.h.gch $(INCL)/all.h

$(INCL)/exits.h.gch:
	$(CC) $(FLAGS) -o $(INCL)/exits.h.gch $(INCL)/exits.h

$(INCL)/color.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) -o $(INCL)/color.o $(INCL)/color.cpp

$(INCL)/colors.o: $(INCL)/stdafx.h.gch $(INCL)/os.o
	$(CC) $(FLAGS) -o $(INCL)/colors.o $(INCL)/colors.cpp

$(INCL)/console.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) -o $(INCL)/console.o $(INCL)/console.cpp

$(INCL)/join.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) -o $(INCL)/join.o $(INCL)/join.cpp

$(INCL)/list.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) -o $(INCL)/list.o $(INCL)/list.cpp

$(INCL)/os.o: $(INCL)/stdafx.h.gch $(INCL)/join.o
	$(CC) $(FLAGS) -o $(INCL)/os.o $(INCL)/os.cpp

$(INCL)/pause.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) -o $(INCL)/pause.o $(INCL)/pause.cpp

$(INCL)/string.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) -o $(INCL)/string.o $(INCL)/string.cpp