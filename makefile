CC    = g++
FLAGS = -g -c -Wall -std=c++11
INCL  = includes
TEST  = tests

main.exe: $(INCL)/all.hpp.gch $(TEST)/all.hpp.gch
	$(CC) -g -Wall -std=c++11 -o main.exe main.cpp

$(INCL)/all.hpp.gch: $(INCL)/color.hpp.gch $(INCL)/colors.hpp.gch $(INCL)/console.hpp.gch $(INCL)/join.hpp.gch $(INCL)/list.hpp.gch $(INCL)/os.hpp.gch $(INCL)/pause.hpp.gch $(INCL)/string.hpp.gch
	$(CC) $(FLAGS) $(INCL)/all.hpp

$(INCL)/color.hpp.gch:
	$(CC) $(FLAGS) $(INCL)/color.hpp

$(INCL)/colors.hpp.gch: $(INCL)/os.hpp.gch
	$(CC) $(FLAGS) $(INCL)/colors.hpp

$(INCL)/console.hpp.gch:
	$(CC) $(FLAGS) $(INCL)/console.hpp

$(INCL)/join.hpp.gch:
	$(CC) $(FLAGS) $(INCL)/join.hpp

$(INCL)/list.hpp.gch:
	$(CC) $(FLAGS) $(INCL)/list.hpp

$(INCL)/os.hpp.gch: $(INCL)/join.hpp.gch
	$(CC) $(FLAGS) $(INCL)/os.hpp

$(INCL)/pause.hpp.gch:
	$(CC) $(FLAGS) $(INCL)/pause.hpp

$(INCL)/string.hpp.gch:
	$(CC) $(FLAGS) $(INCL)/string.hpp

$(TEST)/all.hpp.gch: $(TEST)/colors.hpp.gch $(TEST)/etest.hpp.gch $(TEST)/join.hpp.gch $(TEST)/string.hpp.gch
	$(CC) $(FLAGS) $(TEST)/all.hpp

$(TEST)/colors.hpp.gch:
	$(CC) $(FLAGS) $(TEST)/colors.hpp

$(TEST)/etest.hpp.gch: $(INCL)/all.hpp
	$(CC) $(FLAGS) $(TEST)/etest.hpp

$(TEST)/etest.join.hpp.gch: $(TEST)/etest.hpp.gch
	$(CC) $(FLAGS) $(TEST)/join.hpp

$(TEST)/join.hpp.gch: $(TEST)/etest.hpp.gch
	$(CC) $(FLAGS) $(TEST)/join.hpp

$(TEST)/string.hpp.gch: $(TEST)/etest.hpp.gch
	$(CC) $(FLAGS) $(TEST)/string.hpp
