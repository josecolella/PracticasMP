bin/saludo: obj/saludo.o
	g++ obj/saludo.o -o bin/saludo
obj/saludo.o: src/saludo.cpp
	g++ -c src/saludo.cpp -o obj/saludo.o
