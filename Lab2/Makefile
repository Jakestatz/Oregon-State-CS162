CC = g++ -std=c++11
exe_file = student_db
$(exe_file): student_db.o driver.o
	$(CC) student_db.o driver.o -o $(exe_file)
mult_div.o: student_db.cpp
	$(CC) -c student_db.cpp
prog.o: driver.cpp
	$(CC) -c driver.cpp

