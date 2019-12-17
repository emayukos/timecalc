# timecalc
Emily Smith
Dec 2018
(University of Saskatchewan CMPT 214 assignment 4)


time_calc project (reference manual)
========

is executed as a command from the LINUX/UNIX command line, and can perform different commands related to time measured in seconds or in a formatted time specification.


Features
--------

time_calc can perform five commands based on a "command keyword" given as the first argument:

- convert between a number of seconds and a time spec (conv command);

- add two time values and output the result as a time spec (add command);

- subtract two time values (i.e. time1 − time2) and output the result as a time spec (subt command); and

- compare two time values and output a result string (comp command).

- issue a help or usage message (help command).


to get started
------------

type "make calculator" into your terminal to create the time_calc executable


usage pattern
-------------

./time_calc conv time 
./time_calc {add,subt,comp} time1 time2

where each of time, time1, and time2 is a "time value", so either a number of seconds (an unsigned integer) less than 3155760000, or a string time specification of the form
n1y n2n n3d n4h n5m n6s


possible commands
--------

time_calc conv <time>	
time_calc add <time1> <time2>
time_calc subt <time1> <time2>
time_calc comp <time1> <time2>	 
note that this produces "greater" if time1 > time2, "equal" if time1 = time2, and "less" if time1 < time2

for each command, output on successful operation is produced on the stdout.
