test: main.o shape.o circle.o square.o
	g++ -g -o test main.o shape.o circle.o square.o

main.o: main.cpp shape.h shape.cpp square.h square.cpp circle.h circle.cpp
	g++ -g -c main.cpp

shape.o: shape.h shape.cpp
	g++ -g -c shape.cpp
	
circle.o: circle.h circle.cpp shape.h shape.cpp
	g++ -g -c circle.cpp

square.o: square.h square.cpp shape.h shape.cpp
	g++ -g -c square.cpp

clean:
	rm -f *.o test