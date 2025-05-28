#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 4

int jogo[TAMANHO][TAMANHO];

void menu();
void jogar();
void inicializar();
void estatisticas();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;

    do {
        printf("\n=== QUEBRA CABECA DESLIZANTE ===\n");
        printf("1. Jogar\n");
        printf("2. Estatisticas\n");
        printf("3. Sair\n");
        printf("================================\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                jogar();
                break;
            
            case 2:
                estatisticas();
                break;
            
            case 3:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while(opcao != 3);
}

void jogar() {

}

void inicializar() { // posiciona os números de 1 a 15, e deixa um espaço vazio
    int num = 1;
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            jogo[i][j] = num++;
        }
    }
    jogo[TAMANHO - 1][TAMANHO - 1] = 0;
}

void estatisticas() {

}