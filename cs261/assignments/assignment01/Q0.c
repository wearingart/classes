/* CS261- Assignment 1 - Q. 0*/
/* Name: Brian Wilkins
 * Date: 10/5/15
 * 
 * Solution description: This program is used to demonstrate how
 * pointers, references, and values work by printing them to the
 * console. An int variable is created and used to show the printed
 * address, the value pointed to, the address pointed to, and the
 * address of the variable.
 */

#include <stdio.h>
#include <stdlib.h>


/**************************************************************
* Entry: iptr is a pointer to int x in main()
*
* Exit: Value pointed to by iptr
*
* Purpose: Print the value pointed to by iptr, print the address
*          pointed to by iptr, and print the address of iptr
*
***************************************************************/
void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("%d\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("%p\n", iptr);
     /*Print the address of iptr itself*/
     printf("%p\n", &iptr);
}


/**************************************************************
* Entry: N/A. int x is set to a value to be used by fooA()
*
* Exit: returns 0 if successful.
*
* Purpose: Sets variable and calls fooA() to demonstrate how
*          pointers work.
*
***************************************************************/
int main(){

    /*declare an integer x*/
    int x = 44;

    /*print the address of x*/
    printf("%p\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("%d\n", x);


    return 0;
}
