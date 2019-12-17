// Emily Smith
// 11233272
// ems032

#ifndef TIME_CALC_H
#define TIME_CALC_H

/*
 * Type definitions
 */
typedef unsigned char bool; // synonymous to unsigned char data type
// Use standard C values for TRUE and FALSE
#define TRUE  1
#define FALSE 0

// =====================================
// Functions

//   output usage message on stdout
// In:
// Out:
void usage( void );


//  Program entry point.
//  will process the command given as command-line arguments.
// In:
//  argc > 0
//  argv[0 .. argc-1] != NULL
// Out:
//  return -- EXIT_SUCCESS if program terminates normally,
//            EXIT_FAILURE otherwise
int main( int argc, char *argv[]);

#endif /* TIME_CALC_H_ */
