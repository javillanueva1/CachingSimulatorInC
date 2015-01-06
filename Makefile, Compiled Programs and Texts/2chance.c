//Author: Joseph Villanueva
//
//FileName: 2Chance.c
//
//Description: This program will simulate a second chance caching algorithm. This will be done
//			   using a deque data structure. A deque has the requirement that you can only
//			   remove from either the first or last itme in the doubly-linked circularly
//			   linked list. This is alright considering that a second chance algorthim requires
//			   that you check from the front and also replace in the front.
//
//			   To implement a second chance algorithm, when adding a number to the data structure,
//			   make it a "referenced page". When there is no longer "memory" (as dictated by
//			   the number that is passed in when initially running the program) and more memory
//			   needs to be allocated for a new page, a page fault occurs. When a page fault
//			   occurs in a second chance algorithm, the algo tries to delete the first one.
//			   However, if the first one is referenced, then it is moved to the back and is
//			   unreferenced. Then it checks the next one to see whether or not it can be deleted.
//
//			   For when you need to make room for a new page, update all reference bits to zero
//				

//Include statements

#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	
	//Initialize the variables used in the main
	int faults = 0;
	char *p;
	long size = strtol(argv[1], &p, 10);
	int num;
	int position = -1; /*default set to not found*/
	int referenced, referenced_number, previous_reference;
	char str[20];
	//Initialize the deque
	DEQUE *data_deque;
	DEQUE *reference_deque;
	data_deque = createDeque(); //This will be the deque that stores all of the numbers
	reference_deque = createDeque(); //This will be the deque that stores all of the reference bits

	//Put each number into the deque 
	while(fgets(str, sizeof(str), stdin))
	{
		if(isdigit(str[0]))
			sscanf(str, "%d", &num);
		else
			continue;	
		//If the request is more than the number of page frames and is also not found, delete something
		if (numItems(data_deque) >= size)
		{
			//Search the deque to see if it is in there. If it is, do not add the page.

			position = search(data_deque, num);
			if (position != -1)
			{
				UpdateData(reference_deque, position, 1);
				continue;
			}

			while(1)
			{
				//Check whether the first number is referenced
				referenced = getFirst(reference_deque);

				//If it is not referenced, this will be the place where deletion happens
				if (referenced == 0)
				{
					//increment the number of page faults that occur
					faults++;	
					//This is where the deletion of the first number and the addition of the new page occur
					referenced_number = removeFirst(data_deque);
					previous_reference = removeFirst(reference_deque);
					addLast(data_deque, num);
					addLast(reference_deque, 1);
					fprintf(stdout, "%d\n", num);
					break;
				}

				//If it is referenced, we have to move the first to the back, then make the last reference bit
				//unreferenced
				else
				{
					referenced_number = removeFirst(data_deque);
					previous_reference = removeFirst(reference_deque);
					addLast(data_deque, referenced_number);
					addLast(reference_deque, 0);	
				}
			}

				}
		//If the numItems is less than the number of page frames
		if (numItems(data_deque) < size)
		{
			//Search the deque to see if it is in there. If it is, do not add the page (this does not happen if it is the first)
			if(numItems(data_deque) > 0)
			{
				position = search(data_deque, num);
				if (position != -1)
				{
					UpdateData(reference_deque, position, 1);
					continue;
				}
			}
			
			faults++;
			addLast(data_deque, num);
			addLast(reference_deque, 1);
			fprintf(stdout, "%d\n", num);
			continue;
		}
	}
	fprintf(stderr, "\nThis is the number of 2nd chance page faults %d\n", faults);
	return 0;
}
