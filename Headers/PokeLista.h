#ifndef POKELISTA_H
#define POKELISTA_H

#include "Pokemon.h"

#define MAXTAM 50000
#define INICIO 0

typedef struct {
    Pokemon Item[MAXTAM];
    int primeiro, ultimo;
} Pokelista;

void fazlistavazia(Pokelista* lista);
int listaehvazia(Pokelista* lista);
void inserenalista(Pokelista* lista, Pokemon poke);
void imprimeLista(FILE* arq, Pokelista* lista);
void selecaoPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, double* tempoS);
void quickSortPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, double* tempoS);
void ordenaQS(Pokelista* lista, int Esq, int Dir, int* nComparacoes, int* nMovimentacoes);
void particionaQS(Pokelista* lista, int Esq, int Dir, int *i, int *j, int* nComparacoes, int* nMovimentacoes);

#endif