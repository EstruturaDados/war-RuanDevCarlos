// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Protótipos das Funções ---
// limpa as entradas de scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int i;
    int opcao;
    int MAX_TERRITORIO;
    struct territorio *mapa;
    mapa = (struct territorio *) malloc(MAX_TERRITORIO * sizeof(struct territorio));

    //MENU
    do {
        printf("\n========================================================\n");
        printf("\n");
        printf("Insira a Quantidade de Territorios: ");
        scanf("%d", &MAX_TERRITORIO);

        // cadastro de territórios
        for (i = 0; i < MAX_TERRITORIO; i++) {
            printf("\n--- Cadastrando Territorio %d ---\n", i + 1);
            printf("Nome do Territorio: ");
            fgets(mapa[i].nome, 30, stdin);

            printf("Cor do exercito: ");
            fgets(mapa[i].cor, 10, stdin);

            printf("Numero de tropas: ");
            scanf("%d", &mapa[i].tropas);
            limparBufferEntrada();
        };

        printf("\nCadastro Incial Concluido com Sucesso\n");
        printf("\n===========================================================\n");
        printf("              MAPA DO MUNDO - ESTADO ATUAL                 \n");
        printf("===========================================================\n");

        // exibição de territórios cadastrados
        for (i = 0; i < MAX_TERRITORIO; i++) {
            printf("\nTerritorio %d:", i + 1);
            printf("- Nome: %s", mapa[i].nome);
            printf("- Cor: %s", mapa[i].cor);
            printf("- Tropas: %d\n", mapa[i].tropas);
        };


        free(mapa);
        opcao = 0;
    } while (opcao != 0);
    
}