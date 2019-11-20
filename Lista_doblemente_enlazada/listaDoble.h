#ifndef __LDL_H__
#define __LDL_H__

#include<stdio.h>
#include<stdlib.h>

struct listaDoble
{
  int datos;
  struct listaDoble *siguiente;
  struct listaDoble *anterior;
};

void
insertaInicio (struct listaDoble **, int);

int
eliminarDato (struct listaDoble **, int);

void
mostrar (struct listaDoble *);

#endif
