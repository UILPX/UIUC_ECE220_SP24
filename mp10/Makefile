CC=gcc
CFLAGS=-g -std=c99 -Wall -Werror

all: mp10

mp10: main.o sparsemat.o
	$(CC) $(CFLAGS) main.o sparsemat.o cmp_mat.o -o mp10

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sparsemat.o: sparsemat.c
	$(CC) $(CFLAGS) -c sparsemat.c

clean:
	rm -f sparsemat.o main.o mp10
