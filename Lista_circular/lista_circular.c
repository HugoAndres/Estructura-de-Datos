#include<stdio.h>
#include<stdlib.h>

struct listaCircular
{
  int datos;
  struct listaCircular *siguiente;
};


void
insertar (struct listaCircular **lista, int dato)
{
  struct listaCircular *nuevo;
  nuevo = (struct listaCircular *) malloc (sizeof (struct listaCircular));
  nuevo->datos = dato;
  if (*lista == NULL)
    {

      *lista = nuevo;
    }
  else
    {

      nuevo->siguiente = (*lista)->siguiente;
    }

  (*lista)->siguiente = nuevo;
}

void
eliminar (struct listaCircular **lista, int dato)
{
  struct listaCircular *nuevo;
  nuevo = *lista;
  do
    {
      if ((*lista)->siguiente->datos != dato)
	{
	  *lista = ((*lista)->siguiente);
	};
    }
  while ((*lista)->siguiente->datos != dato && *lista != nuevo);
  if ((*lista)->siguiente->datos == dato)
    {
      if (*lista == (*lista)->siguiente)
	{
	  free (*lista);
	  *lista = NULL;
	}
      else
	{
	  nuevo = (*lista)->siguiente;
	  (*lista)->siguiente = nuevo->siguiente;
	  free (nuevo);
	}
    }
}

void
mostrar (struct listaCircular *lista)
{
  struct listaCircular *nuevo = lista;

  do
    {
      printf ("%d  ", nuevo->datos);
      nuevo = nuevo->siguiente;
    }
  while (nuevo != lista);
}

int
main ()
{
  struct listaCircular *lista = NULL;
  insertar (&lista, 4);
  insertar (&lista, 3);
  insertar (&lista, 10);
//  insertar (&lista, 9);
//  insertar (&lista, 20);
  mostrar (lista);
  printf ("\n-----------------------\n");
  eliminar (&lista, 3);
  mostrar (lista);
  return 0;
}
