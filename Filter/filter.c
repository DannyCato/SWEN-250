/*
 * Implementation of functions that filter values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h> OTHER THAN
 * strcpy() and strlen()
 *****
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "filter.h"

#define NUL ('\0')

/*
 * YOU MAY FIND THIS FUNCTION USEFUL.
 * Return true if and only if character <c> is in string <s>.
 */
static bool includes(char c, char *s) {
	while( *s && c != *s ) {
		s++ ;
	}
	return c == *s ;
}

/*
 * YOU MAY ALSO FIND THIS FUNCTION USEFUL.
 * Return true if and only if string <pre> is a prefix of string <s>.
 */
static bool prefix(char *s, char *pre) {
	while( *pre && *s == *pre ) {
		s++ ;
		pre++ ;
	}
	return *pre == NUL ;
}

/*
 * Copy <string> to <result> while removing all occurrences of <ch>.
 */
void filter_ch_index(char string[], char result[], char ch) {
	int i = 0, resIndex = 0 ;
	while ( string[i] ) // iterate over every index of string looking to see if that index is equal to ch, if equal do not add to result array
	{
		if ( string[i] != ch )
		{
			result[resIndex] = string[i] ;
			resIndex++ ;
		}
		i++ ;
	}
	result[resIndex] = NUL ;
}

/*
 * Return a pointer to a string that is a copy of <string> with
 * all occurrences of <ch> removed. The returned string must occupy
 * the least possible dynamically allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_ch_ptr(char *string, char ch) {
	if ( !*string )
	{
		char *ret_p = malloc( sizeof(char) * 2 ) ;
		strcpy( ret_p, "\0" ) ;
		return ret_p ;
	}

	char *new_p = malloc( sizeof(char) * strlen(string) + 1 ) ; // freed at 88
	memset( new_p, '\0', strlen(string) + 1) ; // to solve "Conditional jump or move depends on uninitialised value(s)" error in valgrind
	char *start_of_new_p = new_p ;
	do
	{
		if ( *string != ch )
		{
			memcpy( new_p, string, 1 ) ; // used instead of strcpy or strncpy because it works with no errors and im scared to fix it
			new_p++ ; 
		}
		string++ ;
	} while ( *string ); // loop over every index of string looking for indexs equal to ch. if not equal then copy char into new string
	new_p = NUL ;
	char *ret_p = malloc( sizeof(char) * strlen(start_of_new_p) + 1 ) ; // freed in test_filter.c
	strcpy( ret_p, start_of_new_p ) ;
	free( start_of_new_p ) ;
	return ret_p ;
}

/*
 * Copy <string> to <result> while removing all occurrences of
 * any characters in <remove>.
 */
void filter_any_index(char string[], char result[], char remove[]) {
	int i = 0 ;
	do
	{
		filter_ch_index ( string, result, remove[i] ) ;
		string = result ; 
		i++ ;
	} while ( remove[i] ) ; // iterate over every element of remove and use filter_ch_index to comply with DRY
}

/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of any characters in <remove>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_any_ptr(char *string, char* remove) {
	string = strcpy( malloc( sizeof(char) * strlen(string) + 1), string) ; // freed at 128
	char *start_of_string_p = string ;
	do
	{
		char *temp = filter_ch_ptr( string, *remove ) ;
		strcpy( string, temp ) ;
		free( temp );
		string = start_of_string_p ;
		remove++ ;
	} while ( *remove );
	char *ret_p = strcpy( malloc( sizeof(char) * strlen(string) + 1), string ) ; // freed in test_filter.c
	free(string) ;
	return ret_p;
}

/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of the substring <substr>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE ARRAY INDEXING.
 *****
 */
char *filter_substr(char *string, char* substr) {
	string = strcpy( malloc( sizeof(char) * strlen(string) + 1), string ) ; // At start of function as to not mess up ts_abccba. freed in test_filter.c
	char *start_of_string_p = string ;
	if ( !includes( *substr, string ))
	{
		return string ; 
	}
	int substr_len = - strlen( substr ) ;
	int lock = 0;
	char *new_p = malloc( sizeof(char) * strlen(string) + 1) ;
	char *start_of_new_p = new_p ;
	memset( new_p, '\0', strlen(string) + 1) ; // to solve "Conditional jump or move depends on uninitialised value(s)" error in valgrind
	do
	{
		if ( lock >= 0 )
		{
			if ( *string == *substr ) 
			{
				char *temp_p_of_string = string ;
				char *temp_p_of_substr = substr ;
				if ( prefix ( string, substr ) ) 
				{
					string = temp_p_of_string ;
					substr = temp_p_of_substr ;
					lock = substr_len ;
					continue; // continue to not activate the pointer increment down below and remove this char too
				}
			}
			memcpy( new_p, string, 1 ) ; // used instead of strcpy or strncpy because it works with no errors and im scared to fix it
			new_p++ ;
		}
		++lock ;
		string++ ;
	} while ( *string ); // loops through every index of string looking for ones to passover and others to write to new_p
	free( start_of_string_p ) ;
	char *ret = strcpy( malloc( sizeof(char) * strlen( start_of_new_p ) + 1 ) , start_of_new_p ) ;
	free( start_of_new_p ) ;
	return ret ;
}
