# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
DEPS = cell.h grid.h gridWithNoBorder.h gridWithOpenBorder.h gridWithPeriodicBorder.h
OBJ = cell.o grid.o gridWithNoBorder.o gridWithOpenBorder.o gridWithPeriodicBorder.o main.o

# *****************************************************
# Targets needed to bring the executable up to date

%.o: %.cpp $(DEPS)
	$(CC) -c -g -o $@ $^

# The main.o target can be written more simply
main: $(OBJ)
	$(CC) ${CFLAGS} -g -o $@ $^
 
clean:
	rm *.o main