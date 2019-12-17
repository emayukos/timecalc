// Emily Smith
// 11233272
// ems032
/*
 * time_spec.h
declarations of type time_spec_t and constants associated with that type;
function prototypes and interface comments for is_legal_time_spec(),
string_to_time_spec(), and print_time_spec(); symbols, constants, and types
that need to be known to code within time_spec.c; definition or declaration of
any other constants, symbols, names, types, or function prototypes related to
the content of time_spec.c that need to be known by other modules.
 */

#ifndef TIME_SPEC_H
#define TIME_SPEC_H

// local headers
#include "time_calc.h"	// for bool

/* a struct for holding a time spec. */
typedef struct { // don't really get how this works
// all of type unsigned char
uint8_t year;
uint8_t month;
uint8_t day;
uint8_t hour;
uint8_t minute;
uint8_t second;
} time_spec_t;



// =====================================
// Functions

// helper function that has same functionality as is_legal_time_spec,
// but gives no error output.
// In:
// Out:
//   return -- TRUE if string is a legal time spec
//          -- FALSE otherwise.
bool is_time_spec(char * spec);


//   determine whether the string pointed to by in_str represents a legal
//   "time spec"; that is, it is a string of the form
//      n1y n2n n3d n4h n5m n6s
//   where n1 < LIMT_TS_YE, n2 < LIMIT_TS_MO, n3 < LIMIT_TS_DA,
//   n4 < LIMIT_TS_HO, n5 < LIMIT_TS_MI, n6 < LIMIT_TS_SE and each
//   of the fields may or may not be surrounded by white space.
//   Output an error message on stderr if it is not.
// In:
// Out:
//   return -- TRUE if string is a legal time spec
//          -- FALSE otherwise.  Also output error message on stderr.
bool is_legal_time_spec( char * spec);


//  the time spec specified by the string whose address is in
//  in_str is converted to corresponding numeric values, and these are
//  stored in a new, dynamically allocated time_spec_t data structure.
//  The string is known to contain a valid time spec.  For example,
//  it is known that all the fields are within limits.
// In:
//   in_str != NULL, *in_str is a valid time spec
// Out:
//   return -- on success, pointer to newly allocated time_spec_t structure
//             containing acquired fields
//          -- on failure, NULL
time_spec_t *string_to_time_spec( char *in_str );


// print_time_spec
//   output a formatted representation of the time spec pointed to by
//   time_spec on the standard output, followed by a newline character.
//   There are to be no spaces between the fields of the time spec.
// In:
//   time_spec != NULL
// Out:
//   Character representation of time spec output to stdout.
//   Always returns as long as printf() returns.
void print_time_spec( time_spec_t *time_spec );

#endif /* TIME_SPEC_H_ */
