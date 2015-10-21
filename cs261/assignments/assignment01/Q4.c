/* CS261- Assignment 1 - Q.4*/
/* Name: Brian Wilkins
 * Date: 10/8/2015
 * Solution description: This program generates a random list of
 * student IDs and a Score for each student. The students are
 * sorted from lowest score to highest score using the sort()
 * function.
 */

#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

/**************************************************************
* Entry: struct student* students containing 10 struct student objects
*        int n which is number of student objects
*
* Exit: *students is sorted by lowest score to highest score
*
* Purpose: Sorts *students from lowest to highest score.
***************************************************************/
void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
     int i;                 //counter
     int j;                 //counter
     struct student temp;   //temp variable to store the larger score before switching

     for (i = 0; i < n - 1; i++)
     {
        for (j = i + 1; j < n; j++)
        {
            //if the first score is larger than the second
            //score, switch them
            if (students[i].score > students[j].score)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
     }
}

/**************************************************************
* Entry: N/A.
*
* Exit: returns 0 if successful.
*
* Purpose: Creates 10 struct student* students objects with unique
*          IDs. Prints the unsorted array of IDs and scores. 
*          Passes students to sort(). Prints sorted array of 
*          IDs and students.
***************************************************************/
int main(){
     /*Declare an integer n and assign it a value.*/
     int n = 10;
     /*Allocate memory for n students using malloc.*/
     struct student* students = (struct student*) malloc(sizeof(struct student) * n);

     /*Generate random IDs and scores for the n students, using rand().*/
     int i;          //counter
     int idUsed[n];  //array to store if id is used (0 = id not used, 1 = id used)

     //create array of parity "bits" with all 0 (0 = id not used, 1 = id used)
     for (i = 0; i < n; i++)
     {
        idUsed[i] = 0;
     }

     //loop through for each student
     for (i = 0; i < n; i++)
     {
        //generate random id
        students[i].id = (rand() % n) + 1;
        //while an id has been used, generate a new id
        while (idUsed[students[i].id] == 1)
        {
            students[i].id = (rand() % n) + 1;
        }

        //at this point a unique id was generated, so set parity to 1
        idUsed[students[i].id] = 1;
        //generate random score for student
        students[i].score = rand() % 101;
     }

    /*Print the contents of the array of n students.*/
     printf("\nUnsorted Students by Scores\n");
     printf("============================\n");
     for (i = 0; i < n; i++)
     {
        printf("ID%d Score: %d\n", students[i].id, students[i].score);
     }

    /*Pass this array along with n to the sort() function*/
     sort(students, n);

    /*Print the contents of the array of n students.*/
     printf("\nSorted Students by Scores\n");
     printf("==========================\n");
     for (i = 0; i < n; i++)
     {
        printf("ID%d Score: %d\n", students[i].id, students[i].score);
     }

    return 0;
}
