#include <stdio.h>
#include <string.h>

/* Protótipo da função recursiva */
void moverPecaRecursivo(int movimentosRestantes, char* direcao);

int main() {
    char PecaDeXadrez[20];
    int peca;
    int pecaValida = 1;
    int DirecaoEscolhida;
    char Direcao[20];
    int Movimento;

    printf("Escolha uma peça (1-Torre, 2-Bispo, 3-Rainha, 4-Cavalo): \n");
    scanf("%d", &peca);

    switch(peca) {
        case 1: strcpy(PecaDeXadrez, "Torre"); break;
        case 2: strcpy(PecaDeXadrez, "Bispo"); break;
        case 3: strcpy(PecaDeXadrez, "Rainha"); break;
        case 4: strcpy(PecaDeXadrez, "Cavalo"); break;
        default:
            printf("Peça Inválida\n");
            pecaValida = 0;
            break;
    }

    if (pecaValida) {
        if (strcmp(PecaDeXadrez, "Cavalo") == 0) {
            int movimentoCavalo;
            int i;

            printf("Escolha o movimento do Cavalo (1-Frente-Dir, 2-Frente-Esq, 3-Dir-Frente, 4-Dir-Tras): \n");
            scanf("%d", &movimentoCavalo);

            printf("\nSimulando movimento do Cavalo...\n");
            switch (movimentoCavalo) {
                case 1: 
                    for (i = 0; i < 2; i++) { printf("Movendo 1 casa para Frente...\n"); }
                    printf("Movendo 1 casa para Direita...\n");
                    printf("\nA peça Cavalo foi movida.\n");
                    break;
                case 2: 
                    for (i = 0; i < 2; i++) { printf("Movendo 1 casa para Frente...\n"); }
                    printf("Movendo 1 casa para Esquerda...\n");
                    printf("\nA peça Cavalo foi movida.\n");
                    break;
                case 3: 
                    for (i = 0; i < 2; i++) { printf("Movendo 1 casa para Direita...\n"); }
                    printf("Movendo 1 casa para Frente...\n");
                    printf("\nA peça Cavalo foi movida.\n");
                    break;
                case 4: 
                    for (i = 0; i < 2; i++) { printf("Movendo 1 casa para Direita...\n"); }
                    printf("Movendo 1 casa para Trás...\n");
                    printf("\nA peça Cavalo foi movida.\n");
                    break;
                default:
                    printf("Movimento Inválido para o Cavalo.\n");
                    break;
            }
        } else {
            printf("Escolha a direção (1-Direita, 2-Esquerda, 3-Frente, 4-Trás, 5-Diagonal): \n");
            scanf("%d", &DirecaoEscolhida);

            switch(DirecaoEscolhida) {
                case 1: strcpy(Direcao, "Direita"); break;
                case 2: strcpy(Direcao, "Esquerda"); break;
                case 3: strcpy(Direcao, "Frente"); break;
                case 4: strcpy(Direcao, "Trás"); break;
                case 5: strcpy(Direcao, "Diagonal"); break;
                default:
                    printf("Movimento Inválido\n");
                    strcpy(Direcao, "Invalida");
                    break;
            }

            if (strcmp(Direcao, "Invalida") != 0) {
                printf("Escolha a quantidade de movimentos (1 a 9): \n");
                scanf("%d", &Movimento);
        
                if (Movimento >= 1 && Movimento <= 9) {
                    printf("\nSimulando movimento...\n");
                    moverPecaRecursivo(Movimento, Direcao);
                    printf("\n");
                    printf("A peça %s foi movida %d casas para a direção %s.\n", PecaDeXadrez, Movimento, Direcao);
                } else {
                    printf("Quantidade de movimentos inválida.\n");
                }
            }
        }
    }
    
    printf("\n****FIM DO JOGO****\n");
    return 0;
}

/* Implementação da função recursiva */
void moverPecaRecursivo(int movimentosRestantes, char* direcao) {
    if (movimentosRestantes <= 0) {
        return;
    }
    printf("Movendo para %s...\n", direcao);
    moverPecaRecursivo(movimentosRestantes - 1, direcao);
}
