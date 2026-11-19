#include <stdio.h>
#include <string.h>

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

void selecaoPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, int* tempoS){
    *nComparacoes = 0;
    *nMovimentacoes = 0;
    *tempoS = 0;
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
}

void quickSortPokemon(Pokelista* lista, int* nComparacoes, int* nMovimentacoes, int* tempoS){
    ordenaQS(lista, lista->primeiro, lista->ultimo-1, nComparacoes, nMovimentacoes, tempoS);
}

void ordenaQS(Pokelista* lista, int Esq, int Dir, int* nComparacoes, int* nMovimentacoes, int* tempoS){
    int i, j;
    particionaQS(lista, Esq, Dir, &i, &j, nComparacoes,);
}
void particionaQS(Pokelista* lista, int Esq, int Dir, int *i, int *j, int* nComparacoes, int* nMovimentacoes, int* tempoS);