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

void insertar (struct ABB **, int);
int esHoja (struct ABB *);
void eliminar (struct ABB **, int);
void INORDEN (struct ABB *);
void PREORDEN (struct ABB *);
void POSTORDEN (struct ABB *);
int buscar (struct ABB *, int);
#endif
