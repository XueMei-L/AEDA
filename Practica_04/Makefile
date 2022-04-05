CXX       := g++
CXX_FLAGS := #-Wall

BIN     := bin
SRC     := src
INCLUDE := include
LIBRARIES	:= $(INCLUDE)/*.h
EXECUTABLE  := main

all: $(BIN)/$(EXECUTABLE)

run:
		clear
		./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
		$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBRARIES)

clean:
		-rm $(BIN)/*