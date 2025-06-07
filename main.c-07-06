/*
CHECKLIST:
-criando a matriz e posicionando os numeros dentro dela
-embaralhando os numeros e verificando se o tabuleiro é solucionavel
-pintando o fundo da matriz
-jogador pode encerrar o jogo no meio da partida
-estrutura para iniciar/finalizar o cronometro e mostrar mensagem de vitória está pré implementada

NÃO FEITO:
1: armazenar jogadores dentro de estatisticas (nome e tempo de conclusão) em forma de ranking
2: terminar de implementar a estrutura de iniciar/finalizar cronometro e mostrar mensagem de vitoria
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "solucionavel.h"

#define TAMANHO 4

//pintar o tabuleiro
#define RESET     "\033[0m"
#define PRETO     "\033[30m"
#define BRANCO_BG "\033[47m"
#define VERMELHO  "\033[31m"

// o tamanho do tabuleiro
int jogo[TAMANHO][TAMANHO];

//struct do jogador
struct Jogador {
  char nome [50];
  int tempo;
};

//funcionalidades que vamos usar no jogo
void menu();
void jogar();
void inicializar();
void exibirTabuleiro();
void estatisticas();
int moverPeca(int linha, int coluna);
int verificarVitoria();

//início do main
int main() {
    menu();
    return 0;
}

//corpo da função menu
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

//esse meotodo vai embaralhar e preencher a matriz
void inicializar() {
    int vetor[TAMANHO * TAMANHO];

    do {
        // criando um vetor unidimensional para auxiliar no embaralhamento
        for (int i = 0; i < TAMANHO * TAMANHO; i++) {
            vetor[i] = i;
        }

        // embaralhndo o vetor usando o algoritmo de Fisher-Yates
        srand(time(NULL));
        for (int i = TAMANHO * TAMANHO - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }

        // copiando o vetor embaralhado para dentro da matriz jogo[][]
        int num = 0;
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                jogo[i][j] = vetor[num++];
            }
        }
    //chamando o metodo pra verificar se o tabuleiro é sulucionavel
    } while (!verificarSolucionavel(jogo)); // repete até ser solucionável
}

//função para exibir o tabuleiro na tela
void exibirTabuleiro(){
    printf("\n");
    printf(VERMELHO "+------+------+------+------+\n" RESET);

    for (int i = 0; i < TAMANHO; i++) {
        printf(VERMELHO "|" RESET);
        for (int j = 0; j < TAMANHO; j++) {
            if (jogo[i][j] == 0) {
                printf(BRANCO_BG "      " RESET);
            } else {
                printf(BRANCO_BG PRETO "  %2d  " RESET, jogo[i][j]);
            }
            printf(VERMELHO "|" RESET);
        }
        printf("\n");
        printf(VERMELHO "+------+------+------+------+\n" RESET);
    }
    printf("\n");
}

//corpo da função jogar
void jogar() {
  struct Jogador jogador; //variavel local que se chama jogador. Ela é do tipo struct Jogador
  char resposta; //para confirmar a resposta se quiser sair do jogo
  int opcao; //para digitar 0 e encerrar o jogo
  time_t inicio, fim; //para marcar o tempo

  printf ("\nDigite o nome do jogador: ");
  fflush(stdin); //para limpar o buffer do teclado
  fgets (jogador.nome, 50, stdin); //para ler o nome do jogador

  inicializar(); //chamada da função inicalizar que ja foi definida

  time(&inicio);// começa a contar o tempo

  while (1){ //laço while para manter o jogo rodando com a pergunta se o jogador deseja sair do jogo
    system("cls"); //pra limpar a tela quando a gente começar a jogar
    exibirTabuleiro();

    //estrutura para iniciar e encerrar cronometro e mostrar mensagem de vitoria
    if (verificarVitoria()) {
        time(&fim);
        jogador.tempo = (int) difftime(fim, inicio);
        printf("\nParabéns, %s! Você venceu!\n", jogador.nome);
        printf("Seu tempo foi de %d segundos.\n", jogador.tempo);

        // VAMOS SALVAR EM ESTATISTICAS AQUI

        printf("Pressione Enter para continuar...");
        getchar();
        getchar();
        break;
    }

    printf("\nInstruções: Digite a linha e coluna da peça que deseja mover (1-4)\n");
    printf("Digite 0 0 para sair e encerrar o jogo\n");
    
    int linha, coluna;
    printf("Linha e coluna (ex: 2 3): ");
    scanf("%d %d", &linha, &coluna);

    // se digitar 0 0 vai perguntar se quer sair
    if (linha == 0 && coluna == 0) {
        printf("Tem certeza que deseja encerrar o jogo? (s/n): ");
        scanf(" %c", &resposta);

        if (resposta == 's' || resposta == 'S') {
            system("cls");
            break;
        }
        continue;
    }

    // converter para índices do array (subtrair 1)
    linha--;
    coluna--;

    // tentar mover a peça
    if (moverPeca(linha, coluna)) {
        printf("Movimento realizado com sucesso!\n");
    } else {
        printf("Movimento inválido! Tente novamente.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        getchar();
    }
  }
}

// função para mover uma peça
int moverPeca(int linha, int coluna) {
    // verificar se as coordenadas estão dentro dos limites
    if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
        return 0; // Movimento inválido
    }
    
    //se a posição esta vazia não pode mover
    if (jogo[linha][coluna] == 0) {
        return 0; // Movimento inválido
    }
    
    // procurar o espaço vazio (0) adjacente
    int linhaVazia = -1, colunaVazia = -1;
    
    // verificar posições adjacentes (cima, baixo, esquerda, direita)
    int direcoes[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < 4; i++) {
        int novaLinha = linha + direcoes[i][0];
        int novaColuna = coluna + direcoes[i][1];
        
        // verificar se está dentro dos limites
        if (novaLinha >= 0 && novaLinha < TAMANHO && 
            novaColuna >= 0 && novaColuna < TAMANHO) {
            
            // se encontrou o espaço vazio
            if (jogo[novaLinha][novaColuna] == 0) {
                linhaVazia = novaLinha;
                colunaVazia = novaColuna;
                break;
            }
        }
    }
    
    // se não encontrou espaço vazio adjacente
    if (linhaVazia == -1) {
        return 0; // Movimento inválido
    }
    
    // fazer a troca
    jogo[linhaVazia][colunaVazia] = jogo[linha][coluna];
    jogo[linha][coluna] = 0;
    
    return 1; // Movimento válido
}

// função para verificar se o jogador venceu
int verificarVitoria() {
    int contador = 1;
    
    // ferificar se os números estão em ordem (1-15)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            // última posição deve ser 0 (espaço vazio)
            if (i == TAMANHO - 1 && j == TAMANHO - 1) {
                if (jogo[i][j] != 0) {
                    return 0;
                }
            } else {
                if (jogo[i][j] != contador) {
                    return 0;
                }
                contador++;
            }
        }
    }
    
    return 1;
}

void estatisticas() {

}
