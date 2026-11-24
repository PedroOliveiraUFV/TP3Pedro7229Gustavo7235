#ifndef POKEMON_H
#define POKEMON_H

typedef struct {
    int n_pokedex;
    char nome[50];
    char tipo[30];
    int poder;
} Pokemon;

void inicializa_pokemon(Pokemon *poke, int num, char nome[], char tipo[], int poder);
void imprime_pokemon(FILE* arq, Pokemon *poke);

#endif