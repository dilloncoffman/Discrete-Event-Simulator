# Variable for compiler
CC = gcc
# Variable for compiler options
CFLAGS = -c -Wall -I.
# Variable for cleanup command
# to clean .o file
CLEANUP = rm -rf *o main.exe

# Entry point and exit point for call to "make".
# Compile executable.
all:
	gcc -o main.exe main.c Queues.c

# Remove object
clean:
	$(CLEANUP)