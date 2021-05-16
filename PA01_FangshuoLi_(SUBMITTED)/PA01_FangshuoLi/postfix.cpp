//
//  PostFix.cpp
//  Li_Fangshuo_PA01
//
//  Created by Oliver Li on 9/15/20.
//  Copyright © 2020 Oliver Li. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include "StackLinked.h"

using namespace std;

int main ()
{
    cout << "Enter the Postfix expression: ";

    StackLinked<float> stack;

    int counter = 1;
    char temp;
    float value, operand1, operand2, result;
    while ((temp = getchar()) && temp != '\n')
    {
      if (temp == ' ')
        continue;

        //if is a number
        if (temp >= 48 && temp <= 57){
            value = temp - 48;
            stack.push(value);
        }
        //if a operator
        else
        {
            //pop off two numbers
            operand2 = stack.pop();
            operand1 = stack.pop();

            switch (temp){
                //multiply
                case 42:
                    result = operand1 * operand2;
                    stack.push(result);
                    break;
                //add
                case 43:
                    result = operand1 + operand2;
                    stack.push(result);
                    break;
                //subtract
                case 45:
                    result = operand1 - operand2;
                    stack.push(result);
                    break;
                //divide
                case 47:
                    result = operand1 / operand2;
                    stack.push(result);
                    break;
                //exponent
                case 94:
                    result = operand1;
                    for (int i = 0; i < operand2 - 1; i++)
                        result *= operand1;
                    stack.push(result);
                    break;
                default:
                    stack.push(operand1);
                    stack.push(operand2);
                    cout << "error please only use single digit numbers and * + - / ^ operators" << endl;
                    break;
            }
        }
    }
//remove
    cout << "result: " << stack.pop() << endl;

    //pop them one at a time

    return 0;
}
