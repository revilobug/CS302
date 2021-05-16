//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------


#include <iostream>

using namespace std;

#include "StackLinked.h"


//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------


int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin || inputLine == "<EOF>")              // Reached EOF: stop processing
            break;

        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}


//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below


bool delimitersOk ( const string &expression )
{
    //create the Linked List
    StackLinked <char> stack;

    char test;

    //increment through the string one character at a time
    for (char const &temp: expression)
    {
        //if the character is the '[' character
        if (temp == 91)
        {
            stack.push(temp);
        }
        else {
          //if the character is the ']' character
          if (temp == 93)
          {
              //if the stack is empty then there is no corresponding '['
              if(stack.isEmpty())
                  return false;
              test = stack.pop();
              //check to see if the last character on the stack is '['
              if (test != 91)
                  return false;
          }
        }
    }
    //if made it out of loop, check if stack is Empty
    if (stack.isEmpty())
      return true;
    else
      return false;
}
