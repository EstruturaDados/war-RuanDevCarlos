// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_TERRITORIO 5

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Protótipos das Funções ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct territorio mundo[MAX_TERRITORIO];
    int totalTerritorio;
    int opcao;

    //MENU
    do {
        printf("\n========================================================\n");
        printf("\n");
        printf("Vamos cadastrar os 5 territorios inciais do nosso mundo.\n");

        printf("--- Cadastrando Territorio 1 ---\n");
        printf("Nome do Territorio: ");
        fgets(mundo[0].nome, 30, stdin);
        printf
    } while (opcao != 0);
    
    
}