/* CS261- Assignment 3 -  Dynamic array implementation*/
/* Name: Brian Wilkins
 * Date: 10/25/2015
 * Solution description: This is the implementation file for the
 * Dynamic array.
 * Citation: Some code provided by the instructor, and some code
 * used is based on the work of Group 7 on the worksheets for
 * week 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q)
{
  	/* FIXME: you must write this */
  	assert(q != NULL && q != 0);
	q->size = 0;
	q->Sentinel = (struct DLink *)malloc(sizeof(struct DLink));

	assert(q->Sentinel != 0);
	//since this is empty, Sentinel next and prev points to self
	q->Sentinel->next = q->Sentinel;
	q->Sentinel->prev = q->Sentinel;
}

/*
 create a new circular list deque

 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
	struct DLink* newLink = (struct DLink *)(malloc(sizeof(struct DLink)));
	assert(newLink != 0);
	newLink->value = val;
	return(newLink);
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */
	//create the new link to be inserted
	struct DLink *newLnk = _createLink(v);

	assert(q != NULL && q != 0);
	assert(lnk != NULL);

    lnk->next->prev = newLnk;   //prev pointing to sentinel points to newLnk
	newLnk->next = lnk->next;   //newLnk next points to where sentinel next points
	lnk->next = newLnk;         //sentinel next points to newLnk
	newLnk->prev = lnk;         //newLnk prev points to sentinel
	q->size++;                  //increase size of circular list
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */
	assert(q != NULL && q != 0);
	_addLinkAfter(q, q->Sentinel->prev, val);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */
	assert(q != NULL && q != 0);
	_addLinkAfter(q, q->Sentinel, val);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	assert(q != NULL && q != 0);
	assert(q->size != 0);
	return(q->Sentinel->next->value);
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	assert(q != NULL && q != 0);
	assert(q->size != 0);
	return(q->Sentinel->prev->value);
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */
	assert(q != 0 && !isEmptyCirListDeque(q));

	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	free(lnk);
	q->size--;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */
	assert(q != 0 && !isEmptyCirListDeque(q));
	_removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */
  	assert(q != 0 && !isEmptyCirListDeque(q));
	_removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	while(q->size > 0)
	{
		removeFrontCirListDeque(q);
    }
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
	return(q->size == 0);
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	printf("\nsize of deque is: %d\n", q->size);

	struct DLink* idx = q->Sentinel->next;  //idx is equal to first item Sentinel points to
	assert(idx != 0);

	//loop through all list items until the Sentinel is reached
	while(idx != q->Sentinel)
	{
		printf("%g\n", idx->value);
		idx = idx->next;
	}
	printf("\n");
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	assert(q != 0 && !isEmptyCirListDeque(q));

	struct DLink* idx = q->Sentinel->next;
	//temp needed for swap
	struct DLink* temp;

	q->Sentinel->prev = idx;

    //swapping next and prev pointers for each list item as long
    //as idx is not equal to Sentinel
	do{
		temp = idx->next;
		if(temp->next == q->Sentinel){
			q->Sentinel->next = temp;
		}
		idx->next = idx->prev;
		idx->prev = temp;
		idx = temp;
	} while(idx != q->Sentinel);
}
