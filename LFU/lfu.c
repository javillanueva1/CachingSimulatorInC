//Author: Joseph Villanueva
//
//FileName: lfu.c
//
//Description: This program will simulate a least frequently used caching algorithm. 
//			   This will be done using a deque data structure. A true deque has 
//			   the requirement that you can only remove from either the first 
//			   or last itme in the doubly-linked circularly list. However, I have 
//			   modified a deque.c to remove and update a node within the deque.
//			   This is extremely helpful for making this program.
//
//			   To implement a lfu algorithm, one has two linked list of pages (accomplished
//			   with a deque). If there is room, add it to the front, as the front is 
//			   the node that was "most recently used". When searching for a node,
//			   if it is found, update the corresponding reference node. If there is 
//			   no room, and it is not found, delete the node that has the lowest
//			   reference and then add the new node to the front. If there is a tie,
//			   delete the one used least recently. The order of most frequently used
//			   to least recently is kept because you add to the front and you delete the min
//			   that is rearmost.
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
	int del_reference, del_position, del_data, referenced;
	char str[20];
	//Initialize the deque
	DEQUE *data_deque, *reference_deque;
	data_deque = createDeque(); //This will be the deque that stores all of the numbers
	reference_deque = createDeque(); //Number of times a page is referenced

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
			//Search the deque to see if it is in there. If it is, do not add the page. Instead, increase the reference at that position

			position = search(data_deque, num);
			if (position != -1)
			{
				referenced = getPosition(reference_deque, position);
				referenced++;
				UpdateData(reference_deque, position,referenced );
				continue;
			}
			
			//This is where deletion occurs
			else
			{
				del_position = findMin(reference_deque);
				del_data = removePosition(data_deque, del_position);
				del_reference = removePosition(reference_deque, del_position);
				addFirst(data_deque, num);
				addFirst(reference_deque, 1);
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
					referenced = getPosition(reference_deque, position);
					referenced++;
					UpdateData(reference_deque, position, referenced);
					continue;
				}
			}
			faults++;
			addFirst(data_deque, num);
			addFirst(reference_deque, 1);
		}
	}
	printf("This is the number of lfu page faults %d", faults);
	return 0;
}
