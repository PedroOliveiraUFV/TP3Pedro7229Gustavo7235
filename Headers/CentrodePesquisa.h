#ifndef CENTRODEPESQUISA_H
#define CENTRODEPESQUISA_H

#include "Pokelista.h"

typedef struct {
    Pokelista listaSL;
    Pokelista listaQS;
} Centro;

void inicializaCentro(Centro *centro);
void selecaoPokemon(Centro *centro, int* nComparacoes, int* nMovimentacoes, double* tempoS);
void quickSortPokemon(Centro *centro, int* nComparacoes, int* nMovimentacoes, double* tempoS);
void ordenaQS(Centro *centro, int Esq, int Dir, int* nComparacoes, int* nMovimentacoes);
void particionaQS(Centro *centro, int Esq, int Dir, int *i, int *j, int* nComparacoes, int* nMovimentacoes);

#endif