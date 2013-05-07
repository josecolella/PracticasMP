##########################################
# 
# Fichero: makefile
# Autor: Jose Miguel Colella
# Descripcion: Este fichero makefile describe los ejecutables
# que saldran para verificar la validez de las funciones
# Basicamente tenemos des ficheros ejecutables: Ejercicio8Main y Ejercicio9Main
# El Ejercicio8Main verifica la validez de las funciones creadas para Matriz2D_1,
# mientras que Ejercicio9Main verifica la validez de las funciones creadas para Matriz2D_2
##########################################


CXX = g++
SRC = src
OBJ = obj
LIB = lib
BIN = bin
INCLUDE = include
INCLUDE_DIR = -I./include
LIBRARYPATH = -L./lib
MODS_OBJ = $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o 
EXECUTABLES = $(BIN)/Ejercicio8Main $(BIN)/Ejercicio9Main

.PHONY = clean

all: $(EXECUTABLES) 

########################################################3
$(BIN)/Ejercicio8Main: $(OBJ)/Ejercicio8Main.o $(LIB)/libmatrix.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -lmatrix

$(BIN)/Ejercicio9Main: $(OBJ)/Ejercicio9Main.o $(LIB)/libmatrix.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -lmatrix

$(LIB)/libmatrix.a: $(MODS_OBJ)
	ar -crvs $@ $^

###############################################################
$(OBJ)/Ejercicio8Main.o: $(SRC)/Ejercicio8Main.cpp 
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ $(LIBRARYPATH) -lmatrix

$(OBJ)/Ejercicio9Main.o: $(SRC)/Ejercicio9Main.cpp 
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ $(LIBRARYPATH) -lmatrix

$(OBJ)/Matriz2D_1.o: $(SRC)/Matriz2D_1.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ 

$(OBJ)/Matriz2D_2.o: $(SRC)/Matriz2D_2.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

###############################################################
clean:
	rm $(OBJ)/*.o $(BIN)/* $(LIB)/*



