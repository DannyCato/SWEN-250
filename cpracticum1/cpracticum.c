// C (no pointers) Practicum
// SWEN-250
// Larry Kiser November 1, 2015

#include <stdlib.h>
#include <stdio.h>
#include "cpracticum.h"
#include "unit_tests.h"

// Determine whether or not the passed string is in sorted ascending order.
// For the purpose of this exam sort order is determined by simply
// comparing the numeric values of the characters in the string.
// You can assume that only printable characters are included in the string.
// If you have a string with a '9' (0x39), a ':' (0x40), and a 'A' (0x41)
// it must be "9:A" to be considered to be in sorted ascending order.
// ALSO -- successive characters that are the same character are considered to
// be sorted (e.g. "AAAAA" is sorted).
//
// Hint -- create a loop that goes to the end of the string that
// compares adjacent characters. You can exit the loop as soon as you
// see one pair of characters out of order. Be sure to not compare the '\0'
// at the end of the string!
//
// Return 0 if any character is not in ascending order.
// Return 1 if all characters in the entire string are in ascending order.
//
// NOTE -- you must handle an empty string -- return 1 if empty.
// NOTE 2 -- a string with just one character is sorted -- return a 1.
//
// You are NOT allowed to use any library functions to do this.
// You must loop through the array and return the correct result.
int string_is_sorted( char mystring[] )
{
	int result = 0 ;
	int i = 0 ;
	while ( mystring[i] != '\0' )
	{
		if ( mystring[i - 1] == '\0' )
		{
			i++;
			continue ;
		}
		else 
		{
			if ( mystring[i] - 1 != mystring[i - 1] && mystring[i] != mystring[i - 1])
			{
				return 0 ;
			}
		}
		i++;
	}

	
	return 1 ;
}

// This function is implemented incorrectly. You need to correct it.
// It is supposed to sum up the integers in the array for the number of entries in the
// second parameter.
// It returns that sum.
int fix_bad_code( int numbers[], int number_of_entries )
{
	int index ;
	int sum = 0 ;
	int answer ;
	
	for ( index = 0 ; index < number_of_entries ; index++ ) 
	{
		sum += numbers[index] ;
	}

	return sum ;
}



// Returns the mydata struct that is typedef'ed in cpracticum.h
// Find the lowest upper case letter in the passed string and put that the struct.
// that your return.
// Count the number of upper case letters in the passed string (A through Z) and put that in the struct.
// NOTE -- you must handle an empty string. If you have an empty string, then
//         set the lowest_upper_case_letter to '\0' and the upper_case_count to 0.
// NOTE -- you cannot use any library functions in this code.
// For your convenience I have made a copy of that struct definition below:
//
// Hint -- you may want to initialize a char variable to a value higher than 'Z' to
// help with finding the highest letter.
//
//typedef struct
//{
//	char lowest_upper_case_letter ;	// This would be A if A is anywhere in the string.
//							// If there are NO upper case letters (A through Z) then this must be a 0 or '\0'.
//							// Yes, this is the same as the End of String marker ('\0').
//	int upper_case_count ;	// The number of upper case letters in the string.
//} mydata ;

mydata get_string_info( char mystring[] )
{
	mydata data ;
	data.upper_case_count = 0 ;

	int i = 0;
	data.lowest_upper_case_letter = '\0' ;	
	while ( mystring[i] != '\0' ) 
	{
		if ( mystring[i] >= 65 && mystring[i] <= 90)
		{
			if ( data.lowest_upper_case_letter == '\0' ) 
			{
				data.lowest_upper_case_letter = mystring[i] ;
			}
			data.upper_case_count++ ;
			int diff = mystring[i] - data.lowest_upper_case_letter ;
			if ( diff < 0 )
			{
				data.lowest_upper_case_letter = mystring[i] ;
			}			
		}
		i++;
	}
	
	return data ;
}

// Run the unit tests or as a "normal program".
int main( int argc, char *argv[] ) {

	// Execute unit tests
	return test() ;
}
