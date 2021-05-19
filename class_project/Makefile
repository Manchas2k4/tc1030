all: date.o item.o user.o borrowed.o main.o
	g++ date.o item.o user.o main.o -o app

date.o: types.h date.h date.cpp
	g++ -c date.cpp

item.o: types.h item.h item.cpp
	g++ -c item.cpp

user.o: types.h user.h user.cpp
	g++ -c user.cpp

borrowed.o: types.h borrowed.h borrowed.cpp
	g++ -c borrowed.cpp

main.o: types.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o app
