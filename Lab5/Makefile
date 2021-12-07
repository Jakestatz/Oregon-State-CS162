C = g++ -std=c++11
exe_file = profdemo
$(exe_file): profdemo.o driver.o
	$(CC) profdemo.o driver.o -o $(exe_file)
mult_div.o: profdemo.cpp
	$(CC) -c profdemo.cpp
prog.o: driver.cpp
	$(CC) -c driver.cpp
