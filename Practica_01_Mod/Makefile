# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
DEPS = cell.h grid.h
OBJ = cell.o grid.o main.o

# *****************************************************
# Targets needed to bring the executable up to date

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $^

# The main.o target can be written more simply
main: $(OBJ)
	$(CC) ${CFLAGS} -o $@ $^
 
clean:
	rm *.o main