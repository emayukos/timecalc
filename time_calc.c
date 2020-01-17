/*
 * Emily Smith
 */

/*
 * Header files
 */
#include <stdio.h>	
#include <inttypes.h> 
#include <string.h>	
#include <stdlib.h> 

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
					if (strcmp(argv[1],"add") == 0) {
						result = time1 + time2;
				        if( (result >= LIMIT_SECONDS) ||
				            (result < time1) ||        
				            (result < time2) )         
				        {
				            fprintf( stderr, "error: time range exceeded\n" );
				            return( EXIT_FAILURE );
				        }
						time_spec_t *time_spec = seconds_to_time_spec(result);
						print_time_spec(time_spec);
				        free( time_spec ); // why?
				        return( EXIT_SUCCESS );
					}
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
