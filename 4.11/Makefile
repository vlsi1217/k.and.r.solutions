CC = gcc
CFLAGS = -g -Wall -Werror -std=c99 -I./src
LD = $(CC)
LDFLAGS = -g -lm
MAIN = bin/4.11
LIBOBJECTS = \
	src/stack.o \
	src/calculator.o \
	src/main.o

.PHONY : clean

$(MAIN) : $(LIBOBJECTS)
	$(LD) $(LDFLAGS) $? -o $@

clean :
	rm -f src/*.o $(MAIN)

