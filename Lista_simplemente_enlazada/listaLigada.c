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
      nuevo->siguiente = *lista;
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
  return;
}

int
eliminarDato (struct listaLigada **lista, int dato)
{
  struct listaLigada *aux;
  struct listaLigada *ant;
  struct listaLigada *act;
  if (*lista == NULL)
    {
      return 0;
    }
  if (dato == (*lista)->datos)
    {
      aux = *lista;
      *lista = (*lista)->siguiente;
      free (aux);
      return dato;
    }
  else
    {
      ant = *lista;
      act = (*lista)->siguiente;
      while (act != NULL && act->datos != dato)
	{
	  ant = act;
	  act = act->siguiente;
	}
      if (act != NULL)
	{
	  aux = act;
	  ant->siguiente = act->siguiente;
	  free (aux);
	  return dato;
	}

    }
  return '\0';
}

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
