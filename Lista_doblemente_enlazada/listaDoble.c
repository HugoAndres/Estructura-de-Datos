#include<stdio.h>
#include<stdlib.h>

struct listaDoble
{
  int datos;
  struct listaDoble *siguiente;
  struct listaDoble *anterior;
};
struct listaDoble *
insertaLista (struct listaDoble *lista, int dato)
{
  struct listaDoble *nuevo = NULL;
  nuevo = (struct listaDoble *) malloc (sizeof (struct listaDoble));
  if (nuevo == NULL)
    {
      return NULL;
    }

  nuevo->datos = dato;
  nuevo->siguiente = lista;
  nuevo->anterior = NULL;
  if (lista == NULL)
    {
      return nuevo;
    }
  lista->anterior = nuevo;

  return nuevo;
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

int
main (void)
{
  struct listaDoble *lista = NULL;


  lista = insertaLista (lista, 0);
  lista = insertaLista (lista, 1);
  lista = insertaLista (lista, 2);
  lista = insertaLista (lista, 3);
  lista = insertaLista (lista, 4);
  mostrar (lista);
}
