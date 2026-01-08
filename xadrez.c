
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
    printf("Escolha uma peça de xadrez para mover (DIGITE 1-Torre, 2-Bispo, 3-Rainha): \n");
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
        default:
            printf("Peça Inválida\n");
            pecaValida = 0;
            break;
    }

    // Só continua se a peça for válida
    if (pecaValida) {
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
                strcpy(Direcao, "Invalida"); // Evita problemas posteriores
                break;
        }

        // Continua se a direção for válida
        if (strcmp(Direcao, "Invalida") != 0) {
            printf("Escolha agora a quantidade de movimentos que a peça %s deve fazer (DIGITE 1 a 9): \n", PecaDeXadrez);
            scanf("%d", &Movimento);
    
            // Conclusão e simulação do movimento
            if (Movimento >= 1 && Movimento <= 9) {
                int InicioDoMovimento = 0;
                printf("\nSimulando movimento...\n");
                do {
                    InicioDoMovimento++;
                    printf("Movendo para %s...\n", Direcao);
                } while(Movimento > InicioDoMovimento);
        
                printf("\n");
                
                // --- CORREÇÃO APLICADA AQUI ---
                // Adicionado 'Direcao' como o terceiro argumento do printf.
                printf("A peça %s foi movida %d casas para a direção %s.\n", PecaDeXadrez, Movimento, Direcao);
            } else {
                printf("Quantidade de movimentos inválida.\n");
            }
        }
    } // Fim do if (pecaValida)
    

    printf("****FIM DO JOGO****");
    return 0;
}
