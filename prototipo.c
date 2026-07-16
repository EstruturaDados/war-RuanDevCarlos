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
    
    if (numATK > numDEF) {
        strcpy(defensor->cor, atacante->cor);
        int totalTropas = atacante->tropas + defensor-> tropas;
        
        if (totalTropas % 2 == 0){
            atacante->tropas = totalTropas / 2;
            defensor->tropas = totalTropas / 2;
        } else {
            atacante->tropas = totalTropas / 2 + 1;
            defensor->tropas = totalTropas / 2;
        }

        printf("\n ### Atacante Venceu ### \n");
    } else if (numDEF > numATK) {
        strcpy(defensor->cor, atacante->cor);
        atacante->tropas--;
        printf("\n ### Defensor Venceu ### \n");
    } else {
        printf("\n ### EMPATE ### \n");
    }
}

// função principal
int main() {
    int i;
    int atk;
    int def;
    int opcao;
    int MAX_TERRITORIO;

    //MENU
    do {
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

        do {
            printf("\n===========================================================\n");
            printf("              MAPA DO MUNDO - ESTADO ATUAL                 \n");
            printf("===========================================================\n");

            // exibição de territórios cadastrados
            for (i = 0; i < MAX_TERRITORIO; i++) {
                printf("%d. %s - Cor: %s | Tropas: %d\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
            }

            // fase de ataque
            printf("\n --- FASE DE ATAQUE ---");
            printf("\nEscolha o territorio atacante (1 a %d, ou 0 para sair): ", MAX_TERRITORIO);
            scanf("%d", &atk);
            limparBufferEntrada();

            if (atk == 0) {
                printf("\nTchau, Tchau!");
                continue;
            };

            printf("\nEscolha o territorio defensor (1 a %d): ", MAX_TERRITORIO);
            scanf("%d", &def);
            limparBufferEntrada();

            if ( strcmp(mapa[atk-1].cor, mapa[def-1].cor) == 0) {
                printf("\nEste territorio ja foi dominado!");
                continue;
            }

            atacar(&mapa[atk-1], &mapa[def-1]);

        } while (atk != 0);

        free(mapa);
        opcao = 0;
    } while (opcao != 0);
    
}