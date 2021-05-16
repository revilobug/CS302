#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <memory>
#include "binaryNode.h"
#include "binarySearchTree.h"
#define INTEGER_COUNT 100
#define MAX_RAND 200

int main ()
{
    //seed the random generator
    srand(time(NULL));

    //create testing BST
    std::shared_ptr<BinarySearchTree<int>> node = std::make_shared<BinarySearchTree<int>>();

    //create necessary variables
    int array [INTEGER_COUNT];
    size_t index = 0;
    int temp;
    bool condition;

    //while there are less than INTEGER_COUNT numbers
    while (index < INTEGER_COUNT)
    {
        //condition is used to see if there are duplicates
        condition = true;

        //generate values
        temp = rand() % MAX_RAND;

        //increment through array to find duplicates
        for (int i = 0; i < index; i++)
        {
            //if duplicate found set condition to false
            if (temp == array[i])
            {
                condition = false;
            }
        }

        //only if no duplicate was found
        if (condition)
        {
            //add number to array
            array[index] = temp;
            index++;
        }
    }

    std::cout << "original set: " << std::endl;
    for (int i = 0; i < index; i++)
    {
        //print array
        std::cout << array[i] << std::endl;
        //add array to BST
        node -> add(array[i]);
    }

    //printing Output
    std::cout << "Height of Tree:" << node -> getHeight() << std::endl;
    std::cout << "In Order Traversal: " << std::endl;
    node -> inorderTraverse();
    std::cout << "Pre Order Traversal: " << std::endl;
    node -> preorderTraverse();
    std::cout << "Post Order Traversal: " << std::endl;
    node -> postorderTraverse();

    return 0;
}
