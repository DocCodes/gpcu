CC    = g++
FLAGS = -g -c -Wall -std=c++11
INCL  = includes
TEST  = tests

main.exe: $(INCL)/stdafx.h.gch $(INCL)/all.h.gch $(INCL)/color.o $(INCL)/colors.o $(INCL)/console.o $(INCL)/join.o $(INCL)/list.o $(INCL)/os.o $(INCL)/pause.o $(INCL)/string.o
	$(CC) -g -Wall -std=c++11 -o main.exe main.cpp

$(INCL)/stdafx.h.gch:
	$(CC) $(FLAGS) $(INCL)/stdafx.h

$(INCL)/all.h.gch:
	$(CC) $(FLAGS) $(INCL)/all.h

$(INCL)/color.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) $(INCL)/color.cpp

$(INCL)/colors.o: $(INCL)/stdafx.h.gch $(INCL)/os.o
	$(CC) $(FLAGS) $(INCL)/colors.cpp

$(INCL)/console.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) $(INCL)/console.cpp

$(INCL)/join.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) $(INCL)/join.cpp

$(INCL)/list.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) $(INCL)/list.cpp

$(INCL)/os.o: $(INCL)/stdafx.h.gch $(INCL)/join.o
	$(CC) $(FLAGS) $(INCL)/os.cpp

$(INCL)/pause.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) $(INCL)/pause.cpp

$(INCL)/string.o: $(INCL)/stdafx.h.gch
	$(CC) $(FLAGS) $(INCL)/string.cpp