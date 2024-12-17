/*
 * Implementation of functions that find values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h>
 *****
 */

#include <stdlib.h>
#include <stdbool.h>

#include "find.h"

#define NOT_FOUND (-1)	// integer indicator for not found.

/*
 * Return the index of the first occurrence of <ch> in <string>,
 * or (-1) if the <ch> is not in <string>.
 */
int find_ch_index(char string[], char ch) {
	int i = 0 ;
	while ( string[i] ) 
	{
		if ( string[i] == ch ) {
			return i ;
		}
		i++ ;
	}
	return NOT_FOUND ;	// placeholder
}

/*
 * Return a pointer to the first occurrence of <ch> in <string>,
 * or NULL if the <ch> is not in <string>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_ch_ptr(char *string, char ch) {
	if ( *string == '\0') 
	{
		return NULL ;
	}
	do 
	{
		if ( *string == ch ) {
			return (char*)string ;
		}
		string++;
	}
	while ( *string ) ;
	return NULL ;	// placeholder
}

/*
 * Return the index of the first occurrence of any character in <stop>
 * in the given <string>, or (-1) if the <string> contains no character
 * in <stop>.
 */
int find_any_index(char string[], char stop[]) {
	if (stop[0] == '\0')
	{
		return NOT_FOUND ;
	}

	int ret = 0;
	int index = 0 ;
	while ( string[index] ) 
	{
		if ( ret = find_ch_index( stop, string[index] ) >= 0 )
		{
			return index ;
		}
		index++;
	}
	return NOT_FOUND ;
}

/*
 * Return a pointer to the first occurrence of any character in <stop>
 * in the given <string> or NULL if the <string> contains no characters
 * in <stop>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_any_ptr(char *string, char* stop) {
	if (*stop == '\0')
	{
		return NULL ;
	}

	char *start = stop ;
	char *ret = NULL;
	do
	{
		stop = start ;
		ret = (char*) find_ch_ptr( stop, *string ) ;
		if ( ret != (char*) NULL )
		{
			return string ;
		}
		string++ ;
	} while ( *string ) ;
	return NULL ;
}

/*
 * Return a pointer to the first character of the first occurrence of
 * <substr> in the given <string> or NULL if <substr> is not a substring
 * of <string>.
 * Note: An empty <substr> ("") matches *any* <string> at the <string>'s
 * start.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_substr(char *string, char* substr) {
	if ( *substr == '\0' ) {
		return string ;
	}
	
	char *start = substr, *strstart = string;
	do
	{
		char* ret = find_ch_ptr( string, *substr ) ;
		if ( ret != NULL ) 
		{
			string = ret ;
			do
			{
				if ( *string != *substr )
				{
					substr = start ;
					break;
				}
				string++ ;
				substr++ ;
			} while ( *substr );
			if ( !(*substr))
			{
				return ret ;
			}
		}
		string++ ;
	} while ( *string ) ;
	return NULL ;
}
