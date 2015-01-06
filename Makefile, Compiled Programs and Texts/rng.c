/*Author: Joseph Villanueva
 *
 * Title: rng.c
 *
 * Purpose: This will output a textfile to a textfile called workload. Workload must contain 1 million lines
 * of numbers that are randomly generated using the following code. This is done using random() and
 * srand(time(NULL)). The number generated will then be modded with the upper limit. If the range is below
 * a lower limit, then discard the number. The numbers will in general range from 0 to 10000. 
 *
 */

//Include statements

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	//Init Variables
	int count = 0, section, prev_section;
	int num, prevnum = 0;
	int ulimit = 100, llimit;
	FILE *outfile;
	outfile = fopen("rng.txt", "w");
	srand(time(NULL));
	while (count < 1000000)
	{
		num = random();
		if (count % 10 == num % 10)
		{
			num = (prevnum  + 1);
		}
		if(count % 10000 == 0)
		{
			section = count / 10000;
			ulimit = 100*section;
			llimit = ulimit - 100;
		}
		if (num > ulimit || num < ulimit)
		{
			num = (num % 100) + llimit;
			fprintf(outfile, "%d\n", num);
			count++;
		}
		else
		{ 
			fprintf(outfile, "%d\n", num);
			count++;
		}
	}
}

