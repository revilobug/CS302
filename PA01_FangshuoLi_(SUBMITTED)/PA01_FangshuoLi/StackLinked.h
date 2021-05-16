//--------------------------------------------------------------------
//
//  StackLinked.h
//
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_H
#define STACKLINKED_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

  public:

    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();

    void push( const DataType & value ) throw(logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:
    class StackNode {
    public:
        StackNode(const DataType& nodeData, StackNode * nextPtr)
        {
            dataItem = nodeData;
            next = nextPtr;
        }

        DataType dataItem;
        StackNode * next;
    };

    StackNode * top;
};


//param-ctor
template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber): top(NULL)
{
}




//copy-ctor
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked & other): top(NULL)
{
    (*this) = other;
}

//dtor
template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
    clear();
}


//assignment operator
template <typename DataType>
StackLinked<DataType> & StackLinked<DataType>::operator=(const StackLinked<DataType> & other)
{
    this -> clear();

    //assign first values
    this->top = other.top;

    //make temporary pointer to increment and assignm values with
    StackNode * thatptr = other.top;
    StackNode * thisptr = top;

    StackNode * indexptr = thatptr;
    for (indexptr = thatptr; indexptr != NULL; indexptr -> next)
    {
        thisptr = new StackNode (other.top -> data, other.top -> next);
        thatptr = thatptr -> next;
        thisptr = thisptr -> next;
    }
}


//push
template <typename DataType>
void StackLinked<DataType>::push(const DataType & value) throw (logic_error)
{
    try {
        //dynamically allocate new Node
        StackNode * nodeptr = new StackNode (value, top);

        //point top to new top
        top = nodeptr;
    } catch (logic_error)
    {
        cout << "error with push" << endl;
    }
}



//pop
template <typename DataType>
DataType StackLinked<DataType>::pop() throw(logic_error)
{
    try{
        if(!isEmpty())
        {
            //save the dataItem
            DataType data = top -> dataItem;

            //move top forward
            StackNode * nodeptr = top;
            top = top -> next;

            //remove the the pointer to the next node
            nodeptr -> next = NULL;
            //delete node
            delete nodeptr;

            //return the value
            return data;
        }

    } catch (logic_error)
    {
        cout << "error with push" << endl;
    }
    return '?';
}




//clear
template <typename DataType>
void StackLinked<DataType>::clear()
{
    while(!isEmpty())
        pop();
}





//isEmpty
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
    //if top points to something then not empty
    if (top == NULL)
        return true;

    return false;
}




//isFull
template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
    return false;
}




//showStructure
template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
    if (isEmpty())
        cout << "list is empty" << endl;

    else{
        cout << "[ ";

        StackNode * ptr = top;

        for(ptr = top; ptr != NULL; ptr = ptr->next)
            cout << ptr->dataItem << " ";

        cout <<"]" << endl;
    }
}



#endif        //#ifndef STACKLINKED_H
