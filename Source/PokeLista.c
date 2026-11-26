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

