// Emily Smith

#ifndef SECONDS_H
#define SECONDS_H

#include <stdint.h>
#include "time_calc.h" // need for bool

typedef uint32_t num_seconds_t; 

#define SECONDS_IN_YEAR 31557600
#define SECONDS_IN_MONTH 2629800
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

#define LIMIT_SECONDS 3155760000


// helper function that has same functionality as is_legal_seconds,
// but gives no error output.
// In:
// Out:
//   return -- TRUE if string is a legal number of seconds
//          -- FALSE otherwise.
bool is_seconds(char* spec);

//   determine whether the string pointed to by in_str represents a legal
//   number of seconds; that is, it is a well-formed unsigned integer less
//   than LIMIT_SECONDS, and nothing else.  Output an error message on
//   stderr if it is not.
// In:
// Out:
//   return -- TRUE if string is a legal number of seconds
//          -- FALSE otherwise.  Also output error message on stderr.
bool is_legal_seconds( char *in_str );


//  the number of seconds specified by the string whose address is in
//  in_str is converted to a numeric value. The string is assumed to
//  contain a valid unsigned decimal number.
// In:
//   in_str != NULL, *in_str is a valid specification of seconds
// Out:
//   return -- number of seconds represented by string point to by in_str
num_seconds_t string_to_seconds( char *in_str );


#endif /* SECONDS_H_ */
