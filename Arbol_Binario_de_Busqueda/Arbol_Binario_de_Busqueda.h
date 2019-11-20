#ifndef __ABB_H__
#define __ABB_H__


#include<stdio.h>
#include<stdlib.h>

struct ABB
{
  int datos;
  struct ABB *derecho;
  struct ABB *izquierdo;
};

int vacio (struct ABB *);
void insertar (struct ABB **, int);
int esHoja (struct ABB *);
void eliminar (struct ABB **, int);
void inOrden (struct ABB *, void (*func) (int *));
void postOrden (struct ABB *, void (*func) (int *));
void preOrden (struct ABB *, void (*func) (int *));
void Mostrar (int *);
int buscar (struct ABB *, int);
#endif
