/* Coder: Joseph Villanueva
 * Class: COEN 12 - Data Structures
 * File: deque.c
 *
 * Description: This is a file which implements the deque abstract data
 * 				type. This is used in maze.c and radix.c. This is done
 * 				using a circular doubly-linked list with a sentinel/
 * 				dummy node. This requires a header called deque.h.
 */

//These are the includes that are used to run this code
#include "deque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//This is a define which cleans up code
#define dummy dp->head

//This is the struct of the node that will be used for the linked list

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}node;

//This is the struct of the list

typedef struct deque
{
	int count;
	node *head;
}deque;

//This function creates the dummy and list node : O(1)

deque *createDeque(void)
{
	node *sentinel = malloc(sizeof(node));
	deque *dp = malloc(sizeof(deque));
	assert(dp != NULL && sentinel != NULL);
	sentinel -> prev = sentinel;
	sentinel -> next = sentinel;
	dummy = sentinel;
	dp -> count = 0;
	return dp;
}

//This function destroys the linked list, the dummy then the dp: O(n)

void destroyDeque(deque *dp)
{
	node *temp, *prev;
	temp = prev = dummy -> next;
	while (temp != dummy)
	{
		temp = temp -> next;
		free(prev);
		prev = temp;
	}
	free(dummy);
	free(dp);

}

//This function returns the  number of items in the list: O(1)

int numItems(deque *dp)
{
	assert(dp != NULL);
	return dp->count;
}

//This function adds x as the first item in the deque pointed to by dp: O(1)

void addFirst(deque *dp, int x)
{
	assert(dp != NULL);
	dp -> count++;
	node *newNode = malloc(sizeof(node));
	newNode -> data = x;
	newNode -> next = dummy -> next;
	newNode -> prev = dummy;
	dummy -> next -> prev = newNode;
	dummy -> next = newNode;
}

//This function adds x as the last item in the deque pointed to by dp: O(1)

void addLast(deque *dp, int x)
{
	assert(dp != NULL);
	dp -> count++;
	node *newNode = malloc(sizeof(node));
	newNode -> data = x;
	newNode -> prev = dummy -> prev;
	newNode -> next = dummy;
	dummy -> prev -> next = newNode;
	dummy -> prev = newNode;
}

//This function removes and returns the first item in the deque  pointed to
//by dp; the deque must not be empty: O(1)

int removeFirst(deque *dp)
{
	assert(dp != NULL && dp -> count > 0);
	dp -> count--;
	node *temp = dummy -> next;
	dummy -> next = temp -> next;
	temp -> next -> prev = temp -> prev;
	int x = temp -> data;
	free(temp);
	return x;
}


//This function removves and returns the last item in the deque pointed to
//by dp; the deque must not be empty: O(1)

int removeLast(deque *dp)
{
	assert(dp != NULL && dp -> count > 0);
	dp -> count--;
	node *temp = dummy -> prev;
	dummy -> prev = temp -> prev;
	temp -> prev -> next = temp -> next;
	int x = temp -> data;
	free(temp);
	return x;
}

//This function returns, but does not remove, the first item's data in the deque
//pointed to by dp; the deque must not be empty: O(1)

int getFirst(deque *dp)
{
	assert(dp != NULL && dummy -> next != NULL);
	return dummy -> next -> data;
}

//This function returns, but does not remove, the last item's data in the deque
//pointed to by dp; the deque must not be empty: O(1) 

int getLast(deque *dp)
{
	assert(dp != NULL && dummy -> prev != NULL);
	return dummy -> prev -> data;
}

//BE CAREFUL WITH THIS: This automatically sets the last item in the list to 0. This should only
//be used with the COEN 177 paging algorithm lab.
void makeLastUnreferenced(deque *dp)
{
	assert(dp != NULL && dummy -> prev != NULL);
	dummy -> prev -> data = 0;
	return;
}

//This is used to search the deque to find an element
int search(deque *dp, int x)
{
	//Assert and init variables
	assert(dp != NULL && dp -> count != 0);
	int i = 0;
	int found = 0;
	int position = 0;
	node *temp = malloc(sizeof(node));
	temp = dummy -> next; 

	//For loop to find the element
	for (i = 0; i < dp -> count; i++)
	{
		//If found break
		if(temp -> data == x)
		{
			found = 1;
			printf("found %d!\n", x);
			break;
		}

		//Else move to next one 
		else
		{
			temp = temp -> next;
			position++;
		}
	}
	if (found == 1)
		return position;
	else
		return -1;
}

//This is used ot print the contents of the deque
void printDeque(deque *dp)
{
	//Initialize variables
	assert(dp != NULL && dp -> count != 0);
	int i = 0;
	node *temp = malloc(sizeof(node));
	temp = dummy -> next;

	//For loop to loop through each and print
	for(i = 0; i < dp -> count; i++)
	{
		printf("\nnode %d: %d\n", i, temp -> data);
		temp = temp -> next;
	}
	
	//Print the count of the deque
	printf("\ncount: %d\n", dp -> count);

	return;
}

//Move the one at the position to the front
void moveToFirst(deque *dp, int position)
{
	//Init variables
	assert(dp != NULL && dp -> count > position);
	int i = 0;
	node *temp = malloc(sizeof(node));
	temp = dummy -> next;

	//For Loop to move to the place where I want to move the node
	for(i = 0; i < position; i++)
	{
		temp = temp -> next;
	}

	//Update the pointers
	temp -> next -> prev = temp -> prev;
	temp -> prev -> next = temp -> next;
	temp -> next = dummy -> next;
	temp -> prev = dummy;
	dummy -> next -> prev = temp;
	dummy -> next = temp;	
	
	return;
};
//Change the data of a node, this should only be used in COEN 177
void UpdateData(deque *dp, int position, int data)
{
	//Init variables
	assert(dp != NULL && dp -> count > position);
	int i;
	node *temp = malloc(sizeof(node));
	temp = dummy -> next;

	//For Loop to move to the place I want to update
	for(i = 0; i < position; i++)
	{
		temp = temp -> next;
	}

	//Update the data
	temp -> data = data;

	return;
}
