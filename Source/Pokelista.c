#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../Headers/Pokelista.h"

void fazlistavazia(Pokelista* lista){
    lista -> primeiro = INICIO;
    lista -> ultimo = primeiro;
}

int listaehvazia(Pokelista* lista){
    return lista->primeiro == lista->ultimo;
}

void inserenalista(Pokelista* lista, Pokemon poke){
    if(lista.ultimo==MAXTAM){
        printf("Maximo de Pokemons da Lista Atingido. Max: 10000\n");
        return;
    }
    lista->Item[ultimo] = poke;
    lista->ultimo++;
}

void imprimeLista(Pokelista* lista);

void selecaoPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, double* tempoS){
    *nComparacoes = 0;
    *nMovimentacoes = 0;
    clock_t inicio = clock();
    int i, j, min;
    Pokemon aux;
    for(i = 0; i<n-1;i++){
        min = i;
        for(j = i+1; j<n;j++){
            (*nComparacoes)++;
            if(lista->Item[j]<lista->Item[min]){
                min = j;
            }
            (*nMovimentacoes)++;
            aux = lista->Item[min];
            lista->Item[min] = lista->Item[i];
            lista->Item[i] = aux;
        }
    }
    clock_t fim = clock();
    tempoS = (double)(fim - inicio)/CLOCKS_PER_SEC;
}

void quickSortPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, double* tempoS){
    *nComparacoes = 0;
    *nMovimentacoes = 0;
    clock_t inicio = clock();
    ordenaQS(lista, lista->primeiro, lista->ultimo-1, nComparacoes, nMovimentacoes);
    clock_t fim = clock();
    tempoS = (double)(fim - inicio)/CLOCKS_PER_SEC;
}

void ordenaQS(Pokelista* lista, int Esq, int Dir, int* nComparacoes, int* nMovimentacoes){
    int i, j;
    particionaQS (lista, Esq, Dir, &i, &j, nComparacoes, nMovimentacoes);
    (*nComparacoes)++;
    if(Esq<j) ordenaQS(lista, Esq, j, nComparacoes, nMovimentacoes);
    (*nComparacoes)++;
    if(i<Dir) ordenaQS(lista, i, Dir, nComparacoes, nMovimentacoes);
}

void particionaQS(Pokelista* lista, int Esq, int Dir, int *i, int *j, int* nComparacoes, int* nMovimentacoes){
    Pokemon aux;
    int pivo;
    *i = Esq; *j = Dir;
    pivo = lista->Item[(*i+*j)/2].poder;
    do{
        while(pivo>lista->Item[i].poder) (*i)++;
        while(pivo<lista->Item[j].poder) (*j)--;
        if (*i <= *j){
            (*nMovimentacoes)++;
            aux = lista->Item[i].poder;
            lista->Item[i].poder = lista->Item[j].poder;
            lista->Item[j].poder = aux;
            (*i)++; (*j)--;
        }
    }while(*i<=*j);
}