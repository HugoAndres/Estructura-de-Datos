#include "Arbol_Binario_de_Busqueda.h"

void
insertar (struct ABB **arbol, int dato)
{
  struct ABB *padre = NULL;
  struct ABB *actual = *arbol;
  while (actual != NULL && dato != actual->datos)
    {
      padre = actual;
      if (dato < actual->datos)
	{
	  actual = actual->izquierdo;
	}
      else if (dato > actual->datos)
	{
	  actual = actual->derecho;
	}
    }
  if (actual != NULL)
    return;
  if (padre == NULL)
    {
      *arbol = (struct ABB *) malloc (sizeof (struct ABB));
      (*arbol)->datos = dato;
      (*arbol)->izquierdo = (*arbol)->derecho = NULL;
    }
  else if (dato < padre->datos)
    {
      actual = (struct ABB *) malloc (sizeof (struct ABB));
      padre->izquierdo = actual;
      actual->datos = dato;
      actual->izquierdo = actual->derecho = NULL;
    }
  else if (dato > padre->datos)
    {
      actual = (struct ABB *) malloc (sizeof (struct ABB));
      padre->derecho = actual;
      actual->datos = dato;
      actual->izquierdo = actual->derecho = NULL;
    }
}

int
esHoja (struct ABB *arbol)
{
  return !arbol->derecho && !arbol->izquierdo;
}

void
eliminar (struct ABB **arbol, int dato)
{
  struct ABB *padre = NULL;
  struct ABB *actual = NULL;
  struct ABB *nuevo = NULL;
  int aux;
  actual = *arbol;
  while (actual != NULL)
    {
      if (dato == actual->datos)
	{
	  if (esHoja (actual))
	    {
	      if (padre)
		{
		  if (padre->derecho == actual)
		    {
		      padre->derecho = NULL;
		    }
		}
	      else if (padre->izquierdo == actual)
		{
		  padre->izquierdo = NULL;
		}
	      free (actual);
	      actual = NULL;
	      return;
	    }
	  else
	    {
	      padre = actual;
	      if (actual->derecho)
		{
		  nuevo = actual->derecho;
		  while (nuevo->izquierdo)
		    {
		      padre = nuevo;
		      nuevo = nuevo->izquierdo;
		    }
		}
	      else
		{
		  nuevo = actual->izquierdo;
		  while (nuevo->derecho)
		    {
		      padre = nuevo;
		      nuevo = nuevo->derecho;
		    }
		}
	      aux = actual->datos;
	      actual->datos = nuevo->datos;
	      nuevo->datos = aux;
	      actual = nuevo;
	    }
	}
      else
	{
	  padre = actual;
	  if (dato > actual->datos)
	    {
	      actual = actual->derecho;
	    }
	  else if (dato < actual->datos)
	    {
	      actual = actual->izquierdo;
	    }
	}
    }
}

int
buscar (struct ABB *arbol, int dato)
{
  struct ABB *actual = arbol;
  while (actual != NULL)
    {
      if (dato == actual->datos)
	return printf ("\nEl elemento %d SI esta.\n", actual->datos);
      else if (dato < actual->datos)
	actual = actual->izquierdo;
      else if (dato > actual->datos)
	actual = actual->derecho;
    }
  return printf ("El elemento %d NO esta.\n", dato);
}

void
INORDEN (struct ABB *arbol)
{
  if (arbol != NULL)
    {
      INORDEN (arbol->izquierdo);
      printf ("%d ,", arbol->datos);
      INORDEN (arbol->derecho);
    }
}

void
PREORDEN (struct ABB *arbol)
{
  if (arbol != NULL)
    {
      printf ("%d ,", arbol->datos);
      PREORDEN (arbol->izquierdo);
      PREORDEN (arbol->derecho);
    }
}

void
POSTORDEN (struct ABB *arbol)
{
  if (arbol != NULL)
    {
      POSTORDEN (arbol->izquierdo);
      POSTORDEN (arbol->derecho);
      printf ("%d ,", arbol->datos);
    }
}
