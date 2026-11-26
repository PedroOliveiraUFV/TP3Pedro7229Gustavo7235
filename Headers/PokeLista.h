#ifndef POKELISTA_H
#define POKELISTA_H

#include "Pokemon.h"

#define MAXTAM 10000
#define INICIO 0

typedef struct {
    Pokemon Item[MAXTAM];
    int primeiro, ultimo;
} Pokelista;

void fazlistavazia(Pokelista* lista);
int listaehvazia(Pokelista* lista);
void inserenalista(Pokelista* lista, Pokemon poke);
void imprimeLista(FILE* arq, Pokelista* lista);

#endif
