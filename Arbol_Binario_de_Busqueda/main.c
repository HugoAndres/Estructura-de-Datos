#include"Arbol_Binario_de_Busqueda.h"

int
main ()
{
  struct ABB *arbol = NULL;

  insertar (&arbol, 8);
  insertar (&arbol, 3);
  insertar (&arbol, 10);
  insertar (&arbol, 1);
  insertar (&arbol, 6);
  insertar (&arbol, 4);
  insertar (&arbol, 7);
  insertar (&arbol, 14);
  insertar (&arbol, 13);
  printf ("Arbol en InOrden: ");
  INORDEN (arbol);
  printf ("\n");
  printf ("Arbol en PreOrden: ");
  PREORDEN (arbol);
  printf ("\n");
  printf ("Arbol en PostOrden: ");
  POSTORDEN (arbol);
  printf ("\nBuscar elemento:\n");
  buscar (arbol, 5);
  buscar (arbol, 1);
  return 0;
}
