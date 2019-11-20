#include<stdio.h>
#include<stdlib.h>

struct ABB
{
  int datos;
  struct ABB *derecho;
  struct ABB *izquierdo;
};

int
vacio (struct ABB *arbol)
{
  return arbol == NULL;
}

void
insertar (struct ABB **arbol, int dato)
{

  struct ABB *padre = NULL;
  struct ABB *actual = *arbol;


  while (!vacio (actual) && dato != actual->datos)
    {
      padre = actual;
      if (dato < actual->datos)
	
	  actual = actual->izquierdo;
	
      else if (dato > actual->datos)
	
	  actual = actual->derecho;
	
    }

  if (!vacio (actual))
    
      return;
    

  if (vacio (padre))
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

  else if (dato < padre->datos)
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
  while (!vacio (actual))
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

void
inOrden (struct ABB *arbol, void (*func) (int *))
{
  if (arbol->izquierdo)
    
      inOrden (arbol->izquierdo, func);
    
  func (&(arbol->datos));
  if (arbol->derecho)
    
      inOrden (arbol->derecho, func);
    
}

void
postOrden (struct ABB *arbol, void (*func) (int *))
{
  if (arbol->izquierdo)
    {
      postOrden (arbol->izquierdo, func);
    }
  if (arbol->derecho)
    {
      postOrden (arbol->derecho, func);
    }
  func (&arbol->datos);
}

void
preOrden (struct ABB *arbol, void (*func) (int *))
{
  func (&arbol->datos);
  if (arbol->izquierdo)
    {
      preOrden (arbol->izquierdo, func);
    }
  if (arbol->derecho)
    {
      preOrden (arbol->derecho, func);
    }
}

void
Mostrar (int *dato)
{
  printf ("%d, ", *dato);
}

int
bucar (struct ABB *arbol, int dato)
{
  struct ABB *actual = arbol;
  while (!vacio (actual))
    {
      if (dato == actual->datos)
	return 1;
      else if (dato < actual->datos)
	actual = actual->izquierdo;
      else if (dato > actual->datos)
	actual = actual->derecho;
    }
  return 0;
}


int
main ()
{
  struct ABB *arbol = NULL;

  insertar (&arbol, 10);
  insertar (&arbol, 5);
  insertar (&arbol, 12);
  insertar (&arbol, 4);
  insertar (&arbol, 11);
  insertar (&arbol, 14);
  printf ("Arbol en InOrden: ");
  inOrden (arbol, Mostrar);
  printf("\n");
  printf ("Arbol en PreOrden: ");
  preOrden (arbol, Mostrar);
  printf("\n");
  printf ("Arbol en PostOrden: ");
  postOrden (arbol, Mostrar);
  
  return 0;
}
