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
void imprimeLista(Pokelista* lista);
void selecaoPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, int* tempoS);
void quickSortPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, int* tempoS);
void ordenaQS(Pokelista* lista, int Esq, int Dir, int* nComparacoes, int* nMovimentacoes, int* tempoS);
void particionaQS(Pokelista* lista, int Esq, int Dir, int *i, int *j, int* nComparacoes, int* nMovimentacoes, int* tempoS);

#endif