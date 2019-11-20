#include "listaDoble.h"

int
main (void)
{
  struct listaDoble *lista = NULL;
  insertaInicio (&lista, 0);
  insertaInicio (&lista, 1);
  insertaInicio (&lista, 2);
  insertaInicio (&lista, 3);
  mostrar (lista);
  printf ("-----------------------\n");
  eliminarDato (&lista, 1);
  eliminarDato (&lista, 3);
  mostrar(lista);
  printf("-----------------------\n");
  insertaInicio(&lista,2);
  mostrar (lista);
}
