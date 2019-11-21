#ifndef __COLA_H__
#define __COLA_H__

#include<stdio.h>
#include<stdlib.h>

struct Cola
{
  int datos;
  struct Cola *siguiente;
};

void insertar (struct Cola **, struct Cola **, int);

int eliminar (struct Cola **, struct Cola **);

void mostrar (struct Cola *);
#endif
