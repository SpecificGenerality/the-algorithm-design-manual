gcc217 = gcc -Wall -pedantic
CFLAGS = -g

3-1: reader.o stack.o 3-1.o
	$(gcc217) $(CFLAGS) reader.o stack.o 3-1.o -o 3-1 
reader.o: reader.h
stack.o: stack.h
3-1.o: stack.h reader.h
