// Emily Smith
// 11233272
// ems032
/*
 * implementation code for is_legal_seconds() and string_to_seconds();
 */

/*
 * Header files
 */
#include <stdio.h>	// for stderr
#include <string.h>	// for strlen()
#include <stdlib.h> // for strtol(), atoi()
// local headers
#include "time_calc.h"	// for bool
#include "seconds.h"	// for num_seconds_t, LIMIT_SECONDS

bool is_seconds(char* spec) {
	num_seconds_t seconds; // need in case where we get seconds
	char *extra; // pointer to store extra characters from strtol
	// check if in seconds format first
	seconds = strtol(spec, &extra, 10);
	if (strlen(extra) == 0) {
		// check if fields exceed limit on number of seconds
		if (!(seconds < LIMIT_SECONDS)) {
			return FALSE;
		}
	}
	if (strlen(extra) > 0) {
		return FALSE;
	}
	return TRUE;
}

bool is_legal_seconds( char * spec) {
	if (is_seconds(spec)) { // check with helper function
		return TRUE;
	}
	fprintf(stderr, "error: number of seconds outside of valid range or "
			"extraneous character(s)\n");
	return FALSE;
}

num_seconds_t string_to_seconds( char * spec ) { 
	num_seconds_t seconds = atoi(spec);
	return seconds;
}
