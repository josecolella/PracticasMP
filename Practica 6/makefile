########################################33
#
# Fichero: makefile
# Autor: Jose Miguel Colella
# Descripcion: Este fichero makefile facilita
# el proceso de compilacion para que se generen dos
# ejecutables: Ejercicio9Main y Ejercicio10Main.
# El Ejercicio9Main comprueba la parte b y c del ejercicio 9.
# Mientras el Ejercicio10Main comprueba los modulos creados para
# los poligonos
#
#########################################

CXX = g++
SRC = src
OBJ = obj
LIB = lib
BIN = bin
INCLUDE = include
INCLUDE_DIR = -I./include
LIBRARYPATH = -L./lib
MODS_OBJ_MATRIX = $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o $(OBJ)/matriz2D_Xoperations.o
MODS_OBJ_POLYGON = $(OBJ)/polygonoperations.o
EXECUTABLES = $(BIN)/Ejercicio9Main $(BIN)/Ejercicio10Main

.PHONY = clean

all: $(EXECUTABLES) 


$(BIN)/Ejercicio9Main: $(OBJ)/Ejercicio9Main.o $(LIB)/libmatrix.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -lmatrix

$(BIN)/Ejercicio10Main: $(OBJ)/Ejercicio10Main.o $(LIB)/libpolygons.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -lpolygons -lm


###############################################################

$(OBJ)/Ejercicio9Main.o: $(SRC)/Ejercicio9Main.cpp 
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ $(LIBRARYPATH) -lmatrix

$(OBJ)/Ejercicio10Main.o: $(SRC)/Ejercicio10Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ $(LIBRARYPATH) -lpolygons

################################################################

$(LIB)/libmatrix.a: $(MODS_OBJ_MATRIX)
	ar -crvs $@ $^

$(LIB)/libpolygons.a: $(MODS_OBJ_POLYGON)
	ar -crvs $@ $^

##############################################################
$(OBJ)/Matriz2D_1.o: $(SRC)/Matriz2D_1.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ 

$(OBJ)/Matriz2D_2.o: $(SRC)/Matriz2D_2.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

$(OBJ)/matriz2D_Xoperations.o: $(SRC)/matriz2D_Xoperations.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

###############################################################

$(OBJ)/polygonoperations.o: $(SRC)/polygonoperations.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

##############################################################

clean:
	rm $(OBJ)/*.o $(BIN)/* $(LIB)/*
