#include <stdio.h>
#include <string.h>

#include "../Headers/Pokemon.h"

void inicializa_pokemon(Pokemon *poke, int num, char nome[], char tipo[], int poder){ //Inicializa o Pokemon com suas devidas caracteristicas e informacoes//
    poke -> n_pokedex = num;

    strcpy(poke -> nome, nome);
    strcpy(poke -> tipo, tipo);

    poke -> poder = poder;
}

void imprime_pokemon(FILE* arq, Pokemon *poke) { //Imprime as informacoes do pokemon//
    fprintf(arq, "ID: %-3d | Nome: %-13s | Tipo: %-8s | Poder: %-2d\n", poke -> n_pokedex, poke -> nome, poke -> tipo, poke -> poder);
}