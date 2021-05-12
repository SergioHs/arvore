# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -O3

default: main

arvore.o: arvore.c arvore_interface.h arvore_privado.h
	$(CC) $(CFLAGS) -c arvore.c -o arvore.o

main: main.c arvore.o
	$(CC) $(CFLAGS) main.c arvore.o -o main

clean:
	rm -f main *.o core a.out *.*~ Makefile~

all: main