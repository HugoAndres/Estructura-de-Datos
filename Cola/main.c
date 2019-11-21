#include "cola.h"

int
main ()
{
  struct Cola *primero = NULL;
  struct Cola *ultimo = NULL;

  insertar (&primero, &ultimo, 10);
  insertar (&primero, &ultimo, 10);
  insertar (&primero, &ultimo, 13);
  insertar (&primero, &ultimo, 20);
  insertar (&primero, &ultimo, 15);
  insertar (&primero, &ultimo, 18);
  insertar (&primero, &ultimo, 15);
  mostrar (primero);
  printf ("--------------------\n");
  eliminar (&primero, &ultimo);
  eliminar (&primero, &ultimo);
  mostrar (primero);
}
