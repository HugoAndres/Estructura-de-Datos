#ifndef __LSL_H__
#define __LSL_H__

#include<stdio.h>
#include<stdlib.h>

struct listaLigada
{
  int datos;
  struct listaLigada *siguiente;
};

void insertaLista (struct listaLigada **, int);

void mostrarLista (struct listaLigada *);

int eliminarDato (struct listaLigada **, int);
#endif
