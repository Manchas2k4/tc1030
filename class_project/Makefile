all: utils.o date.o item.o user.o ucatalog.o borrowed.o main.o
	g++ utils.o date.o item.o user.o ucatalog.o borrowed.o main.o -o app

utils.o: utils.h utils.cpp
	g++ -c utils.cpp

date.o: date.h date.cpp
	g++ -c date.cpp

item.o: item.h item.cpp
	g++ -c item.cpp

user.o: user.h user.cpp
	g++ -c user.cpp

ucatalog.o: ucatalog.h ucatalog.cpp
	g++ -c ucatalog.cpp

borrowed.o: borrowed.h borrowed.cpp
	g++ -c borrowed.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o app
