#include<stdio.h>
#include<stdlib.h>
struct listaLigada
{
  int datos;
  struct listaLigada *siguiente;
};

void
insertaLista (struct listaLigada *lista, int dato)
{
  struct listaLigada *nuevonodo = NULL;
  nuevonodo = (struct listaLigada *) malloc (sizeof (struct listaLigada));
  if (nuevonodo == NULL)
    {
      return;
    }

  if (lista == NULL)
    {
      lista = nuevonodo;
      lista->datos = dato;
      lista->siguiente = NULL;
    }
  else
    {
      lista=nuevonodo->siguiente;
      lista->datos = dato;
      lista->siguiente=NULL;
    }
}

void
mostrarLista (struct listaLigada *lista)
{
  struct listaLigada *actual = NULL;
  actual = lista;
  while (actual != NULL)
    {
      printf ("%d\n", actual->datos);
      actual = actual->siguiente;
    }
}

void
main ()
{
  struct listaLigada *lista = NULL;
  insertaLista (lista, 2019);
  mostrarLista(lista);
  return;
}
