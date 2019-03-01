CC    = g++
FLAGS = -g -c -Wall -std=c++11
INCL  = includes
TEST  = tests

main.exe: $(INCL)/stdafx.h.gch $(INCL)/all.h.gch $(TEST)/all.h.gch $(INCL)/exits.h.gch $(INCL)/color.o $(INCL)/colors.o $(INCL)/console.o $(INCL)/join.o $(INCL)/list.o $(INCL)/os.o $(INCL)/pause.o $(INCL)/random.o $(INCL)/string.o $(TEST)/etest.o $(TEST)/colors.o $(TEST)/string.o
	$(CC) -g -Wall -std=c++11 -o main.exe main.cpp $(INCL)/color.o $(INCL)/colors.o $(INCL)/console.o $(INCL)/join.o $(INCL)/list.o $(INCL)/os.o $(INCL)/pause.o $(INCL)/random.o $(INCL)/string.o $(TEST)/etest.o $(TEST)/colors.o $(TEST)/string.o

$(INCL)/stdafx.h.gch:
	$(CC) $(FLAGS) -o $(INCL)/stdafx.h.gch $(INCL)/stdafx.h

$(INCL)/all.h.gch: $(INCL)/exits.h.gch
	$(CC) $(FLAGS) -o $(INCL)/all.h.gch $(INCL)/all.h

$(TEST)/all.h.gch:
	$(CC) $(FLAGS) -o $(TEST)/all.h.gch $(TEST)/all.h

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

$(INCL)/random.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) -o $(INCL)/random.o $(INCL)/random.cpp

$(INCL)/string.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) -o $(INCL)/string.o $(INCL)/string.cpp

$(TEST)/colors.o: $(INCL)/stdafx.h.gch $(TEST)/etest.o $(INCL)/colors.o
	$(CC) $(FLAGS) -o $(TEST)/colors.o $(TEST)/colors.cpp

$(TEST)/etest.o: $(INCL)/stdafx.h.gch $(INCL)/colors.o
	$(CC) $(FLAGS) -o $(TEST)/etest.o $(TEST)/etest.cpp

$(TEST)/string.o: $(INCL)/stdafx.h.gch $(TEST)/etest.o $(INCL)/string.o
	$(CC) $(FLAGS) -o $(TEST)/string.o $(TEST)/string.cpp