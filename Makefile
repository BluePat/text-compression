# Setting the compiler: gcc for C program
CC = gcc

# Setting compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -pedantic-errors

# Create main object file
main.o:
	$(CC) $(CFLAGS) src/main.c

command_line_args.o:
	$(CC) $(CFLAGS) src/command_line_args.c

program:
	$(CC) main.o command_line_args.o -o zipper

clean: 
	@echo "Cleaning up..."
	# $(RM) zipper
