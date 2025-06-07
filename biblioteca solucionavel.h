/*biblioteca para conferir se o tabuleiro é solucionavel*/


#ifndef SOLUCIONAVEL_H
#define SOLUCIONAVEL_H

#define TAMANHO 4

static inline int verificarSolucionavel(int tab[TAMANHO][TAMANHO]) {
    int vetor[TAMANHO * TAMANHO];
    int k = 0;

    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            vetor[k++] = tab[i][j];
        }
    }

    int inversoes = 0;
    for(int i = 0; i < TAMANHO * TAMANHO; i++) {
        for(int j = i + 1; j < TAMANHO * TAMANHO; j++) {
            if(vetor[i] && vetor[j] && vetor[i] > vetor[j]) {
                inversoes++;
            }
        }
    }

    int linha_zero = 0;
    for(int i = TAMANHO - 1; i >= 0; i--) {
        for(int j = 0; j < TAMANHO; j++) {
            if(tab[i][j] == 0) {
                linha_zero = TAMANHO - i;
                break;
            }
        }
    }

    if((linha_zero % 2 == 0 && inversoes % 2 == 1) || 
       (linha_zero % 2 == 1 && inversoes % 2 == 0)) {
        return 1; // Solucionável
    }
    return 0; // Não solucionável
}

#endif
