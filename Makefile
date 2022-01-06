CC := gcc

ifeq ($(example),)
$(error No example specified. make example=path/to/example/file.c)
endif

all: example

example:
	$(CC) -lminitest -o bin/example $(example)