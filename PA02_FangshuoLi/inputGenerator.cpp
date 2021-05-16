#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "settings.h"

int main() {
    //creating random seed
    srand(time(NULL));
    int random;

    //opening file
    std::ofstream file;
    file.open ("inputFile.txt");

    //add in the values
    for (int ind = 0; ind < INTEGER_COUNT; ind++)
    {
        random = rand() % MAX_RAND;
        file << random << " ";
    }

    //closing file
    file.close();

    return 0;
}
