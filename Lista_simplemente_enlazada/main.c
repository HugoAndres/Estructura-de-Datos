#include "listaLigada.h"

int
main ()
{
  struct listaLigada *lista = NULL;

  insertaLista (&lista, 2013);
  insertaLista (&lista, 2012);
  insertaLista (&lista, 2011);
  insertaLista (&lista, 2010);
  insertaLista (&lista, 2009);
  insertaLista (&lista, 2008);

  mostrarLista (lista);
  printf ("-------------------------------------");


  eliminarDato (&lista, 2008);
  eliminarDato (&lista, 2010);
  eliminarDato (&lista, 2012);
  eliminarDato (&lista, 2013);
  mostrarLista (lista);


  return 0;
}
