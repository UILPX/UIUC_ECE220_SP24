CC=gcc
CFLAGS= -Wall -g -O0
LDFLAGS = -lpthread
DEPS = ll.h merge_sort.h

all: merge_sort_serial merge_sort_parallel

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

merge_sort_serial: merge_sort_serial.o merge_sort.o ll.o
	$(CC) -o $@ $^ $(CFLAGS)

merge_sort_parallel: merge_sort_parallel.o merge_sort.o ll.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f *.o merge_sort_serial merge_sort_parallel