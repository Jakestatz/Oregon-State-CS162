CC = g++ -std=c++11 -g
exe_file = Linked

$(exe_file): Driver.o Functions.o Linked_List.hpp Node.hpp
	$(CC) Driver.o Functions.o Linked_List.hpp Node.hpp -o $(exe_file)
Driver.o: Driver.cpp Linked_List.hpp
	$(CC) -c Driver.cpp
Functions.o: Functions.cpp Functions.h
	$(CC) -c Functions.cpp
clean:
	rm -f *.out *.o $(exe_file)
