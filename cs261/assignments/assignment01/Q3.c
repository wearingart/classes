/* CS261- Assignment 1 - Q.3*/
/* Name: Brian Wilkins
 * Date: 10/8/2015
 * 
 * Solution description: This program generates a list of 20
 * integers at random and prints the list. The list is then
 * sorted from lowest to highest using the sort() function.
 * The sorted list is then printed to the console.
 */

#include <stdio.h>
#include <stdlib.h>

/**************************************************************
* Entry: int* number which points to array of integers
*        int n which is number of array elements
*
* Exit: *number is sorted from lowest to highest number
*
* Purpose: Sorts *number from lowest to highest number.
***************************************************************/
void sort(int* number, int n){
     int i;     //counter
     int j;     //counter
     int temp;  //temp variable to store the larger int before switching

     /*Sort the given array number , of length n*/
     for (i = 0; i < n - 1; i++)
     {
        for (j = i + 1; j < n; j++)
        {
            //if the first number is larger than the second
            //number, switch them
            if (number[i] > number[j])
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
     }
}

/**************************************************************
* Entry: N/A.
*
* Exit: returns 0 if successful.
*
* Purpose: Creates array of 20 random integers, prints the integers,
*          passes array to sort(), then prints the sorted integers.
***************************************************************/
int main(){
    int i; //counter

    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *fooArray = (int*) malloc(sizeof(int) * n);

    /*Fill this array with random numbers, using rand().*/
    for (i = 0; i < n; i++)
    {
        fooArray[i] = rand() % (n + 1);
    }

    /*Print the contents of the array.*/
    printf("Unsorted Array Contents\n");
    printf("=======================\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\n", fooArray[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(fooArray, n);

    /*Print the contents of the array.*/
    printf("\nSorted Array Contents\n");
    printf("=======================\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\n", fooArray[i]);
    }

    free(fooArray);

    return 0;
}
