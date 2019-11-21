#include "cola.h"


void
insertar (struct Cola **primero, struct Cola **ultimo, int dato)
{
  struct Cola *nuevo = NULL;
  nuevo = (struct Cola *) malloc (sizeof (struct Cola));

  if (nuevo != NULL)
    {
      nuevo->datos = dato;
      nuevo->siguiente = NULL;
      if (*primero == NULL)
	{
	  *primero = nuevo;
	}
      else
	{
	  (*ultimo)->siguiente = nuevo;
	}
      *ultimo = nuevo;
    }
  else
    {
      printf ("No se pudo insertar\n");
    }
}

int
eliminar (struct Cola **primero, struct Cola **ultimo)
{
  int dato;
  struct Cola *nuevo = NULL;
  dato = (*primero)->datos;
  nuevo = *primero;
  *primero = (*primero)->siguiente;

  if (*primero == NULL)
    {
      *ultimo = NULL;
    }
  free (nuevo);
  return dato;
}

void
mostrar (struct Cola *cola)
{
  if (cola == NULL)
    {
      printf ("\nCola vacia\n");
    }
  else
    {
      while (cola != NULL)
	{
	  printf ("%d\n", cola->datos);
	  cola = cola->siguiente;
	}
      printf ("\n");
    }
}
