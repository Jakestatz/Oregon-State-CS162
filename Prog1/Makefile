CC = g++ -std=c++11
exe_file = Program1
$(exe_file): Program1.o prog.o
	$(CC) Program1.o prog.o -o $(exe_file)
Program1.o: Program1.cpp
	$(CC) -c Program1.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
