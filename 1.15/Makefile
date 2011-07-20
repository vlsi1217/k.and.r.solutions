cc = gcc
ld = $(cc)
cflags = -g -Wall -std=c99

.PHONY : all clean

all : bin/1.15

bin/% : bin/%.o
	$(ld) -g $? -o $@

bin/%.o : src/%.c
	$(cc) $(cflags) -c $? -o $@

clean :
	rm -rf bin/*

