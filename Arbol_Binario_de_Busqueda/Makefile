Arbol_Binario_de_Busqueda.o: Arbol_Binario_de_Busqueda.c
	gcc Arbol_Binario_de_Busqueda.c -c
main.o: main.c
	gcc main.c -c
a.out: main.o Arbol_Binario_de_Busqueda.o
	gcc main.o Arbol_Binario_de_Busqueda.o
run: a.out
	./a.out
clean:
	rm -f a.out main.o Arbol_Binario_de_Busqueda.o
