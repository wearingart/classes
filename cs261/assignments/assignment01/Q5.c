/* CS261- Assignment 1 - Q.5*/
/* Name: Brian Wilkins
 * Date: 10/9/2015
 * Solution description: Converts a word entered by the user into
 * sticky case (e.g. horse to HoRsE). This program uses the custom
 * fuctions toUpperCase and toLowerCase to convert characters. The
 * sticky() function processes the word and calls the appropriate
 * case changing function. The converted word is then displayed
 * for the user.
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/**************************************************************
* Entry: char* word
*
* Exit: *word is converted to sticky caps
*
* Purpose: Takes *word and converts it to sticky caps. Every odd
*          letter is capitalized, every even letter is lowercased.
***************************************************************/
void sticky(char* word){
     /*Convert to sticky caps*/
     int i = 0;    //counter

     //Perform loop as long as end marker \0 is not found
     do
     {
        //if i is evenly divisible, we have an even number
        if( i % 2 == 0) {
            //even indexed character
            if( word[i] >= 'a' && word[i] <= 'z') {
                //upper case
                word[i] = toUpperCase(word[i]);
            }
        } else {
            //odd indexed character
            if( word[i] >= 'A' && word[i] <= 'Z' ) {
                //lower case
                word[i] = toLowerCase(word[i]);
            }
        }
        //increment counter
        i++;
     } while (word[i] != '\0');
}

/**************************************************************
* Entry: N/A.
*
* Exit: returns 0 if successful.
*
* Purpose: Allocates memory for char *word and asks user to type
*          a word. The word is passed to sticky() so it can be
*          converted to sticky caps.
***************************************************************/
int main(){
    //create character pointer with 140 characters
    char *word = (char*) malloc(sizeof(char*) * 140);
    /*Read word from the keyboard using scanf*/
    printf("Type a word to be put in StIcKy CaPs: ");
    scanf("%140s", word);

    /*Call sticky*/
    sticky(word);

    /*Print the new word*/
    printf("\n%s\n", word);

    return 0;
}
