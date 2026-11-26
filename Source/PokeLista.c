#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../Headers/PokeLista.h"

void fazlistavazia(Pokelista* lista){
    lista -> primeiro = INICIO;
    lista -> ultimo = lista -> primeiro;
}

int listaehvazia(Pokelista* lista){
    return lista->primeiro == lista->ultimo;
}

void inserenalista(Pokelista* lista, Pokemon poke){
    if(lista -> ultimo==MAXTAM){
        printf("Maximo de Pokemons da Lista Atingido. Max: 50000\n");
        return;
    }
    lista->Item[lista -> ultimo] = poke;
    lista->ultimo++;
}

void imprimeLista(FILE* arq, Pokelista* lista){
    for(int i = 0; i<lista->ultimo; i++){
        fprintf(arq, "%d. ",i+1);
        imprime_pokemon(arq, &lista->Item[i]);
    }
}

void selecaoPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, double* tempoS){
    *nComparacoes = 0;
    *nMovimentacoes = 0;
    int n = lista -> ultimo;
    clock_t inicio = clock();
    int i, j, min;
    Pokemon aux;
    for(i = 0; i<n-1;i++){
        min = i;
        for(j = i+1; j<n;j++){
            (*nComparacoes)++;
            if(lista->Item[j].poder<lista->Item[min].poder || (lista->Item[j].poder==lista->Item[min].poder && lista->Item[j].n_pokedex<lista->Item[min].n_pokedex)){
                min = j;
            }
        }
        (*nMovimentacoes)++;
        aux = lista->Item[min];
        lista->Item[min] = lista->Item[i];
        lista->Item[i] = aux;
    }
    clock_t fim = clock();
    *tempoS = (double)(fim - inicio)/CLOCKS_PER_SEC;
}

void quickSortPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, double* tempoS){
    *nComparacoes = 0;
    *nMovimentacoes = 0;
    clock_t inicio = clock();
    ordenaQS(lista, lista->primeiro, lista->ultimo -1, nComparacoes, nMovimentacoes);
    clock_t fim = clock();
    *tempoS = (double)(fim - inicio)/CLOCKS_PER_SEC;
}

void ordenaQS(Pokelista* lista, int Esq, int Dir, int* nComparacoes, int* nMovimentacoes){
    int i, j;
    particionaQS (lista, Esq, Dir, &i, &j, nComparacoes, nMovimentacoes);
    (*nComparacoes)++;
    if(Esq<j) {
        ordenaQS(lista, Esq, j, nComparacoes, nMovimentacoes);
    }
    (*nComparacoes)++;
    if(i<Dir) {
        ordenaQS(lista, i, Dir, nComparacoes, nMovimentacoes);
    }
}

void particionaQS(Pokelista* lista, int Esq, int Dir, int *i, int *j, int* nComparacoes, int* nMovimentacoes){
    Pokemon aux;
    int pivoPoder, pivoNPokedex;
    *i = Esq; *j = Dir;
    pivoPoder = lista->Item[(*i+*j)/2].poder;
    pivoNPokedex = lista->Item[(*i+*j)/2].n_pokedex;
    do{
        while(pivoPoder>lista->Item[*i].poder || (pivoPoder==lista->Item[*i].poder && pivoNPokedex>lista->Item[*i].n_pokedex)) (*i)++;
        while(pivoPoder<lista->Item[*j].poder || (pivoPoder==lista->Item[*j].poder && pivoNPokedex<lista->Item[*j].n_pokedex)) (*j)--;
        if (*i <= *j){
            (*nMovimentacoes)++;
            aux = lista->Item[*i];
            lista->Item[*i] = lista->Item[*j];
            lista->Item[*j] = aux;
            (*i)++; (*j)--;
        }
    }while(*i<=*j);
}
