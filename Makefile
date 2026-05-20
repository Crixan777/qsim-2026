CC=gcc

CFLAGS=-Wall -pthread

SRC=$(wildcard src/*.c)

OUT=qsim

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)