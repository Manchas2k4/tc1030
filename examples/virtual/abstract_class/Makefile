all: rectangle.o circle.o main.o
	g++ rectangle.o circle.o main.o -o app

rectangle.o: figure.h rectangle.h rectangle.cpp
	g++ -c rectangle.cpp

circle.o: figure.h circle.h circle.cpp
	g++ -c circle.cpp

main.o: main.cpp
	g++ -c main.cpp