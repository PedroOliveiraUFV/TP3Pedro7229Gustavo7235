#include <stdio.h>
#include <string.h>
#include "Headers/Pokelista.h"

int lerArquivos(Pokelista* lista1, Pokelista* lista2){
    char nomep[50], tipo[30];
    int quant, num_poke, poder;

    if(fscanf(arq, "%d", &quant)!= 1){
        printf("Erro ao ler quantidade de pokemons.");
        return 0;
    }

    for(int i = 0; i < quant; ++i){
        if(fscanf(arq, "%d %49s %29s %d", &num_poke, nomep, tipo, &poder) != 4){
            printf("Erro ao ler os pokemons.");
            return 0;
        }
        Pokemon pikachu;
        inicializa_pokemon(&pikachu, num_poke, nomep, tipo, poder);
        inserenalista(lista1, pikachu);
        inserenalista(lista2, pikachu);
    }
    return 1;
}

int main(){
    Pokelista listaSL, listaQS;
    if(!lerArquivos(&listaSL, &listaQS)){
        printf("Erro ao ler arquivos")
        return 0;
    }

    double TempoS;
    int Movimentacoes, Comparacoes;

    selecaoPokemon(&listaSL,&Comparacoes,&Movimentacoes, &TempoS);

    printf("Resultados Algoritmo Selecao:\n");
    printf("Comparacoes: %d\n", Comparacoes);
    printf("Movimentacoes: %d\n", Movimentacoes);
    printf("Tempo (segundos): %.2f\n", TempoS);
    printf("Lista Organizada\n");
    imprimeLista(&listaSL);

    quickSortPokemon(&listaQS,&Comparacoes,&Movimentacoes, &TempoS);

    printf("Resultados Algoritmo QuickSort:\n");
    printf("Comparacoes: %d\n", Comparacoes);
    printf("Movimentacoes: %d\n", Movimentacoes);
    printf("Tempo (segundos): %.2f\n", TempoS);
    printf("Lista Organizada\n");
    imprimeLista(&listaQS);

    return 0;
}