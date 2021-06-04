all: character.o hero.o enemy.o room.o main.o
	g++ *.o -o app

character.o: character.h character.cpp
	g++ -c character.cpp

hero.o: hero.h hero.cpp
	g++ -c hero.cpp

enemy.o: enemy.h enemy.cpp
	g++ -c enemy.cpp

room.o: room.h room.cpp
	g++ -c room.cpp

main.o: main.cpp
	g++ -c main.cpp
