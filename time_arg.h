// Emily Smith
// 11233272
// ems032
/*
function prototypes and interface comments for seconds_to_time_spec(),
time_spec_to_seconds(), and get_time_arg(); symbols, constants, and types that
need to be known to code within time_arg.c; definition or declaration of any
other constants, symbols, names, types, or function prototypes related to the
content of time_arg.c that need to be known by other modules.
 */

#ifndef TIME_ARG_H
#define TIME_ARG_H

// local headers
#include "time_calc.h"	// for bool
#include "time_spec.h"	// for time_spec_t
#include "seconds.h"	// for num_seconds_t


// seconds_to_time_spec:
//  the number of seconds in seconds
//  is converted to corresponding numeric values, and these are
//  stored in a new, dynamically allocated time_spec_t data structure.
//  The value in seconds is known to contain a valid number of
//  seconds.  For example, it is known that the value is within limits.
// In:
//   seconds < LIMIT_SECONDS
// Out:
//   return -- on success, pointer to newly allocated time_spec_t structure
//             containing acquired fields
//          -- on failure, NULL
time_spec_t *seconds_to_time_spec( num_seconds_t seconds );

// time_spec_to_seconds:
//  the time spec specified by the string whose address is
//  passed as the argument to the function is converted to a single numeric
//  value, a number of seconds. The string is known to
//  contain a valid time spec.  For example, all field values
//  are within limits.
// In:
//   time_spec != NULL, *time_spec is a valid time spec
// Out:
//   return -- number of seconds represented by string point to by in_str
num_seconds_t time_spec_to_seconds( time_spec_t *time_spec );

// get_time_arg
//  Try to convert the string pointed to by in_str to a number of seconds.
//  If successful, store the number of seconds in the num_seconds_t location
//  pointed to by seconds_p.  Pointer in_str can point to a time spec or a
//  number of seconds.  The number of seconds is checked to make sure
//  it is less than LIMIT_SECONDS.  If in_str does not point to valid input,
//  or if the number of seconds is beyond the limit, print an appropriate
//  error message on stderr.  Note that the validity of in_str and the
//  string pointed to by in_str will be checked by functions such as
//  is_legal_time_spec() and is_legal_seconds.
// In:
// Out:
//   return -- TRUE if string is legal input and the number of seconds is
//             within bounds
//          -- FALSE otherwise.  Also output error message on stderr.
//   side effect -- on success, number of seconds stored in location
//     pointed to by seconds_p
bool get_time_arg( char *in_str, num_seconds_t *seconds_p);


#endif /* TIME_ARG_H_ */
