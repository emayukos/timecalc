# Emily Smith
# makefile for time_calc project 

CFLAGS = -Wall -Wextra 

.PHONY: clean calculator

calculator: time_calc
 
CALC_OBJ = time_calc.o time_spec.o seconds.o time_arg.o

time_calc: $(CALC_OBJ)
	gcc $(CALC_OBJ) -o time_calc

time_calc.o: time_calc.c time_calc.h time_spec.h seconds.h time_arg.h
	gcc $(CFLAGS) -c time_calc.c

time_spec.o: time_spec.c time_spec.h time_calc.h
	gcc $(CFLAGS) -c time_spec.c

seconds.o: seconds.c seconds.h time_calc.h
	gcc $(CFLAGS) -c seconds.c

time_arg.o: time_arg.c time_arg.h time_calc.h time_spec.h seconds.h
	gcc $(CFLAGS) -c time_arg.c
	
clean: 
	rm -f *.o time_calc
	@echo "all cleaned up!"
