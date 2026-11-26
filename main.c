#include <stdio.h>
#include <string.h>

#include "Headers/PokeLista.h"
#include "Headers/Pokemon.h"
#include "Headers/CentrodePesquisa.h"

int lerArquivos(Centro *centro){
    char nomep[50], tipo[30];
    int quant, num_poke, poder;

    FILE *arq = fopen("entrada.txt", "r");
    if(arq == NULL){
        printf("Erro ao ler a entrada\n");
        return 0;
    }

    if(fscanf(arq, "%d", &quant) != 1){
        printf("Erro ao ler quantidade de pokemons.");
        return 0;
    }

    inicializaCentro(centro, quant);

    for(int i = 0; i < quant; ++i){
        if(fscanf(arq, "%d %49s %29s %d", &num_poke, nomep, tipo, &poder) != 4){
            printf("Erro ao ler os pokemons.");
            return 0;
        }
        Pokemon pikachu;
        inicializa_pokemon(&pikachu, num_poke, nomep, tipo, poder);
        inserenalista(&centro->listaSL, pikachu);
        inserenalista(&centro->listaQS, pikachu);
    }
    return 1;
}

int escreveResultados(Centro *centro){
    FILE* Res;

    Res = fopen("ResultadoSelecao.txt", "w");
    if(Res == NULL){
        printf("Erro ao escrever resultados do Seleção\n");
        return 0;
    }
    fprintf(Res, "Resultado do algoritimo de seleção:\n\n");
    imprimeLista(Res, &centro->listaSL);
    fclose(Res);

    Res = fopen("ResultadoQuickSort.txt", "w");
    if(Res == NULL){
        printf("Erro ao escrever resultados do QuickSort\n");
        return 0;
    }
    fprintf(Res, "Resultado do algoritimo de QuickSort:\n\n");
    imprimeLista(Res, &centro->listaQS);
    fclose(Res);

    return 1;
}

int main(){

    Centro centrodepesquisa;

    if(!lerArquivos(&centrodepesquisa)){
        printf("Erro ao ler arquivos");
        return 0;
    }

    double TempoS;
    int Movimentacoes, Comparacoes;

    selecaoPokemon(&centrodepesquisa,&Comparacoes,&Movimentacoes, &TempoS);

    printf("Resultados Algoritmo Selecao:\n");
    printf("Comparacoes: %d\n", Comparacoes);
    printf("Movimentacoes: %d\n", Movimentacoes);
    printf("Tempo (segundos): %.5f\n", TempoS);
    printf("Lista Organizada\n");
    
    printf("---------------------------------------------------------\n");
    
    quickSortPokemon(&centrodepesquisa,&Comparacoes,&Movimentacoes, &TempoS);

    printf("Resultados Algoritmo QuickSort:\n");
    printf("Comparacoes: %d\n", Comparacoes);
    printf("Movimentacoes: %d\n", Movimentacoes);
    printf("Tempo (segundos): %.5f\n", TempoS);
    printf("Lista Organizada\n");

    if(!escreveResultados(&centrodepesquisa)){
        printf("Erro ao escrever Resultados");
    }

    return 0;
}
