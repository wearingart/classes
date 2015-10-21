/* CS261- Assignment 1 - Q.1*/
/* Name: Brian Wilkins
 * Date: 10/5/2015
 * 
 * Solution description: This program generates a random list of
 * student IDs and Scores for 10 students using several different
 * functions (see function descriptions below).The scores are then
 * checked to determine the highest and lowest scores, and the
 * average score is calculated. The list of IDs and Scores are
 * printed to the console, as well as the highest, lowest, and average
 * scores.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int NUM_STUDENTS = 10; //constant for number of students

struct student{
	int id;
	int score;
};

/**************************************************************
* Entry: N/A.
*
* Exit: returns s with allocated memory for NUM_STUDENTS
*
* Purpose: allocates memory for NUM_STUDENTS for struct student*
*          object.
***************************************************************/
struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* s = (struct student*) malloc(sizeof(struct student) * NUM_STUDENTS);
     /*return the pointer*/
     return s;
}

/**************************************************************
* Entry: struct student* students with memory allocated for 
*        NUM_STUDENTS
*
* Exit: struct student* students contains generated IDs and
*       scores for NUM_STUDENTS
*
* Purpose: Generates student IDs and scores for NUM_STUDENTS.
***************************************************************/
void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     int i;                     //counter
     int idUsed[NUM_STUDENTS];  //array to store if id is used (0 = id not used, 1 = id used)

     //create array of parity "bits" with all 0 (0 = id not used, 1 = id used)
     for (i = 0; i < NUM_STUDENTS; i++)
     {
        idUsed[i] = 0;
     }

     //loop through for each student
     for (i = 0; i < NUM_STUDENTS; i++)
     {
        //generate random id
        students[i].id = (rand() % NUM_STUDENTS) + 1;
        //while an id has been used, generate a new id
        while (idUsed[students[i].id] == 1)
        {
            students[i].id = (rand() % NUM_STUDENTS) + 1;
        }

        //at this point a unique id was generated, so set parity to 1
        idUsed[students[i].id] = 1;
        //generate random score for student
        students[i].score = rand() % 101;
     }
}

/**************************************************************
* Entry: struct student* students with memory allocated for 
*        NUM_STUDENTS
*
* Exit: NUM_STUDENTS IDs and Scores have been printed.
*
* Purpose: Prints NUM_STUDENTS IDs and Scores
***************************************************************/
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i;

    for (i = 0; i < NUM_STUDENTS; i++)
    {
        printf("ID%d Score: %d\n", students[i].id, students[i].score);
    }
}

/**************************************************************
* Entry: struct student* students with memory allocated for 
*        NUM_STUDENTS
*
* Exit: Minimum, maximum, and average scores are printed.
*
* Purpose: Calculates the minimum, maximum, and average of the 
*          scores for the NUM_STUDENTS in *students, then prints
*          the results.
***************************************************************/
void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int i;                         //counter
     int min = students[0].score;   //minimum score
     int max = students[0].score;   //maximum score
     int avg = 0;                   //average score
     int scoresTotal = 0;           //total of all scores

     for (i = 0; i < NUM_STUDENTS; i++)
     {
        //if student score is less than current min, new score is min
        if (students[i].score < min)
        {
            min = students[i].score;
        }
        //if student score is less than current max, new score is max
        if (students[i].score > max)
        {
            max = students[i].score;
        }
        //get total of all scores to be used to calculate avg.
        scoresTotal = scoresTotal + students[i].score;
     }
     //calculate average score
     avg = scoresTotal / NUM_STUDENTS;

     printf("\nSCORES SUMMARY\n");
     printf("===================\n");
     printf("Minimum score: %d\n", min);
     printf("Maximum score: %d\n", max);
     printf("Average score: %d\n", avg);

}

/**************************************************************
* Entry: struct student* students with memory allocated for 
*        NUM_STUDENTS
*
* Exit: Memory for struct student* students is freed.
*
* Purpose: Free memory for struct student* students
***************************************************************/
void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if (stud != NULL)
     {
        free(stud);
     }
}

/**************************************************************
* Entry: N/A.
*
* Exit: returns 0 if successful.
*
* Purpose: Create a stuct student* object, then call functions
*          allocate(), generate(), output(), summary(), and 
*          deallocate().
***************************************************************/
int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
