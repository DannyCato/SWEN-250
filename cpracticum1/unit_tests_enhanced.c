// unit_tests.c
// Larry Kiser November 1, 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "cpracticum.h"
#include "unit_tests.h"

// used by stdout switching functions
static int stdout_file_descriptor = 0 ;
static fpos_t stdout_position ;

// Redirect printf's to the specified text file (redirect stdout).
static void switch_stdout_to_file( char *filename )
{
	fflush( stdout ) ;
	fgetpos( stdout, &stdout_position ) ;
	stdout_file_descriptor = dup( fileno( stdout ) ) ;
	freopen( filename, "w", stdout ) ;
}

// Restore normal printf behavior (restore stdout).
// MUST be called only after a prior call to switch_stdout_to_file!
static void restore_stdout( void )
{
	if ( stdout_file_descriptor )
	{
		fflush( stdout ) ;
		dup2( stdout_file_descriptor, fileno( stdout ) ) ;
		close( stdout_file_descriptor ) ;
		clearerr( stdout ) ;
		fsetpos( stdout, &stdout_position ) ;
	}
}

// Simple boolean assert function for unit testing
int assert( int test_result, char error_format[], ... ) {
	va_list arguments ;
	static int test_number = 1 ;
	int result = 1 ;	// return 1 for test passed or 0 if failed
	// bogus code that does nothing except avoid compiler warning on these two unused functions.
	#pragma GCC diagnostic ignored "-Waddress"
	if ( switch_stdout_to_file && restore_stdout ) ;
	#pragma GCC diagnostic warning "-Waddress"
	
	if ( ! test_result ) {
		va_start( arguments, error_format ) ;
		printf( "Test # %d failed: ", test_number ) ;
		vprintf( error_format, arguments ) ;
		printf( "\n" ) ;
		result = 0 ;
	}
	test_number++ ;
	return result ;
}

//////////////////////////////////////////////////////////////////////////
// Begin unit tests //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// do the unit tests
int test()
{
	int passcount = 0 ;
	int failcount = 0 ;
	int result ;
	int numbers1[] = { 5, 10, 15, 20, 25 } ;
	mydata data ;
	
	// Test 1 -- 
	assert( ( result = string_is_sorted( "" ) ) == 1,
		"Empty string must report 1 for sorted. Got %d", result )
		? passcount++ : failcount++ ;
		
	// Test 2 -- 
	assert( ( result = string_is_sorted( "x" ) ) == 1,
		"Single character string must report 1 for sorted. Got %d", result )
		? passcount++ : failcount++ ;
		
	// Test 3 -- 
	assert( ( result = string_is_sorted( "abcdef" ) ) == 1,
		"Expected sorted for string abcdef. Got %d", result )
		? passcount++ : failcount++ ;
		
	// Test 4 -- 
	assert( ( result = string_is_sorted( "abcdee" ) ) == 1,
		"Expected sorted for string abcdee. Got %d", result )
		? passcount++ : failcount++ ;
		
	// Test 5 -- 
	assert( ( result = string_is_sorted( "abcdeed" ) ) == 0,
		"Expected unsorted for string abcdeed. Got %d", result )
		? passcount++ : failcount++ ;
		
	// Test 6 -- 
	assert( ( result = string_is_sorted( "cbc" ) ) == 0,
		"Expected unsorted for string cbc. Got %d", result )
		? passcount++ : failcount++ ;
		
	// Test 7 -- 
	assert( ( result = fix_bad_code( numbers1, 2 ) ) == 15,
		"Expected 15 for sum of first two. Got %d", result )
		? passcount++ : failcount++ ;
		
	// Test 8 -- 
	assert( ( result = fix_bad_code( numbers1, 5 ) ) == 75,
		"Expected 75 for sum of first five. Got %d", result )
		? passcount++ : failcount++ ;
		
	// Test 9 -- 
	data = get_string_info( "" ) ;
	assert( data.lowest_upper_case_letter == '\0',
		"Expected 0 for lowest upper case letter for an empty string but got 0x%x", (int)data.lowest_upper_case_letter )
		? passcount++ : failcount++ ;
		
	// Test 10 -- 
	assert( data.upper_case_count == 0,
		"Expected 0 for upper case count for an empty string but got %d", data.upper_case_count )
		? passcount++ : failcount++ ;
	
	// Test 11 --
	data = get_string_info( "ZXY55T" ) ;
	assert( data.lowest_upper_case_letter == 'T',
		"Expected T for lowest upper case letter but got %c", data.lowest_upper_case_letter )
		? passcount++ : failcount++ ;
		
	// Test 12 --
	assert( data.upper_case_count == 4,
		"Expected 4 for upper case count but got %d", data.upper_case_count )
		? passcount++ : failcount++ ;
		
	// Test 13 --
	data = get_string_info( "AABB----" ) ;
	assert( data.lowest_upper_case_letter == 'A',
		"Expected A for lowest upper case letter but got %c", data.lowest_upper_case_letter )
		? passcount++ : failcount++ ;
		
	// Test 14 --
	assert( data.upper_case_count == 4,
		"Expected 4 for upper case count but got %d", data.upper_case_count )
		? passcount++ : failcount++ ;
	
	// additional post exam unit tests
	// Test 15 -- variation on 6 -- 
	assert( ( result = string_is_sorted( "ABCDDC" ) ) == 0,
		"Expected unsorted for string ABCDDC. Compare to Test 6. Got %d", result )
		? passcount++ : failcount++ ;

	// Test 16 like Test 11 but only upper case letters --
	data = get_string_info( "CBA" ) ;
	assert( data.lowest_upper_case_letter == 'A',
		"Expected A for lowest upper case letter but got %c", data.lowest_upper_case_letter )
		? passcount++ : failcount++ ;

	// Test 17 like Test 12 but only upper case letters --
	assert( data.upper_case_count == 3,
		"Expected 3 for upper case count but got %d", data.upper_case_count )
		? passcount++ : failcount++ ;

	printf( "\nSummary of unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;

	
	return failcount ;
}