//Author: Joseph Villanueva
//
//FileName: lru.c
//
//Description: This program will simulate a least recently used  caching algorithm. This will be done
//			   using a deque data structure. A true deque has the requirement that you can only
//			   remove from either the first or last itme in the doubly-linked circularly list.
//			   However, I have modified a deque.c to move a node within the deque to the front.
//			   This is extremely helpful for making this program.
//
//			   To implement a lru algorithim, one must have a linked list of pages (accomplished
//			   with a deque). If there is room, at it to the front, as the front is the node that
//			   was "most recently used". When searching for a node, if it is found, move that node
//			   to the front. If there is no room, and it is not found, delete the node that is
//			   in the back and then add the new node to the front. This algorithim does not
//			   care about a reference bit.
//
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
	int size = strtol(argv[1], &p, 9);
	int num;
	int position = -1 ; /*default set to not found, otherwise, it is the search return value*/
	int referenced;
	char str[20];
	//Initialize the deque
	DEQUE *data_deque;
	data_deque = createDeque(); //This will be the deque that stores all of the numbers

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
			//Search the deque to see if it is in there. If it is, do not add the page. Instead, move it to first

			position = search(data_deque, num);
			if (position != -1)
			{
				moveToFirst(data_deque, position);
				continue;
			}
			
			//This is where deletion occurs
			else
			{
				referenced = removeLast(data_deque);
				addFirst(data_deque, num);
				faults++;
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
					moveToFirst(data_deque, position);
					continue;
				}
			}
			
			faults++;
			addFirst(data_deque, num);
			printDeque(data_deque);
		}
	}
	printf("This is the number of lru page faults %d", faults);
	return 0;
}
