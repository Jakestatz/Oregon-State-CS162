CC = g++ -std=c++11
exe_file = shape
$(exe_file): shape.o circle.o rectangle.o square.o application.o
	$(CC) shape.o application.o circle.o rectangle.o square.o -o $(exe_file)
shape.o: shape.cpp
	$(CC) -c shape.cpp
circle.o: circle.cpp
	$(CC) -c circle.cpp
rectangle.o: rectangle.cpp
	$(CC) -c rectangle.cpp
square.o: square.cpp
	$(CC) -c square.cpp
application.o: application.cpp
	$(CC) -c application.cpp
clean:
	rm -f *.o $(exe_file)
