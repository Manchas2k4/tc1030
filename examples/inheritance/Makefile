all: package.o twoday.o overnight.o main.o
	g++ package.o twoday.o overnight.o main.o -o app

package.o: package.h package.cpp
	g++ -c package.cpp

twoday.o: twoday.h twoday.cpp
	g++ -c twoday.cpp

overnight.o: overnight.h overnight.cpp
	g++ -c overnight.cpp

main.o: main.cpp
	g++ -c main.cpp