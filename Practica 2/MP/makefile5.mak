# Fichero: makefil3.mak 
# Construye el ejecutable "saludo" a partir de "saludo.cpp" 
# Tambien puede construirse el objeto "saludo.o" a partir de "saludo.cpp"

SRC = src
BIN = bin
OBJ = obj
INCLUDE = include
LIB = lib

.PHONY : clean

todo: $(BIN)/saludo $(BIN)/unico clean salva

$(BIN)/unico: $(SRC)/unico.cpp
	@echo Creando unico...
	g++ $(SRC)/unico.cpp -o $(BIN)/unico

$(BIN)/saludo : $(SRC)/saludo.cpp
	@echo Creando saludo...
	g++ $(SRC)/saludo.cpp -o $(BIN)/saludo

# Esta regla especifica un destino que no es un fichero ejecutable.

$(OBJ)/saludo.o : $(SRC)/saludo.cpp
	@echo Creando saludo.o solamente...
	g++ -c $(SRC)/saludo.cpp -o $(OBJ)/saludo.o 
                
clean:
	@echo Borrando ficheros objeto
	rm $(OBJ)/*.o 

salva: $(BIN)/saludo $(BIN)/unico
	echo @Creando directorio resultado
	mkdir resultado
	echo @Moviendo los ejecutables al directorio resultado
	mv $^ resultado	
