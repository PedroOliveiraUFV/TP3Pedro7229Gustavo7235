#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../Headers/PokeLista.h"

void fazlistavazia(Pokelista* lista, int maxtam){
    lista -> MAXTAM = maxtam;
    lista -> Item = (Pokemon*)malloc(lista -> MAXTAM * sizeof(Pokemon));
    lista -> primeiro = INICIO;
    lista -> ultimo = lista -> primeiro;
}

void liberarLista(Pokelista* lista){
    if(lista -> Item == NULL) return;
    lista -> MAXTAM = 0;
    free(lista -> Item);
    lista -> Item = NULL;
    lista -> primeiro = INICIO;
    lista -> ultimo = lista -> primeiro;
}

int listaehvazia(Pokelista* lista){
    return lista->primeiro == lista->ultimo;
}

void inserenalista(Pokelista* lista, Pokemon poke){
    if(lista -> ultimo==lista -> MAXTAM){
        printf("Maximo de Pokemons da Lista Atingido. Max: %d\n", lista -> MAXTAM);
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

