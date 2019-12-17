// Emily Smith
// 11233272
// ems032
/*
 * implementation code for is_legal_time_spec(), string_to_time_spec(),
 * and print_time_spec().
 */

/*
 * Header files
 */
#include <stdio.h>	// for puts(), fprintf(), sprintf(), and stderr
#include <inttypes.h> // for SCNu64, SCNu32, PRIu8, SCNu8
// local headers
#include "time_calc.h"	// for bool
#include "time_spec.h"	// for time_spec_t
#include <stdlib.h> // for malloc

bool is_time_spec(char * spec) {
	uint8_t year, month, day, hour, minute, second;

	char extra[2]; // buffer to store extra char after end of format string
	int num_scanned = sscanf(spec,  " %"SCNu8"y" " %"SCNu8"n" " %"SCNu8"d"
								"%"SCNu8 "h" " %"SCNu8"m" " %"SCNu8"s"
								" %s", &year, &month, &day, &hour, &minute,
								&second, extra);
	if (num_scanned < 6) {
		return FALSE;
	}
	if (num_scanned > 6) {
		return FALSE;
	}
	// dont need to check for 0 since unsigned is always positive
	if (!((year < 100) && (month < 12) && (day < 31) && (hour < 24) &&
		(minute < 60) && (second < 60))) {
		return FALSE;
	}
	return TRUE;
}


bool is_legal_time_spec( char * spec) {
	if (is_time_spec(spec)) { // check with helper function
		return TRUE;
	}
	fprintf(stderr, "error: time range exceeded, extraneous characters, or "
			"'%s' is not a valid time spec\n", spec);
	return FALSE;
}


time_spec_t * string_to_time_spec( char * string) {
	if (string == NULL) {
		return NULL;
	}
	time_spec_t *spec = NULL; // good to initialize pointers to NULL
	spec = (time_spec_t *)malloc( sizeof(time_spec_t) ); // pointing to some mem
								// of type struct point
	if (spec == NULL) {
		return NULL;
	}
	uint8_t year, month, day, hour, minute, second;
	sscanf(string,  " %"SCNu8"y" " %"SCNu8"n" " %"SCNu8"d" " %"SCNu8 "h"
					" %"SCNu8"m" " %"SCNu8"s",&year, &month, &day, &hour,
					&minute, &second);

	spec->year = year; // dereference it then get year
	spec->month = month;
	spec->day = day;
	spec->hour = hour;
	spec->minute = minute;
	spec->second = second;
	return spec;
}


void print_time_spec( time_spec_t *spec ) {
    printf( "%" PRIu8 "y", spec->year );
    printf( "%" PRIu8 "n", spec->month );
    printf( "%" PRIu8 "d", spec->day );
    printf( "%" PRIu8 "h", spec->hour );
    printf( "%" PRIu8 "m", spec->minute );
    printf( "%" PRIu8 "s\n", spec->second );
}
