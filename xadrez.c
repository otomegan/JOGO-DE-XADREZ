#include <stdio.h>
#include <string.h>

int main() {
    char PecaDeXadrez[20];
    int peca;
    int pecaValida = 1;
    int DirecaoEscolhida;
    char Direcao[20];
    int Movimento;

    // Pede e valida a peça
    printf("Escolha uma peça de xadrez para mover (DIGITE 1-Torre, 2-Bispo, 3-Rainha, 4-Cavalo): \n");
    scanf("%d", &peca);

    switch(peca) {
        case 1:
            strcpy(PecaDeXadrez, "Torre");
            break;
        case 2:
            strcpy(PecaDeXadrez, "Bispo");
            break;
        case 3:
            strcpy(PecaDeXadrez, "Rainha");
            break;
        case 4:
            strcpy(PecaDeXadrez, "Cavalo");
            break;
        default:
            printf("Peça Inválida\n");
            pecaValida = 0;
            break;
    }

    // Só continua se a peça for válida
    if (pecaValida) {
        // Lógica especial para o Cavalo
        if (strcmp(PecaDeXadrez, "Cavalo") == 0) {
            int movimentoCavalo;
            printf("Escolha a direção do movimento em L (1-Frente-Direita, 2-Frente-Esquerda, 3-Direita-Frente, 4-Direita-Tras): \n");
            scanf("%d", &movimentoCavalo);

            printf("\nSimulando movimento do Cavalo...\n");

            switch (movimentoCavalo) {
                case 1: // Duas para frente e uma para direita
                    for (int i = 0; i < 2; i++) { printf("Movendo 1 casa para Frente...\n"); }
                    printf("Movendo 1 casa para Direita...\n");
                    printf("\nA peça Cavalo foi movida em L para Frente-Direita.\n");
                    break;
                case 2: // Duas para frente e uma para esquerda
                    for (int i = 0; i < 2; i++) { printf("Movendo 1 casa para Frente...\n"); }
                    printf("Movendo 1 casa para Esquerda...\n");
                    printf("\nA peça Cavalo foi movida em L para Frente-Esquerda.\n");
                    break;
                case 3: // Duas para direita e uma para frente
                    for (int i = 0; i < 2; i++) { printf("Movendo 1 casa para Direita...\n"); }
                    printf("Movendo 1 casa para Frente...\n");
                    printf("\nA peça Cavalo foi movida em L para Direita-Frente.\n");
                    break;
                case 4: // Duas para direita e uma para trás
                    for (int i = 0; i < 2; i++) { printf("Movendo 1 casa para Direita...\n"); }
                    printf("Movendo 1 casa para Trás...\n");
                    printf("\nA peça Cavalo foi movida em L para Direita-Trás.\n");
                    break;
                default:
                    printf("Movimento Inválido para o Cavalo.\n");
                    break;
            }
        } else {
            // Lógica para as outras peças
            printf("Escolha a direção do movimento (DIGITE 1-Direita, 2-Esquerda, 3-Frente, 4-Trás, 5-Diagonal): \n");
            scanf("%d", &DirecaoEscolhida);

            switch(DirecaoEscolhida) {
                case 1:
                    strcpy(Direcao, "Direita");
                    break;
                case 2:
                    strcpy(Direcao, "Esquerda");
                    break;
                case 3:
                    strcpy(Direcao, "Frente");
                    break;
                case 4:
                    strcpy(Direcao, "Trás");
                    break;
                case 5:
                    strcpy(Direcao, "Diagonal");
                    break;
                default:
                    printf("Movimento Inválido\n");
                    strcpy(Direcao, "Invalida");
                    break;
            }

            if (strcmp(Direcao, "Invalida") != 0) {
                printf("Escolha agora a quantidade de movimentos que a peça %s deve fazer (DIGITE 1 a 9): \n", PecaDeXadrez);
                scanf("%d", &Movimento);
        
                if (Movimento >= 1 && Movimento <= 9) {
                    int InicioDoMovimento = 0;
                    printf("\nSimulando movimento...\n");
                    do {
                        InicioDoMovimento++;
                        printf("Movendo para %s...\n", Direcao);
                    } while(Movimento > InicioDoMovimento);
            
                    printf("\n");
                    printf("A peça %s foi movida %d casas para a direção %s.\n", PecaDeXadrez, Movimento, Direcao);
                } else {
                    printf("Quantidade de movimentos inválida.\n");
                }
            }
        }
    } // Fim do if (pecaValida)
    
    printf("\n****FIM DO JOGO****\n");
    return 0;
}
