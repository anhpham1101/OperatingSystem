all: main.o ex1.o
	gcc main.o ex1.o -o main
ex1.o: ex1.c ex1.h
	gcc -c ex1.c
main.o: main.c
	gcc -c main.c
clean: 
	rm -f *.o ex1