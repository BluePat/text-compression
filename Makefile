# the compiler: gcc for C program
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

program: src/main.c
	$(CC) $(CFLAGS) -o program src/main.c

clean: 
	$(RM) program