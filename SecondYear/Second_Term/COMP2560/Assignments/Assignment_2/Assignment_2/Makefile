CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -D_POSIX_C_SOURCE=200809L
LDLIBS = -lrt

.PHONY: all clean

all: detector logger

detector: detector.c alert.h
	$(CC) $(CFLAGS) -o $@ detector.c $(LDLIBS)

logger: logger.c alert.h
	$(CC) $(CFLAGS) -o $@ logger.c $(LDLIBS)

clean:
	rm -f detector logger alerts.bin
