/* CS261- Assignment 1 - Q.2*/
/* Name: Brian Wilkins
 * Date: 10/8/2015
 * Solution description: This program demonstrates how int pointers and
 * int values are manipulated when passed into a function.
 */

#include <stdio.h>
#include <stdlib.h>

/**************************************************************
* Entry: int *a is a pointer to x in main, int *b is a pointer 
*        to y in main, and int c is value of z in main()
*
* Exit: returns c, which is the calculated value of *a + *b
*
* Purpose: Doubles *a and halves *b, then return the value. This
*          is used to demonstrate how pointers are handled between
*          functions.
***************************************************************/
int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

/**************************************************************
* Entry: N/A.
*
* Exit: returns 0 if successful.
*
* Purpose: Sets values for three variables and prints those values.
*          Values are passed to fooValue() and then variables
*          are printed again to show how pointers and regular
*          variables are handled between functions. 
***************************************************************/
int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    int fooValue;

    /*Print the values of x, y and z*/
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    fooValue = foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("%d\n", fooValue);
    /*Print the values of x, y and z again*/
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);

    /*Is the return value different than the value of z?  Why?

    Yes. Because the value of z is not passed to foo() as a reference,
    it does not change values when printed a second time. If z had been
    passed by reference, z and the return value of foo() would be
    the same.*/
    return 0;
}


