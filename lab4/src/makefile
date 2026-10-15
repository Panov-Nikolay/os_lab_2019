CC=gcc
CFLAGS=-I.

parallel_sum: utils.o sum.o
	$(CC) -o parallel_sum parallel_sum.c utils.o sum.o $(CFALGS)

process_memory : process_memory.c
	$(CC) -o process_memory process_memory.c $(CFLAGS)

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

sum.o : sum.h
	$(CC) -o sum.o -c sum.c $(CFLAGS)

clean :
	rm utils.o find_min_max.o parallel_min_max process_memory sum.o parallel_sum

all : parallel_min_max process_memory