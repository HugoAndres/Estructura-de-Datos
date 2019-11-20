#include "pila.h"

void
Push (struct Pila **pila, int dato)
{
  struct Pila *nuevo = NULL;
  nuevo = (struct Pila *) malloc (sizeof (struct Pila));
  if (nuevo == NULL)
    {
      return;
    }
  if (*pila == NULL)
    {

      *pila = nuevo;
      (*pila)->datos = dato;
      (*pila)->tope = NULL;
    }
  else
    {
      nuevo->tope = *pila;
      nuevo->datos = dato;
      *pila = nuevo;
    }

}

int
Pop (struct Pila **pila)
{
  struct Pila *aux;
  int dato;
  if (*pila == NULL)
    {
      return 0;
    }
  aux = *pila;
  dato = (*pila)->datos;
  *pila = (*pila)->tope;
  free (aux);
  return dato;
}

void
Mostrar (struct Pila *pila)
{
  struct Pila *actual = NULL;
  actual = pila;
  while (actual != NULL)
    {
      printf ("\n%d\n", actual->datos);
      actual = actual->tope;
    }
  return;
}
