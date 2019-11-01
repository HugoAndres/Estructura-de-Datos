#include<stdio.h>
#include<stdlib.h>

struct Pila
{
  int datos;
  struct Pila *tope;
};

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

int
main (void)
{
  struct Pila *pila = NULL;

  Push (&pila, 1);
  Push (&pila, 3);
  Push (&pila, 2);
  Mostrar (pila);
  printf("-----------");
  Pop (&pila);
  Pop (&pila);
  Mostrar (pila);
  printf("-----------");
  Push (&pila, 4);
  Push (&pila, 45);
  Push (&pila, 54);
  Push (&pila, 14);
  Push (&pila, 22);
  Mostrar (pila);

}
