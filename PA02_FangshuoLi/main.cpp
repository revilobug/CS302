#include <stdio.h>
#include <iostream>
#include <fstream>
#include "settings.h"
#include "Sort.h"
#include <chrono>

int main ()
{
    //opening file
    std::ifstream file;
    file.open ("inputFile.txt");
    Sort sorter;
    auto start = std::chrono::high_resolution_clock::now();
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    /*
    ************
    READ IN FILE
    ************
    */
    //create original array
    int array[INTEGER_COUNT];

    //read in data
    for (int ind =0; ind < INTEGER_COUNT; ind++){
        file >> array[ind];
    }

    //create the respective arrays
    int insertArray [INTEGER_COUNT], mergeArray [INTEGER_COUNT];
    for (int ind =0; ind < INTEGER_COUNT; ind++){
         insertArray[ind] = array[ind];
         mergeArray[ind] = array[ind];
    }


    /*
    *********
    MERGESORT
    *********
    */

    std::cout << "\n";
    std::cout << "**********"
              << "MERGE SORT"
              << "**********" << std::endl;
    std::cout << "Performing Merge Sort ..." << std::endl;

    for (int ind = 0; ind < 2; ind++)
    {
        if (ind == 1)
        {
            std::cout << "\nSorted Speed Test: " << std::endl;
            sorter.setMergeSwap(0);
            sorter.setMergeCompare(0);
        }

        //time for process
        start = std::chrono::high_resolution_clock::now();

        sorter.mergeSort (mergeArray, 0, INTEGER_COUNT-1);

        //time for process
        stop = std::chrono::high_resolution_clock::now();
        elapsed_seconds = stop - start;
        std::cout << "Time for Process: " << elapsed_seconds.count() << std::endl;

        //swaps and comparisons
        std::cout << "Swaps: " << sorter.getMergeSwap() << std::endl;
        std::cout << "Compares: " << sorter.getMergeCompare() << std::endl;
        std::cout << "\n";
    }

    /*
    **********
    INSERTSORT
    **********
    */

    std::cout << "***********"
              << "INSERT SORT"
              << "***********" << std::endl;
    std::cout << "Performing Insert Sort ..." << std::endl;

    for (int ind = 0; ind < 2; ind++)
    {
        if (ind == 1)
        {
            std::cout << "\nSorted Speed Test: " << std::endl;
            sorter.setInsertSwap(0);
            sorter.setInsertCompare(0);
        }

        //time for process
        start = std::chrono::high_resolution_clock::now();

        //sorting
        sorter.insertSort (insertArray);

        //time for process
        stop = std::chrono::high_resolution_clock::now();
        elapsed_seconds = stop - start;
        std::cout << "Time for Process: " << elapsed_seconds.count() << std::endl;

        //swaps and comparisons
        std::cout << "Swaps: " << sorter.getInsertSwap() << std::endl;
        std::cout << "Compares: " << sorter.getInsertCompare() << std::endl;

        std::cout << "\n";
    }
    return 0;
}
