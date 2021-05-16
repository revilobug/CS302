//insertion sort
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "settings.h"

class Sort
{
public:
    void insertSort (int *array);
    void mergeSort (int array[], int left, int right);

    //set
    long long getInsertSwap();
    long long getInsertCompare();
    long long getMergeSwap();
    long long getMergeCompare();

    //get
    void setInsertSwap(int value);
    void setInsertCompare(int value);
    void setMergeSwap(int value);
    void setMergeCompare(int value);

private:
    long long mergeSwap = 0, mergeCompare = 0, insertSwap = 0, insertCompare = 0;
    void swap (int * previous, int * current);
    void merge(int array[], int left, int right);
};

/*
*************
GET FUNCTIONS
*************
*/
long long Sort::getInsertSwap()
{
    return insertSwap;
}
long long Sort::getInsertCompare()
{
    return insertCompare;
}
long long Sort::getMergeSwap()
{
    return mergeSwap;
}
long long Sort::getMergeCompare()
{
    return mergeCompare;
}

/*
*************
SET FUNCTIONS
*************
*/
void Sort::setInsertSwap(int value)
{
    insertSwap = value;
}
void Sort::setInsertCompare(int value)
{
    insertCompare = value;
}
void Sort::setMergeSwap(int value)
{
    mergeSwap = value;
}
void Sort::setMergeCompare(int value)
{
    mergeCompare = value;
}

/*
**********
INSERTSORT
**********
*/

void Sort::insertSort (int *array)
{

    //declare variables
    int * currInd, * regressionInd, * regressionPrev;

/*
    for (currInd = array; currInd - array < INTEGER_COUNT; currInd++)
        std::cout << "Numbers " << currInd - array <<  ": " << *currInd << std::endl;
*/
    for (currInd = array+1, regressionInd = currInd, regressionPrev = array; currInd - array < INTEGER_COUNT; currInd++)
    {
        //compare currrent Index with the previous one
        regressionPrev = currInd - 1;
        regressionInd = currInd;

        while ((*regressionInd) <= (*regressionPrev) && regressionInd - array > 0)
        {
            insertCompare++;
            swap (regressionPrev, regressionInd);
            regressionPrev--;
            regressionInd--;
        }

        insertCompare++;
    }
}

void Sort::swap (int * previous, int * current)
{
    insertSwap++;
    int temp = *previous;

    *previous = *current;
    *current = temp;
}

/*
**********
MERGESORT
**********
*/

void Sort::merge(int array[], int left, int right)
{
    int * tempArray = new int[INTEGER_COUNT]; // Temporary array


    // Initialize the local indices to indicate the subarrays
    int mid = (left + right) / 2;
    int first1 = left; // Beginning of first subarray
    int last1 = mid; // End of first subarray
    int first2 = mid+1; // Beginning of second subarray
    int last2 = right; // End of second subarray
    int index = first1; // next available location in tempArray


    //while both arrays haven't paassed each other
    while ((first1<=last1) && (first2 <=last2))
    {
        // At this point, tempArray[first..index-1] is in order
        if (array[first1] <= array[first2])
            {
                mergeCompare++;
                tempArray[index] = array[first1];
                mergeSwap++;
                first1++;
            }
        else
            {
                mergeCompare++;
                tempArray[index] = array[first2];
                mergeSwap++;
                first2++;
            } // end if
            index++;
    } // end while
    while (first1<=last1)
    {
        // at this point, tempArray[first..index-1] is in order
        tempArray[index] = array[first1];
        mergeSwap++;
        first1++;
        index++;
    } // end while

    // Finish off the second subarray, if necessary while (first2<=last2)

    while (first2<=last2)
    {
        // at this point, tempArray[first..index-1] is in order
        tempArray[index] = array[first2];
        mergeSwap++;
        first2++;
        index++;
    } // end for
    // Copy the result back into the original array
    for (index=left; index<=right; index++)
        array[index] = tempArray[index];

    delete [] tempArray;
 }

void Sort::mergeSort (int array[], int left, int right)
{
    if (left < right)
    {
        //find the middle
        int mid = (left + right) / 2;
        //further split left side of array
        mergeSort(array, left, mid);
        //further split right side of array
        mergeSort(array, mid + 1, right);
        //merge the two sides
        merge(array, left, right);
    }
}
