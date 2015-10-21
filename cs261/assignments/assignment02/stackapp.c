/*	stack.c: Stack application. */
/* CS261- Assignment 2 - Part 3 - Dynamic Array Stack*/
/* Name: Brian Wilkins
 * Date: 10/18/2015
 * Solution description: This program uses a dynamic array stack
 * to check for unbalanced ()[] and {}.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{
	//a string was not entered
	if (s == NULL) {
        return 0;
	}

	int capacity = 10;				//number of characters in s
	char thisChar = nextChar(s);			//a single char from s
    DynArr *parens = newDynArr(capacity);	//dynamic array for ()
    DynArr *brackets = newDynArr(capacity);	//dynamic array for []
    DynArr *curly = newDynArr(capacity);	//dynamic array for {}

    //while a valid char, check to see if it is ()[] or {}
    while (thisChar != '\0')
    {
    	switch(thisChar)
    	{
    		case '(':
    			pushDynArr(parens, thisChar);   //put ( in the array
    			break;
    		case ')':
				if (isEmptyDynArr(parens)) //array is empty, so this is unbalanced
				{
					//free memory
					deleteDynArr(parens);
					deleteDynArr(brackets);
					deleteDynArr(curly);
					return 0;
				}
				else
				{
					popDynArr(parens);	//remove the ( from the array because it's match was found
				}
				break;

    		case '[':
    			pushDynArr(brackets, thisChar);   //put [ in the array
    			break;
    		case ']':
				if (isEmptyDynArr(brackets)) //array is empty, so this is unbalanced
				{
					//free memory
					deleteDynArr(parens);
					deleteDynArr(brackets);
					deleteDynArr(curly);
					return 0;
				}
				else
				{
					popDynArr(brackets);	//remove the [ from the array because it's match was found
				}
				break;

    		case '{':
    			pushDynArr(curly, thisChar);   //put { in the array
    			break;
    		case '}':
				if (isEmptyDynArr(curly)) //array is empty, so this is unbalanced
				{
					//free memory
					deleteDynArr(parens);
					deleteDynArr(brackets);
					deleteDynArr(curly);
					return 0;
				}
				else
				{
					popDynArr(curly);	//remove the { from the array because it's match was found
				}
				break;
    	}
    	thisChar = nextChar(s); //get the next character to process
    }

    //all dynamic arrays are empty so the string is balanced
	if (isEmptyDynArr(parens) && isEmptyDynArr(brackets) && isEmptyDynArr(curly))
	{
		//free memory
		deleteDynArr(parens);
		deleteDynArr(brackets);
		deleteDynArr(curly);
		return 1; //return that the string is balanced
	}

    //if we get here, at least one of the arrays was not empty, which means there
    //is an unbalanced set of ()[] or {}

	//free memory
	deleteDynArr(parens);
	deleteDynArr(brackets);
	deleteDynArr(curly);
	return 0; //return that the string is not balanced
}

int main(int argc, char* argv[]){

	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}

