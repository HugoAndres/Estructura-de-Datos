lista_circular.o: lista_circular.c 
	gcc lista_circular.c -c 
main.o: main.c 
	gcc main.c -c 
a.out: main.o lista_circular.o 
	gcc main.o lista_circular.o 
run: a.out
	./a.out 
clean:
	rm -f a.out main.o lista_circular.o
