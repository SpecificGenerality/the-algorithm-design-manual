gcc217 = gcc -Wall -pedantic
CFLAGS = -g

clean: 
	rm -r -f *.o

all: 3-1 3-2 

3-1: reader.o stack.o 3-1.o
	$(gcc217) $(CFLAGS) reader.o stack.o 3-1.o -o 3-1 
3-2: reader.o linkedlist.o 3-2.o
	$(gcc217) $(CFLAGS) linkedlist.o reader.o 3-2.o -o 3-2

reader.o: reader.h
stack.o: stack.h
linkedlist.o: linkedlist.h
3-1.o: stack.h reader.h
3-2.o: linkedlist.h reader.h