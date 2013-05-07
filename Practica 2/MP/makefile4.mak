# Fichero: makefil3.mak 
# Construye el ejecutable "saludo" a partir de "saludo.cpp" 
# Tambien puede construirse el objeto "saludo.o" a partir de "saludo.cpp"

bin/saludo : src/saludo.cpp
	@echo Creando saludo...
	g++ src/saludo.cpp -o bin/saludo

# Esta regla especifica un destino que no es un fichero ejecutable.

obj/saludo.o : src/saludo.cpp
	@echo Creando saludo.o solamente...
	g++ -c src/saludo.cpp -o obj/saludo.o 
                
clean:
	@echo Borrando ficheros objeto
	rm obj/*.o 
