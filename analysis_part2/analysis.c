// L. Kiser Nov. 9, 2023 updated to version 2

// Document Analysis project functions for Part 2

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "analysis.h"
#include "unit_tests.h"

// Helper function for read_file to validate inputs.
// Returns NULL if there is an error
static FILE *validate_read_file_parameters( struct linked_list *p_list, char *file_name )
{
	if ( p_list == NULL || file_name == NULL || *file_name == '\0' )	// if NULL list or if a bad or empty file name string return 0
		return NULL ;
	
	return fopen( file_name, "r" ) ;
}

// Optional helper function.
// returns 1 if pointers are OK, returns 0 if either is NULL.
static int check_linked_list( struct linked_list *p_list )
{
	if ( p_list != NULL )
	{
		if ( p_list->p_head != NULL && p_list->p_tail != NULL && p_list->p_current != NULL )
		{
			return 1 ;
		}
	}
	return 0 ;
}

// Optional helper function.
// Returns an initialized word entry structure from the current record in the list.
// If p_list has no current record returns 0 in word count and NULL in unique word pointer.
static struct word_entry get_current_entry( struct linked_list *p_list )
{
	struct word_entry entry = { NULL, 0 } ;	// initialize the structure to null string and 0 count

	if ( check_linked_list( p_list ) )
	{
		entry.unique_word = p_list->p_current->unique_word ;
		entry.word_count = p_list->p_current->word_count ;
	}

	return entry ;
}


// First checks that p_list is not NULL. Returns 0 if p_list is a NULL pointer.
// Then checks that word pointer is not NULL and word is not any empty string.
// Returns 0 if either of the above tests on the passed word fails.
//
// Creates the list if starting a fresh list.
// Searches existing list for a match on the word. Increments word count
// if found. If not found adds the word in alphabetic order.
// Returns 1 if the word was added successfully.
// Returns 0 on failure.
// NOTE -- this function makes no assumption on upper or lower case. That is handled by read_file.
// For simplicity all words passed from the unit tests are all lower case only.
int process_word ( struct linked_list *p_list, char *word )
{
	switch ( find_word( p_list, word ) )
	{
	case -1 :
		if ( valid_parameters( p_list, word ) )
		{
			if ( p_list->p_head == NULL )
			{
				add_node_at_head( p_list, word ) ;
				return 1 ;
			}
		}
		return 0 ;
		break ;

	case 0 :
		{
		int status = add_node_after_current( p_list, word ) ;
		if ( status == 0 )
		{
			return 0 ;
		}
		return 1 ;
		break ;
		}

	case 1 :
		p_list->p_current->word_count++ ;
		return 1 ;
		break ;

	default :
		return 0 ;
		break ;
	}	

}

// First checks that the passed string with the file name is not a NULL pointer and is not an empty string.
// Also checks that the passed pointer to the linked_list struct is not a NULL pointer.
// Returns 0 if any of the above tests fail.
// returns 0 if the file cannot be read or if the file does not contain any words as defined for this project.
// returns the number of words if the file was found, opened successfully, and it contained at least one valid word.
// NOTE -- this function MUST convert all words read to lower case only! e.g "First" becomes "first"
int read_file( struct linked_list *p_list, char *file_name )
{
	FILE *file = validate_read_file_parameters( p_list, file_name ) ;
	if ( file == NULL )
	{
		return 0 ;
	}

	char buffer[80] ;
	int ch = 0, i = 0, words = 0 ;
	while ( ( ch = fgetc( file ) ) != EOF ) 
	{ 
		// printf("current character is \'%c\'\n", ch ) ;
		if ( iscntrl( ch ) || isspace(ch) || ispunct( ch ) ) 
		{
			buffer[i] = '\0' ;
			if ( isalnum( buffer[0] ) )
			{
				//int code = 
				process_word( p_list, buffer ) ; // for debugging, move to line above to get exit code from process_word
				// printf("processed word is \"%s\" with code %i\n", buffer, code ) ;
				words++ ;
			}
			i = 0 ;
		}
		else 
		{
			buffer[i] = tolower( ch ) ;
			i++ ;
		}		
	}
	fclose( file ) ;
	return words ;
}


// Returns 0 in the word_count field if the p_list pointer is NULL.
// Returns 0 in the word_count field if no first word meaning p_head == NULL (empty list).
// Otherwise, returns a struct with the first unique word in the list and its number of occurrences in the text file.
// You must update the current pointer (p_current) to the node containing the first word.
struct word_entry get_first_entry( struct linked_list *p_list )
{
	struct word_entry entry ;			

	if ( check_linked_list( p_list ) )
	{
		p_list->p_current = p_list->p_head ;
		entry = get_current_entry( p_list ) ;
	}
	else 
	{
		entry.word_count = 0 ;		// cover empty list case.
		entry.unique_word = NULL ;	// init for empty list case.
	}
	return entry ;
}

// Returns 0 in the word_count field if p_list is NULL.
// Returns 0 in the word_count field if no next word (previously reached end of list or it is an empty list)
// Otherwise, returns a struct with the next unique word (after the node at p_current) and its number of occurrences in the text file.
// You must update the current pointer (p_current) to the node containing the next word.
struct word_entry get_next_entry( struct linked_list *p_list )
{
	struct word_entry entry ;
	
	if ( check_linked_list( p_list ) )
	{
		if ( p_list->p_current->p_next != NULL )
		{
			p_list->p_current = p_list->p_current->p_next ;
			entry = get_current_entry( p_list ) ;
			return entry ;
		}
	}

	entry.word_count = 0 ;		// cover end of list case.
	entry.unique_word = NULL ;	// init for empty list case.

	return entry ;
}

// Returns 0 in the word_count field if no previous word (was already at beginning of the list or it is an empty list).
// Otherwise, returns a struct with the previous unique word (relative to p_current) and its number of occurrences in the text file.
// You must update the current pointer (p_current) to the node containing the previous word.
struct word_entry get_prev_entry( struct linked_list *p_list )
{
	struct word_entry entry ;
	
	if ( check_linked_list( p_list ) )
	{
		if ( p_list->p_current->p_previous != NULL )
		{
			p_list->p_current = p_list->p_current->p_previous ;
			entry = get_current_entry( p_list ) ;
			return entry ;
		}
	}

	entry.word_count = 0 ;		// cover end of list case.
	entry.unique_word = NULL ;	// init for empty list case.

	return entry ;
}

// Returns 0 in the word_count field if the p_list pointer is NULL.
// Returns 0 in the word_count field if no last word meaning p_tail == NULL (empty list).
// Otherwise, returns a struct with the last unique word and its number of occurrences in the text file.
// You must update the current pointer (p_current) to the node containing the last word.
struct word_entry get_last_entry( struct linked_list *p_list )
{
	struct word_entry entry ;

	if ( check_linked_list( p_list ) )
	{
		p_list->p_current = p_list->p_tail ;
		entry = get_current_entry( p_list ) ;
	}
	else 
	{
		entry.word_count = 0 ;		// cover empty list case.
		entry.unique_word = NULL ;	// init for empty list case.
	}
	return entry ;
}

// First check the p_list is not NULL. Return 0 if it is NULL.
// Return 0 if the list is empty (e.g. p_head is NULL).
// Writes the sorted unique word list to a csv file.
// Receives the linked list pointer and the name of the file to be created.
// Returns 1 on a successful write of the file.
// Returns 0 on any failure.
// Test for a NULL or empty string in the file_name. Return 0 for failure if NULL or empty.
// Be sure to test for failure to open the file, failure to write to the file, and failure to close.
// You must have a header row exactly like this (without the quotes): "word,count"
// You must have one row for each unique word and its count (e.g. without quotes "student,5").
// It must be in sorted order and must be the complete list.
int write_unique_word_list_to_csv_file(  struct linked_list *p_list, char *file_name )
{
	FILE *p_write = NULL ;
	if ( ( p_write = validate_read_file_parameters( p_list, file_name ) ) == NULL )
	{
		return 0 ;
	}

	fputs( "word,count", p_write ) ;
	p_list->p_current = p_list->p_head ;
	while ( p_list->p_current != NULL )
	{
		fputc( '\n', p_write ) ; // push to new line at the beginning so 
		fputs( p_list->p_current->unique_word, p_write ) ; // word
		fputc( ',', p_write ) ; // word,
		int length = snprintf( NULL, 0, "%d", p_list->p_current->word_count ) ; // based on this comment https://stackoverflow.com/questions/8257714/how-can-i-convert-an-int-to-a-string-in-c#comment53469384_8257728
		char *p_count = malloc( sizeof(char) * length + 1 ) ; // makes a string of the exact right size for the number
		sprintf( p_count, "%d", p_list->p_current->word_count ) ; // puts word count integer into a string 
		fputs( p_count, p_write ) ; //word,count
		free( p_count ) ;
		p_list->p_current = p_list->p_current->p_next ;
	}
	
	p_list->p_current = p_list->p_tail ;
	fclose( p_write ) ;
	return 1 ;
	
}

