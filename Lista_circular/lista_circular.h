#ifndef __LISTA_CIRCULAR_H__
#define __LISTA_CIRCULAR_H__

#include<stdio.h>
#include<stdlib.h>

struct listaCircular
{
  int datos;
  struct listaCircular *siguiente;
};


void
insertar (struct listaCircular **, int );

void
eliminar (struct listaCircular **, int);

void
mostrar (struct listaCircular *);

#endif
