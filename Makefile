kontest_TARGET = ./kontest
 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -O2 -g

CLEAN = rm *.o
 
.PHONY: default all clean
 
default: $(kontest_TARGET)
all: default
 
kontest_OBJECTS = $(patsubst %.c, %.o, matriz.c main.c)
kontest_HEADERS = $(matriz.h)
   
%.o: %.c $(matriz_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
     
.PRECIOUS: $(kontest_TARGET) $(kontest_TARGET)
     
$(kontest_TARGET): $(kontest_OBJECTS)
	$(CC) $(kontest_OBJECTS) -o $@
     
clean:
	$(CLEAN)
