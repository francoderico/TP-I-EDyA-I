main: main.c arbolops.o btree.o bstree.o glist.o operacion.o operadores.o pilas.o struct_operador.o tablaops.o
	$(CC) -Wall -Wextra -Werror -o $@ $^

arbolops.o: arbolops.c
	$(CC) -c $<

bstree.o: bstree.c
	$(CC) -c $<

btree.o: btree.c
	$(CC) -c $<

glist.o: glist.c
	$(CC) -c $<

operacion.o: operacion.c
	$(CC) -c $<

operadores.o: operadores.c
	$(CC) -c $<

pilas.o: pilas.c
	$(CC) -c $<

struct_operador.o: struct_operador.c
	$(CC) -c $<

tablaops.o: tablaops.c
	$(CC) -c $<

clean:
	-rm *.o

.PHONY = clean