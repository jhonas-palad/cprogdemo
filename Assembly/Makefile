CC = gcc
CFLAGS = -g -Wall -Werror
BINS = build_main

all: $(BINS)

build_%: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.s: %.c
	$(CC) -S $< -o $@
clean:
	rm -f *.out *.o main build_*