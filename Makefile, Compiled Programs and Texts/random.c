//Author: Joseph Villanueva
//
//FileName: random.c
//
//Description: This program will simulate a random caching algorithm. This will be done
//			   using a deque data structure. A true deque has the requirement that you can only
//			   remove from either the first or last itme in the doubly-linked circularly list.
//			   This is extremely helpful for making this program.
//
//			   This random algorithm will always add to the front. If there is no room in the
//			   list, then it will randomly choose a position in the cache and delete that one
//			   before it adds the new page to the front. If there is room, just add the page
//			   to the front. It must still search to ensure that it doesn't add the same 
//			   page twice.
//				

//Include statements

#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char *argv[])
{
	
	//Initialize the variables used in the main
	int faults = 0;
	char *p;
	int size = strtol(argv[1], &p, 9);
	int num;
	int position = -1 ; /*default set to not found, otherwise, it is the search return value*/
	int del_position, del_data;
	char str[20];
	srand(time(NULL));
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
			//Search the deque to see if it is in there. If it is, do not add the page. Instead, increase the reference at that position

			position = search(data_deque, num);
			if (position != -1)
			{
				continue;
			}
			
			//This is where deletion occurs
			else
			{
				del_position = rand() % numItems(data_deque) + 1;
				fprintf(stderr, "random #:%d\n", del_position);
				addFirst(data_deque, num);
				faults++;
				del_data = removePosition(data_deque, del_position);
				fprintf(stdout, "%d\n", num);
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
					continue;
				}
			}
			faults++;
			addFirst(data_deque, num);
			fprintf(stdout, "%d\n", num);
		}
	}
	fprintf(stderr, "\nThis is the number of random page faults %d\n", faults);
	return 0;
}
