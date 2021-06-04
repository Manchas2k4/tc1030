all: cell.o animal.o main.o
	g++ *.o -o app

cell.o: cell.h cell.cpp
	g++ -c cell.cpp

animal.o: animal.h animal.cpp
	g++ -c animal.cpp

main.o: main.cpp
	g++ -c main.cpp