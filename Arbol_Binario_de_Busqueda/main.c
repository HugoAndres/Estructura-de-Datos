#include"Arbol_Binario_de_Busqueda.h"

int
main ()
{
  struct ABB *arbol = NULL;

  insertar (&arbol, 10);
  insertar (&arbol, 5);
  insertar (&arbol, 12);
  insertar (&arbol, 4);
  insertar (&arbol, 11);
  insertar (&arbol, 14);
  printf ("Arbol en InOrden: ");
  inOrden (arbol, Mostrar);
  printf ("\n");
  printf ("Arbol en PreOrden: ");
  preOrden (arbol, Mostrar);
  printf ("\n");
  printf ("Arbol en PostOrden: ");
  postOrden (arbol, Mostrar);

  return 0;
}
