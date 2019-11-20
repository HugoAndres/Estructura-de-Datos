#include "lista_circular.h"

int
main ()
{
  struct listaCircular *lista = NULL;
  insertar (&lista, 4);
  insertar (&lista, 3);
  insertar (&lista, 10);
  mostrar (lista);
  printf ("\n-----------------------\n");
return 0;
}
