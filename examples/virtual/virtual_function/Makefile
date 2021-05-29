all: character.o hero.o enemy.o main.o
	g++ *.o -o app

character.o: character.h character.cpp
	g++ -c character.cpp

hero.o: hero.h hero.cpp
	g++ -c hero.cpp

enemy.o: enemy.h enemy.cpp
	g++ -c enemy.cpp

main.o: main.cpp
	g++ -c main.cpp
