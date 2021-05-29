all: character.o hero.o main.o 
	g++ character.o hero.o main.o -o app

character.o: character.h character.cpp
	g++ -c character.cpp

hero.o: hero.h hero.cpp
	g++ -c hero.cpp

main.o: main.cpp
	g++ -c main.cpp