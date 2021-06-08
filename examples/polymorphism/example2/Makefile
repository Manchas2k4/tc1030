all: currency.o main.o
	g++ *.o -o app

currency.o: currency.h currency.cpp
	g++ -c currency.cpp

main.o: main.cpp
	g++ -c main.cpp