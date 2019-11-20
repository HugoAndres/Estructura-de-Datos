#ifndef __PILA_H__
#define __PILA_H__

#include<stdio.h>
#include<stdlib.h>

struct Pila
{
  int datos;
  struct Pila *tope;
};

void Push (struct Pila **, int);

int Pop (struct Pila **);

void Mostrar (struct Pila *);

#endif
