#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <cstdint>
#include "LeftLeaningRedBlack.h"
#include "VoidRef.h"

#define INTEGER_COUNT 10
#define MAX_RAND 20

int main()
{
    //seed the random generator
    srand(time(NULL));

    //create testing BST
    LeftLeaningRedBlack * node = new LeftLeaningRedBlack();

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

    VoidRef_t tempKey;

    for (int i = 0; i < index; i++)
    {
        //add array to LLRB
        tempKey.Key = array[i];
        node -> Insert(tempKey);

        //print info
        std::cout << "\n\n =================" << i + 1 << ". Entry" << std::endl;

        //node Info
        LLTB_t * currentNode = node -> LookUp(tempKey.Key);
        std::uint32_t nodeKey = (currentNode -> Ref).Key;
        bool NodeisRed = currentNode->IsRed;

        std::cout << "Node Value: " << nodeKey << std::endl;
        std::cout << "Node Color: ";
        if (NodeisRed)
            std::cout << "Red" << std::endl;
        else
            std::cout << "Black" << std::endl;


        std::cout << "\n" << std::endl;

        //find immediate parent
        LLTB_t * parentNode = node -> FindParent(tempKey);
        if (parentNode != NULL)
        {
            std::uint32_t parentKey = (parentNode -> Ref).Key;
            bool isRed = parentNode -> IsRed;

            std::cout << "Parent Value: " << parentKey << std::endl;
            std::cout << "Parent Color: ";
            if (isRed)
                std::cout << "Red" << std::endl;
            else
                std::cout << "Black" << std::endl;
        }

        if (i == 3)
        {
            std::cout << "************\n"
                      << "NODE DELETED\n"
                      << "************"
                      <<std::endl;

            node -> Delete(tempKey.Key);
        }
    }

    //Display tree
    std::cout << "\n\n\nTRAVERSAL" << std::endl;
    node->Traverse();

    return 0;
}
