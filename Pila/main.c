#include "pila.h"

int
main (void)
{
  struct Pila *pila = NULL;

  Push (&pila, 1);
  Push (&pila, 3);
  Push (&pila, 2);
  Mostrar (pila);
  printf ("-----------");
  Pop (&pila);
  Pop (&pila);
  Mostrar (pila);
  printf ("-----------");
  Push (&pila, 4);
  Push (&pila, 45);
  Push (&pila, 54);
  Push (&pila, 14);
  Push (&pila, 22);
  Mostrar (pila);

}
