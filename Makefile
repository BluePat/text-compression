# Setting the compiler: gcc for C program
CC = gcc

# Setting compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -pedantic-errors

# Create main object file
main.o:
	$(CC) $(CFLAGS) src/main.c

program:
	$(CC) main.o logger.o -o zipper

clean: 
	@echo "Cleaning up..."
	$(RM) zipper
