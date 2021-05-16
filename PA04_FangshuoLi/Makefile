#main generator

all: main

LeftLeaningRedBlack.o: LeftLeaningRedBlack.h LeftLeaningRedBlack.cpp VoidRef.h
 	g++ -c LeftLeaningRedBlack.cpp -std=c++14

main.o: main.cpp LeftLeaningRedBlack.o
	g++ -c main.cpp -std=c++14

main: main.o LeftLeaningRedBlack.o
	g++ main.o LeftLeaningRedBlack.o -o main -std=c++14

clean:
	rm *.o main
