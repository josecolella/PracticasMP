INCLUDE = include
BIN = bin
LIB = lib
SRC = src
OBJ = obj
MOVE = -I./include
.PHONY = clean

all: $(BIN)/ppal_1 

$(BIN)/ppal_1: $(OBJ)/ppal_1.o $(OBJ)/opers.o
	g++ $^ -o $@ 


$(OBJ)/ppal_1.o: $(SRC)/ppal_1.cpp 
	g++ -c $(MOVE) $^ -o $@


$(OBJ)/opers.o: $(SRC)/opers.cpp
	g++ -c -I./include $^ -o $@


clean: 
	rm $(OBJ)/* $(BIN)/*