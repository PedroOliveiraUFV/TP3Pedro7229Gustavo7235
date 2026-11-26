#ifndef CENTRODEPESQUISA_H
#define CENTRODEPESQUISA_H

#include "PokeLista.h"

typedef struct {
    Pokelista listaSL;
    Pokelista listaQS;
} Centro;

void inicializaCentro(Centro *centro, int quant);
void liberarListas(Centro *centro);
void selecaoPokemon(Centro *centro, int* nComparacoes, int* nMovimentacoes, double* tempoS);
void quickSortPokemon(Centro *centro, int* nComparacoes, int* nMovimentacoes, double* tempoS);
void ordenaQS(Centro *centro, int Esq, int Dir, int* nComparacoes, int* nMovimentacoes);
void particionaQS(Centro *centro, int Esq, int Dir, int *i, int *j, int* nComparacoes, int* nMovimentacoes);

#endif