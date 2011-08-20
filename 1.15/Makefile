cc = gcc
ld = $(cc)
cflags = -g -Wall -Werror -std=c99
ldflags = -g

.PHONY : all clean

all : $(patsubst src/%.c,bin/%,$(wildcard src/*.c))

bin/% : bin/%.o
	$(ld) $(ldflags) $? -o $@

bin/%.o : src/%.c
	$(cc) $(cflags) -c $? -o $@

clean :
	rm -rf bin/*

