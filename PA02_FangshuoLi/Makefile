#main generator

all: main inputGenerator

main: main.o settings.h inputFile.txt Sort.h
	g++ main.o -o main

main.o: main.cpp settings.h Sort.h
	g++ -c main.cpp -std=c++11


#to create the text file
inputGenerator: inputGenerator.cpp settings.h
	g++ -o inputGenerator inputGenerator.cpp -std=c++11



clean:
	rm *.o main inputGenerator
