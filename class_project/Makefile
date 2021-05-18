all: date.o item.o main.o
	g++ date.o item.o main.o -o app

date.o: date.h date.cpp
	g++ -c date.cpp

item.o: item.h item.cpp
	g++ -c item.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o app