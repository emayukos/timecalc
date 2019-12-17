// Emily Smith
// 11233272
// ems032
/*
implementation code for seconds_to_time_spec(), time_spec_to_seconds(), and
get_time_arg().
 */

/*
 * Header files
 */
#include <stdio.h>	// for NULL
#include <stdlib.h> // for malloc
#include <inttypes.h> // for SCNu64, SCNu32, PRIu8, SCNu8
// local headers
#include "time_calc.h"	// for bool
#include "time_spec.h" // for functions and time_spec_t
#include "seconds.h"	// for functions, seconds constants and num_seconds_t


time_spec_t * seconds_to_time_spec( num_seconds_t seconds ) {
	if (!(seconds < 3155760000)) {
		return NULL;
	}
	time_spec_t *spec = NULL; // good to initialize pointers to NULL
	spec = (time_spec_t *)malloc( sizeof(time_spec_t) );
	if (spec == NULL) {
		return NULL;
	}
	// check if amount of seconds is greater than a year
	if (seconds/(uint32_t)SECONDS_IN_YEAR >= 1){ // floor division
		spec->year = seconds / (uint32_t)SECONDS_IN_YEAR;
		seconds = seconds % (uint32_t)SECONDS_IN_YEAR;
	}
	// check count for months
	if (seconds/(uint32_t)SECONDS_IN_MONTH >= 1){
		spec->month = seconds / (uint32_t)SECONDS_IN_MONTH;
		seconds = seconds % (uint32_t)SECONDS_IN_MONTH;
	}
	if (seconds/(uint32_t)SECONDS_IN_DAY >= 1){
		spec->day = seconds / (uint32_t)SECONDS_IN_DAY;
		seconds = seconds % (uint32_t)SECONDS_IN_DAY;
	}
	if (seconds/(uint32_t)SECONDS_IN_HOUR >= 1){
		spec->hour = seconds / (uint32_t)SECONDS_IN_HOUR;
		seconds = seconds % (uint32_t)SECONDS_IN_HOUR;
	}
	if (seconds/(uint32_t)SECONDS_IN_MINUTE >= 1){
		spec->minute = seconds / (uint32_t)SECONDS_IN_MINUTE;
		seconds = seconds % (uint32_t)SECONDS_IN_MINUTE;
	}
	spec->second = seconds; // whatever's left over

	return spec;
	}


num_seconds_t time_spec_to_seconds(time_spec_t *time_spec) {
	num_seconds_t seconds = time_spec->year*(uint32_t)SECONDS_IN_YEAR
						+ time_spec->month*(uint32_t)SECONDS_IN_MONTH
						+ time_spec->day*(uint32_t)SECONDS_IN_DAY
						+ time_spec->hour*(uint32_t)SECONDS_IN_HOUR
						+ time_spec->minute*(uint32_t)SECONDS_IN_MINUTE
						+ time_spec->second;
	return seconds;
}


bool get_time_arg( char *in_str, num_seconds_t *seconds_p ) {
	if (is_seconds(in_str)) {
		*seconds_p = string_to_seconds(in_str);
		return TRUE;
		}
	if (is_time_spec(in_str)) {
		*seconds_p = time_spec_to_seconds(string_to_time_spec(in_str));
		return TRUE;
	}
	is_legal_seconds(in_str);
	is_legal_time_spec(in_str);
	return FALSE;
}
