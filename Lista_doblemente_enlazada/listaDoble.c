#include "listaDoble.h"

void
insertaInicio (struct listaDoble **lista, int dato)
{
  struct listaDoble *nuevo = NULL;
  nuevo = (struct listaDoble *) malloc (sizeof (struct listaDoble));
  if (nuevo == NULL)
    {
      return;
    }
  if (*lista == NULL)
    {
      *lista = nuevo;
      (*lista)->datos = dato;
      (*lista)->siguiente = NULL;
      (*lista)->anterior = NULL;
    }
  else
    {
      (*lista)->anterior = nuevo;
      nuevo->anterior = NULL;
      nuevo->siguiente = *lista;
      nuevo->datos = dato;
      *lista = nuevo;
    }
}

int
eliminarDato (struct listaDoble **lista, int dato)
{
  struct listaDoble *actual = *lista;
  struct listaDoble *ant = NULL;
  struct listaDoble *sig = NULL;
  if (lista == NULL)
    {
      return 0;
    }
  while (actual != NULL)
    {
      if (actual->datos == dato)
	{
	  if (actual == *lista)
	    {
	      *lista = actual->siguiente;
	      if (actual->siguiente != NULL)
		actual->siguiente->anterior == NULL;
	    }
	  else if (actual->siguiente == NULL)
	    {
	      ant = actual->anterior;
	      actual->anterior = NULL;
	      ant->siguiente = NULL;
	    }
	  else
	    {
	      ant = actual->anterior;
	      actual->anterior = NULL;
	      sig = actual->siguiente;
	      actual->siguiente = NULL;
	      ant->siguiente = sig;
	      sig->anterior = ant;
	    }
	  free (actual);
	  return 1;
	}
      actual = actual->siguiente;
    }
  return 0;
}


void
mostrar (struct listaDoble *lista)
{
  while (lista != NULL)
    {
      printf ("%d ,", lista->datos);
      lista = lista->siguiente;

    }
  printf ("\n");
}
