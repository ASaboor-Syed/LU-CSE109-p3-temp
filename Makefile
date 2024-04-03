CC=gcc
CFLAGS=-g -c -Wall -Wextra -Wwrite-strings
LFLAGS=-g

prog: cIncludes.o syscalls.o cIncludesFuncs.o
	make clean
	make cIncludes
cIncludes: cIncludes.o syscalls.o cIncludesFuncs.o
	${CC} ${LFLAGS} -o cIncludes cIncludes.o syscalls.o cIncludesFuncs.o
cIncludes.o: cIncludes.c
	${CC} ${CFLAGS} cIncludes.c
syscalls.o: syscalls.c
	${CC} ${CFLAGS} syscalls.c
cIncludesFuncs.o: cIncludesFuncs.c
	${CC} ${CFLAGS} cIncludesFuncs.c
clean:
	rm -f *.o
	rm -f cIncludes
	rm -f *.out