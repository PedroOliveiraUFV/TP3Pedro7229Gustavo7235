#ifndef POKELISTA_H
#define POKELISTA_H

#include "Pokemon.h"

#define INICIO 0

typedef struct {
    Pokemon* Item;
    int primeiro, ultimo;
    int MAXTAM;
} Pokelista;

void fazlistavazia(Pokelista* lista, int maxtam);
void liberarLista(Pokelista* lista);
int listaehvazia(Pokelista* lista);
void inserenalista(Pokelista* lista, Pokemon poke);
void imprimeLista(FILE* arq, Pokelista* lista);

#endif
