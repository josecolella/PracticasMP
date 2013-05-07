###########################################
#
# Fichero: makefile
# Autor: Jose Miguel Colella
# Descripcion: Ejecutando este makefile, se crean 7 ejecutables
# que pertenecen a los ejercicios de la practica 8
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
MOD_OBJ = $(OBJ)/VectorDinamico.o $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o $(OBJ)/Node.o $(OBJ)/Lista.o $(OBJ)/Stack.o $(OBJ)/Queue.o $(OBJ)/Conjunto.o

EXECUTABLES = $(BIN)/Ejercicio1Main $(BIN)/Ejercicio2Main\
			  $(BIN)/Ejercicio3Main $(BIN)/Ejercicio4Main\
			  $(BIN)/Ejercicio5Main $(BIN)/Ejercicio6Main\
			  $(BIN)/Ejercicio7Main 

.PHONY = clean

all: $(EXECUTABLES) 

###########################################################################

$(BIN)/Ejercicio1Main: $(OBJ)/Ejercicio1Main.o $(LIB)/libdatastructures.a
	$(CXX) $^ -o $@ $(LIBRARYPATH) -ldatastructures

$(BIN)/Ejercicio2Main: $(OBJ)/Ejercicio2Main.o $(LIB)/libdatastructures.a
	$(CXX) $^ -o $@ $(LIBRARYPATH) -ldatastructures

$(BIN)/Ejercicio3Main: $(OBJ)/Ejercicio3Main.o $(LIB)/libdatastructures.a
	$(CXX) $^ -o $@ $(LIBRARYPATH) -ldatastructures
	
$(BIN)/Ejercicio4Main: $(OBJ)/Ejercicio4Main.o $(LIB)/libdatastructures.a
	$(CXX) $^ -o $@ $(LIBRARYPATH) -ldatastructures
	
$(BIN)/Ejercicio5Main: $(OBJ)/Ejercicio5Main.o $(LIB)/libdatastructures.a
	$(CXX) $^ -o $@ $(LIBRARYPATH) -ldatastructures
	
$(BIN)/Ejercicio6Main: $(OBJ)/Ejercicio6Main.o $(LIB)/libdatastructures.a
	$(CXX) $^ -o $@ $(LIBRARYPATH) -ldatastructures

$(BIN)/Ejercicio7Main: $(OBJ)/Ejercicio7Main.o $(LIB)/libdatastructures.a
	$(CXX) $^ -o $@ $(LIBRARYPATH) -ldatastructures
	
########################################################

$(LIB)/libdatastructures.a: $(MOD_OBJ)
	ar -crvs $@ $^ 

########################################################

$(OBJ)/Ejercicio1Main.o: $(SRC)/Ejercicio1Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ 

$(OBJ)/Ejercicio2Main.o: $(SRC)/Ejercicio2Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ 

$(OBJ)/Ejercicio3Main.o: $(SRC)/Ejercicio3Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ 

$(OBJ)/Ejercicio4Main.o: $(SRC)/Ejercicio4Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ 

$(OBJ)/Ejercicio5Main.o: $(SRC)/Ejercicio5Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ 

$(OBJ)/Ejercicio6Main.o: $(SRC)/Ejercicio6Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ 

$(OBJ)/Ejercicio7Main.o: $(SRC)/Ejercicio7Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@ 

########################################################

$(OBJ)/VectorDinamico.o: $(SRC)/VectorDinamico.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

$(OBJ)/Matriz2D_1.o: $(SRC)/Matriz2D_1.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

$(OBJ)/Matriz2D_2.o: $(SRC)/Matriz2D_2.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

$(OBJ)/Lista.o: $(SRC)/Lista.cpp 
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

$(OBJ)/Node.o: $(SRC)/Node.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

$(OBJ)/Stack.o: $(SRC)/Stack.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@
	
$(OBJ)/Queue.o: $(SRC)/Queue.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@

$(OBJ)/Conjunto.o: $(SRC)/Conjunto.cpp
	$(CXX) -c $(INCLUDE_DIR) $^ -o $@


#######################################

clean:
	rm $(OBJ)/*.o $(BIN)/* $(LIB)/*.a
