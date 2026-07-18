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
    int KO;
    int flow;
};

// --- Protótipos das Funções ---
// limpa as entradas de scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// função de ataque
void atacar(struct territorio *atacante, struct territorio *defensor, int MAX_TERRITORIO) {
    int atk;
    int def;

    srand(time(NULL));
    int dadoATK = 1 + (rand() % 6);
    int dadoDEF = 1 + (rand() % 6);    

    // fase de ataque
    printf("\n --- FASE DE ATAQUE ---");
    printf("\nEscolha o territorio atacante (1 a %d, ou 0 para sair): ",MAX_TERRITORIO);
    scanf("%d", &atk);
    limparBufferEntrada();

    printf("\nEscolha o territorio defensor (1 a %d): ", MAX_TERRITORIO);
    scanf("%d", &def);
    limparBufferEntrada();

    def--;
    atk--;

    if (atacante[atk].tropas == 0){
        printf("\nO atacante nao tem mais tropas");
        return;
    } else if (defensor[def].tropas == 0) {
        printf("\nO defensor nao tem mais tropas");
        return;
    }
    
    if (dadoATK > dadoDEF) {
        atacante[atk].flow++;
        atacante[atk].tropas++;
        defensor[def].flow = 0;
        defensor[def].tropas--;
        printf("\n ### Atacante Venceu ### \n");
        
    } else if (dadoDEF > dadoATK) {
        defensor[def].flow++;
        defensor[def].tropas++;
        atacante[atk].flow = 0;
        atacante[atk].tropas--;
        printf("\n ### Defensor Venceu ### \n");
    } else {
        printf("\n ### EMPATE ### \n");
    }

    if (atacante[atk].tropas == 0){
        defensor[def].KO++;
    } else if (defensor[def].tropas == 0) {
        atacante[atk].KO++;
    }
}

// funcao de exibiçao do mapa
void exibirMapa(struct territorio *mundo, int territorios){
    int i;
    printf("\n=================== MAPA DO MUNDO - ESTADO ATUAL===================\n");

    // exibição de territórios cadastrados
    for (i = 0; i < territorios; i++) {
        printf("%d. %s - Cor: %s | Tropas: %d\n", i + 1, mundo[i].nome, mundo[i].cor, mundo[i].tropas);
    }
    printf("==================================================================\n");
}

void exibirMissao(int missao){
    switch (missao) {
    case 1:
        printf("\n--- Sua Missao ---");
        printf("\nConsiga um total de 10 tropas\n");
        break;

    case 2:
        printf("\n--- Sua Missao ---");
        printf("\nVenca 3 batalhas consecutivas\n");
        break;

    case 3:
        printf("\n--- Sua Missao ---");
        printf("\nelimine todas as tropas de um exercito\n");
        break;
    
    default:
        break;
    }
}

void atribuirMissao(int *missao){
    srand(time(NULL));
    *missao = 1 + (rand() % 3);
}

void verificarMissao(struct territorio *mundo, int missao){
    int index;
    printf("\nQuem cumpriu a missao: ");
    scanf("%d", &index);
    limparBufferEntrada();

    switch (missao){
    case 1:
        if (mundo[index].tropas >= 10) {
            printf("\nParabens, missao cumprida!!!");
        } else {
            printf("\nAinda nao, se esforce mais");
        }
        break;

    case 2:
        if (mundo[index].flow >= 3) {
            printf("\nParabens, missao cumprida!!!");
        } else {
            printf("\nAinda nao, se esforce mais");
        }
        break;

    case 3:
        if (mundo[index].KO >= 1) {
            printf("\nParabens, missao cumprida!!!");
        } else {
            printf("\nAinda nao, se esforce mais");
        }
        break;

    }
}



// função principal
int main() {
    int i;
    int opcao;
    int missao;
    int MAX_TERRITORIO;

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

    atribuirMissao(&missao);

    // loop de menu e funçoes
    do {
        exibirMapa(mapa, MAX_TERRITORIO);

        exibirMissao(missao);

        printf("\n--- MENU DE ACOES ---");
        printf("\n1- Atacar");
        printf("\n2- Verificar Missao");
        printf("\n0- Sair do programa\n");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                atacar(mapa, mapa, MAX_TERRITORIO);
                break;

            case 2:
                verificarMissao(mapa, missao);
                break;

            case 0:
                printf("\nTchau, Tchau!!!");
                break;
        
            default:
                printf("\nOPCAO INVALIDA");
                break;
        }
    } while (opcao != 0);
    free(mapa);
}