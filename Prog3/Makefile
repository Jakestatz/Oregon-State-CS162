CC = g++ -std=c++11 -g
exe_file = Zoo_tycoon

$(exe_file): Animal.o Bear.o Sealion.o Tiger.o Functions.o Zoo.o Driver.o
	$(CC) Animal.o Bear.o Sealion.o Tiger.o Functions.o Zoo.o Driver.o -o $(exe_file)
Animal.o: Animal.cpp Animal.h
	$(CC) -c Animal.cpp
Bear.o: Bear.h Bear.cpp
	$(CC) -c Bear.cpp
Sealion.o: Sealion.h Sealion.cpp
	$(CC) -c Sealion.cpp
Tiger.o: Tiger.h Tiger.cpp
	$(CC) -c Tiger.cpp
Functions.o: Functions.h Functions.cpp
	$(CC) -c Functions.cpp
Zoo.o: Zoo.h Zoo.cpp
	$(CC) -c Zoo.cpp
Driver.o: Driver.cpp
	$(CC) -c Driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
