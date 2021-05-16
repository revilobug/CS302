#main generator

all: main

# binaryNode.o: binaryNode.cpp binaryNode.h
# 	g++ -c binaryNode.cpp -std=c++14
#
# binarySearchTree.o: binarySearchTree.cpp binarySearchTree.h
# 	g++ -c binarySearchTree.cpp -std=c++14

main.o: main.cpp binaryNode.h binaryNode.cpp binarySearchTree.cpp binarySearchTree.h
	g++ -c main.cpp -std=c++14

main: main.o
	g++ main.o -o main

clean:
	rm *.o main
