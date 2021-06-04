all: fraction.o main.o
	g++ *.o -o app

fraction.o: fraction.h fraction.cpp
	g++ -c fraction.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o app