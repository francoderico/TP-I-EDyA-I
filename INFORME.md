# TP-I-EDyA-I
Integrantes: De Rico, Franco.
             Osimi, Milagros.
             
Dificultades encontradas:
Elegir una estructura de datos para usar como auxiliar en la función armar_arbol_operaciones. Elegimos la pila ya que, al estar la expresión escrita en notación
postfija, un operador solo tendá de hijo al último (o los dos últimos) subárbol que se agregó a la estructura. Tambièn tuvimos algunos problemas con la gestión de la memoria.

Ejemplo de compilación:

gcc -c glist.c
gcc -c operacion.c
gcc -c operadores.c
gcc -c struct_operador.c
gcc -c tablaops.c
gcc -c arbolops.c
gcc -c bstree.c
gcc -c pilas.c
gcc -c btree.c
gcc -o main main.c arbolops.o tablaops.o bstree.o struct_operador.o operadores.o operacion.o glist.o pilas.o btree.o
./main



Algunos casos de prueba para main.c:

divcero = cargar 0 0 /
evaluar divcero
expr1 = cargar 25 25 + 6 *
imprimir expr1
impriimr divcero
salir


Nota: todos los archivos _test contienen casos de prueba.


Bibliografía consultada:
Estructuras de Datos con C - Tenenbaum, Langsam, Augenstein

