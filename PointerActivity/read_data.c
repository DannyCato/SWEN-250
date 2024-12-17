/*
 * Implementation of the read_data module.
 *
 * See read_data.h for a description of the read_data function's
 * specification.
 *
 * Note that the parameter declarations in this module must be
 * compatible with those in the read_data.h header file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "read_data.h"

// Reads the three fields from lines such as W$1349$1.414$ into
// local variables using getchar().
// Converts the two numeric fields to numbers using atoi for the
// integer fields and atof for the double.
// Using a correctly defined set of parameters (use pointers) pass
// those values back to the program that called this function.
void read_data( char *C, int *I, double *D ) {
	char input[80];
	int i = 0;
	int selector = 0;
	int character;
	while ((character = getchar()) != EOF)
	{
		if (character == '$') 
		{
			input[i] = '\0';
			i = 0;
			switch (selector)
			{
				case 0:
					{
						*C = input[0];
						break;
					}
				case 1:
					{
						*I = atoi(input);
					}
					break;

				case 2:
					{
						*D = atof(input);
					}
					break;
			}
			selector++;
			if (selector == 3) {
				break;
			}
			continue;
		}
		input[i] = character;
		i++;
	}

	return ;
}
