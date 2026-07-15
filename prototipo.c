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

// função de ataque
void atacar(struct territorio *atacante, struct territorio *defensor) {
    srand(time(NULL));
    int numATK = 1 + (rand() % 6);
    int numDEF = 1 + (rand() % 6);
    printf("\n%d, %d", numDEF, numATK);
}

// função principal
int main() {
    int i;
    int opcao;
    int MAX_TERRITORIO;

    //MENU
    do {
        printf("\n========================================================\n");
        printf("\n");
        printf("Insira a Quantidade de Territorios: ");
        scanf("%d", &MAX_TERRITORIO);
        limparBufferEntrada();

        // criando o vetor mapa do tipo territorio, com alocação dinamica
        struct territorio *mapa = (struct territorio *) malloc(MAX_TERRITORIO * sizeof(struct territorio));

        if (mapa == NULL) {
            printf("\nERRO: MEMORIA INSUFICIENTE!\n");
        };
        

        // cadastro de territórios
        for (i = 0; i < MAX_TERRITORIO; i++) {
            printf("\n--- Cadastrando Territorio %d ---\n", i + 1);
            printf("Nome do Territorio: ");
            fgets(mapa[i].nome, 30, stdin);
            mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

            printf("Cor do exercito: ");
            fgets(mapa[i].cor, 10, stdin);
            mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

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
            printf("%d. %s - Cor: %s | Tropas: %d\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
        }

        atacar(mapa, mapa);

        free(mapa);
        opcao = 0;
    } while (opcao != 0);
    
}