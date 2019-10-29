#include<stdio.h>
#include<stdlib.h>

struct listaDoble
{
  int datos;
  struct listaDoble *siguiente;
  struct listaDoble *anterior;
};
struct listaDoble *
insertar (struct listaDoble *lista, int dato)
{
  struct listaDoble *nuevonodo =
    (struct listaDoble *) malloc (sizeof (struct listaDoble));
  if (nuevonodo == NULL)
    {
      return NULL;
    }

  nuevonodo->datos = dato;
  nuevonodo->siguiente = lista;
  nuevonodo->anterior = NULL;
  if (lista == NULL)
    {
      return nuevonodo;
    }
  lista->anterior = nuevonodo;
  return nuevonodo;
}

void
mostrar (struct listaDoble *lista)
{
  while (lista != NULL)
    {
      printf ("%d", lista->siguiente);
      lista = lista->siguiente;

    }
  printf ("\n");
}

int
main (void)
{
  struct listaDOble *lista = NULL;

  lista = insertar (&lista, 2019);
  mostrar (lista);
}
