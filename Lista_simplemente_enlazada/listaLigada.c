#include<stdio.h>
#include<stdlib.h>
struct listaLigada
{
  int datos;
  struct listaLigada *siguiente;
};

void
insertaLista (struct listaLigada **lista, int dato)
{
  struct listaLigada *nuevo = NULL;
  nuevo = (struct listaLigada *) malloc (sizeof (struct listaLigada));
  if (nuevo == NULL)
    {
      return;
    }

  if (*lista == NULL)
    {
      *lista = nuevo;
      (*lista)->datos = dato;
      (*lista)->siguiente = NULL;
    }
  else
    {
	    nuevo->siguiente=*lista;
	    nuevo->datos = dato;
	    *lista = nuevo;
    }
}

void
mostrarLista (struct listaLigada *lista)
{
  struct listaLigada *actual = NULL;
  actual = lista;
  while (actual != NULL)
    {
      printf ("\n%d\n", actual->datos);
      actual = actual->siguiente;
    }
}

int
main ()
{
  struct listaLigada *lista = NULL;
  insertaLista (&lista, 2019);
  insertaLista (&lista, 2018);
  insertaLista (&lista, 2017);
  insertaLista (&lista, 2016);
  insertaLista (&lista, 2015);
  insertaLista (&lista, 2014);
  insertaLista (&lista, 2013);
  insertaLista (&lista, 2012);
  insertaLista (&lista, 2011);
  insertaLista (&lista, 2010);
  insertaLista (&lista, 2009);
  insertaLista (&lista, 2008);

  mostrarLista(lista);
  return 0;
}
