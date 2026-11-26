#include <stdio.h>
#include <time.h>

#include "../Headers/CentrodePesquisa.h"

void inicializaCentro(Centro *centro, int quant){
    fazlistavazia(&centro->listaSL, quant);
    fazlistavazia(&centro->listaQS, quant);
}

void selecaoPokemon(Centro *centro, int* nComparacoes, int* nMovimentacoes, double* tempoS){
    *nComparacoes = 0;
    *nMovimentacoes = 0;
    int n = centro->listaSL.ultimo;
    clock_t inicio = clock();
    int i, j, min;
    Pokemon aux;
    for(i = 0; i<n-1;i++){
        min = i;
        for(j = i+1; j<n;j++){
            (*nComparacoes)++;
            if(centro->listaSL.Item[j].poder<centro->listaSL.Item[min].poder || (centro->listaSL.Item[j].poder==centro->listaSL.Item[min].poder && centro->listaSL.Item[j].n_pokedex<centro->listaSL.Item[min].n_pokedex)){
                min = j;
            }
        }
        (*nMovimentacoes)++;
        aux = centro->listaSL.Item[min];
        centro->listaSL.Item[min] = centro->listaSL.Item[i];
        centro->listaSL.Item[i] = aux;
    }
    clock_t fim = clock();
    *tempoS = (double)(fim - inicio)/CLOCKS_PER_SEC;
}

void quickSortPokemon(Centro *centro, int* nComparacoes, int* nMovimentacoes, double* tempoS){
    *nComparacoes = 0;
    *nMovimentacoes = 0;
    clock_t inicio = clock();
    ordenaQS(centro, centro->listaQS.primeiro, centro->listaQS.ultimo -1, nComparacoes, nMovimentacoes);
    clock_t fim = clock();
    *tempoS = (double)(fim - inicio)/CLOCKS_PER_SEC;
}

void ordenaQS(Centro *centro, int Esq, int Dir, int* nComparacoes, int* nMovimentacoes){
    int i, j;
    particionaQS (centro, Esq, Dir, &i, &j, nComparacoes, nMovimentacoes);
    if(Esq<j) {
        ordenaQS(centro, Esq, j, nComparacoes, nMovimentacoes);
    }
    if(i<Dir) {
        ordenaQS(centro, i, Dir, nComparacoes, nMovimentacoes);
    }
}

void particionaQS(Centro *centro, int Esq, int Dir, int *i, int *j, int* nComparacoes, int* nMovimentacoes){
    Pokemon aux;
    int pivoPoder, pivoNPokedex;
    *i = Esq; *j = Dir;
    pivoPoder = centro->listaQS.Item[(*i+*j)/2].poder;
    pivoNPokedex = centro->listaQS.Item[(*i+*j)/2].n_pokedex;
    do{
        while(++(*nComparacoes), pivoPoder>centro->listaQS.Item[*i].poder || (pivoPoder==centro->listaQS.Item[*i].poder && pivoNPokedex>centro->listaQS.Item[*i].n_pokedex)) (*i)++;
        while(++(*nComparacoes), pivoPoder<centro->listaQS.Item[*j].poder || (pivoPoder==centro->listaQS.Item[*j].poder && pivoNPokedex<centro->listaQS.Item[*j].n_pokedex)) (*j)--;
        if (*i <= *j){
            (*nMovimentacoes)++;
            aux = centro->listaQS.Item[*i];
            centro->listaQS.Item[*i] = centro->listaQS.Item[*j];
            centro->listaQS.Item[*j] = aux;
            (*i)++; (*j)--;
        }
    }while(*i<=*j);
}
