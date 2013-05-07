#######################################################
#
# Fichero: makefile
# Autor: Jose Miguel Colella
# Descripcion: Este fichero makefile automatiza el proceso de compilacion.
# Basicamente, ejecutando el comando make en el terminal, se crean los ficheros 
# ejecutables que dejan ver el comportamiento de las funciones creadas para las gestion de listas
#
######################################################

CXX = g++
SRC = src
OBJ = obj
LIB = lib
BIN = bin
INCLUDE = include
INCLUDE_DIR = -I./include
LIBRARYPATH = -L./lib
MODS_OBJ = $(OBJ)/basiclistio.o $(OBJ)/listoperations.o\
		   $(OBJ)/listsort.o $(OBJ)/advancedlistio.o\
		   $(OBJ)/mergelist.o
EXECUTABLES =  $(BIN)/Ejercicio1Main $(BIN)/Ejercicio2Main $(BIN)/Ejercicio3Main\
			   $(BIN)/Ejercicio4Main $(BIN)/Ejercicio5Main\
			   $(BIN)/Ejercicio6Main $(BIN)/Ejercicio7MainA $(BIN)/Ejercicio7MainB

.PHONY = clean

all: $(EXECUTABLES)

###################################################################
$(BIN)/Ejercicio1Main: $(OBJ)/Ejercicio1Main.o $(LIB)/liblist.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -llist

$(BIN)/Ejercicio2Main: $(OBJ)/Ejercicio2Main.o $(LIB)/liblist.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -llist
	
$(BIN)/Ejercicio3Main: $(OBJ)/Ejercicio3Main.o $(LIB)/liblist.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -llist

$(BIN)/Ejercicio4Main: $(OBJ)/Ejercicio4Main.o $(LIB)/liblist.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -llist

$(BIN)/Ejercicio5Main: $(OBJ)/Ejercicio5Main.o $(LIB)/liblist.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -llist 

$(BIN)/Ejercicio6Main: $(OBJ)/Ejercicio6Main.o $(LIB)/liblist.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -llist 

$(BIN)/Ejercicio7MainA: $(OBJ)/Ejercicio7MainA.o  $(OBJ)/dvectoroperations.o $(LIB)/liblist.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -llist 

$(BIN)/Ejercicio7MainB: $(OBJ)/Ejercicio7MainB.o  $(OBJ)/dvectoroperations.o $(LIB)/liblist.a
	$(CXX) -o $@ $^ $(LIBRARYPATH) -llist 

$(LIB)/liblist.a: $(MODS_OBJ)
		ar -crvs $@ $^

####################################################################

$(OBJ)/Ejercicio1Main.o: $(SRC)/Ejercicio1Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ $(LIBRARYPATH) -llist

$(OBJ)/Ejercicio2Main.o: $(SRC)/Ejercicio2Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ $(LIBRARYPATH) -llist

$(OBJ)/Ejercicio3Main.o: $(SRC)/Ejercicio3Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ $(LIBRARYPATH) -llist

$(OBJ)/Ejercicio4Main.o: $(SRC)/Ejercicio4Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ $(LIBRARYPATH) -llist

$(OBJ)/Ejercicio5Main.o: $(SRC)/Ejercicio5Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ $(LIBRARYPATH) -llist

$(OBJ)/Ejercicio6Main.o: $(SRC)/Ejercicio6Main.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ $(LIBRARYPATH) -llist

$(OBJ)/Ejercicio7MainA.o: $(SRC)/Ejercicio7MainA.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ $(LIBRARYPATH) -llist

$(OBJ)/Ejercicio7MainB.o: $(SRC)/Ejercicio7MainB.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ $(LIBRARYPATH) -llist
####################################################################
#Ficheros objetos para gestion de listas

$(OBJ)/basiclistio.o: $(SRC)/basiclistio.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@

$(OBJ)/listoperations.o: $(SRC)/listoperations.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ -lm

$(OBJ)/listsort.o: $(SRC)/listsort.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@

$(OBJ)/advancedlistio.o: $(SRC)/advancedlistio.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@

$(OBJ)/mergelist.o: $(SRC)/mergelist.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@

###################################################################
#Ficheros objetos para gestion de vector dinamico

$(OBJ)/dvectoroperations.o: $(SRC)/dvectoroperations.cpp
	$(CXX) -c $(INCLUDE_DIR) $< -o $@ $(LIBRARYPATH) -llist

##################################################################
clean:
	@echo Borrando Ficheros objetos, binarios, y bibliotecas
	rm $(OBJ)/*.o $(BIN)/* $(LIB)/*.a
