/*
 * Emily Smith
 * 11233272
 * ems032
 */

/*
 * Header files
 */
#include <stdio.h>	// for puts(), fprintf(), sprintf()
#include <inttypes.h> // for SCNu64, SCNu32, PRIu8, SCNu8
#include <string.h>	// for strcat() (did i used?), strcpy()
#include <stdlib.h> // for malloc // for EXIT_SUCCESS, EXIT_FAILURE

// local headers
# include"time_calc.h" // for bool
#include "time_spec.h" // need for functions
#include "seconds.h"	// need for functions and limit seconds
#include "time_arg.h"	// need for functions


void usage( void ) {
	puts( "Usage: time_calc help" );
	puts( " time_calc conv " );
	puts( " time_calc {add,subt,comp} " );
}


int main( int argc, char *argv[]) {
	num_seconds_t seconds;
	num_seconds_t time1;
	num_seconds_t time2;
	num_seconds_t result;

	if (argc >= 2) {
		if (strcmp(argv[1],"conv") == 0) { // 0 means equal
			// convert between a number of seconds and a time spec
			if (argc == 3) {
				// need to check if valid, then get and print the conversion!!
				if (get_time_arg(argv[2], &seconds) == 1) {
					if (is_seconds(argv[2])) {
						time_spec_t *time_spec = seconds_to_time_spec(seconds);
						print_time_spec(time_spec);
						free( time_spec );
						return( EXIT_SUCCESS );
					}
					else {
			            if( seconds < LIMIT_SECONDS ) {
			            	printf("%"SCNu32"\n", seconds);
			                return( EXIT_SUCCESS );
			            } else {
			                fprintf( stderr, "error: time range exceeded\n" );
			                return( EXIT_FAILURE );
			            }
					}
				}
			}
			else if (argc < 3) {
				fprintf(stderr, "error: too few arguments\n");
				usage();
				return( EXIT_FAILURE );
			}
			else {
				fprintf(stderr, "error: too many arguments\n");
				usage();
				return( EXIT_FAILURE );
			}

		}
		else if (argc == 4) {

			if (get_time_arg(argv[2], &seconds) == 1) { // check time1
				time1 = seconds;
				if (get_time_arg(argv[3], &seconds) == 1) { // check time2
					time2 = seconds;
				    // If we are processing an add command, add the numbers of seconds,
				    // check that our internal limit (for number of seconds) is not exceeded,
				    // convert to a time spec, print the time spec, and free the time spec.
					if (strcmp(argv[1],"add") == 0) {
						result = time1 + time2;
				        if( (result >= LIMIT_SECONDS) ||
				            (result < time1) ||        // arithmetic overflow
				            (result < time2) )         // arithmetic overflow
				        {
				            fprintf( stderr, "error: time range exceeded\n" );
				            return( EXIT_FAILURE );
				        }
						time_spec_t *time_spec = seconds_to_time_spec(result);
						print_time_spec(time_spec);
				        free( time_spec ); // why?
				        return( EXIT_SUCCESS );
					}
				    // If we are processing an subt command, check that doing the subtraction
				    // won't result in an underflow, subtract the second number of seconds
				    // from the first, convert the result to a time spec, print the time spec,
				    // and free the time spec.
					else if (strcmp(argv[1], "subt") == 0) {
				        if( time2 > time1 ) {
				            fprintf( stderr, "error: negative time not allowed\n" );
				            return( EXIT_FAILURE );
				        } else {
				            result = time1 - time2;
						time_spec_t *time_spec = seconds_to_time_spec(time1 - time2);
						print_time_spec(time_spec);
				        free( time_spec );
				        return( EXIT_SUCCESS );
				        }
					}
					else if (strcmp(argv[1],"comp") == 0) {
						if (time1 > time2) {
							printf("%s\n", "greater");
							return( EXIT_SUCCESS );
						}
						else if (time1 < time2) {
							printf("%s\n", "less");
							return( EXIT_SUCCESS );
						}
						else {
							printf("%s\n", "equal");
							return( EXIT_SUCCESS );
						}
					}
					else {
						fprintf(stderr, "error: command '%s' not recognized\n",
								argv[1]);
						usage();
						return( EXIT_FAILURE );
					}
				}
			}
		}
		else if (argc < 4) {
			if (strcmp(argv[1],"help") != 0) { // if first arg not "help"
				fprintf(stderr, "error: too few arguments\n");
			}
			usage();
			return( EXIT_FAILURE );
		}
		else {
			fprintf(stderr, "error: too many arguments\n");
			usage();
			return( EXIT_FAILURE );
		}
	}
    return( EXIT_FAILURE );
}
