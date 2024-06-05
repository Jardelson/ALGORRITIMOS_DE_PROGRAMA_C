#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

struct Jogador {
    char nome[50];
    int tentativas;
};

int main() {
    struct Jogador ranking[100];
    int num_jogadores = 0;
    char nome[50];
    int numero, tentativa, tentativas = 0;
    int nome_existente;
    char *pos;
    char opcao[10];

    srand(time(NULL));

    printf("Seja bem-vindo ao jogo de adivinhação!\n");

    while (1) {
 
        numero = rand() % 101;

        while (1) {
            printf("Digite seu nome: ");
            if (fgets(nome, sizeof(nome), stdin) == NULL) {
                printf("Erro na leitura do nome. Tente novamente.\n");
                continue;
            }

            pos = strchr(nome, '\n');
            if (pos) {
                *pos = '\0';
            }

            nome_existente = 0;
            for (int i = 0; i < num_jogadores; i++) {
                if (strcmp(ranking[i].nome, nome) == 0) {
                    nome_existente = 1;
                    break;
                }
            }

            if (nome_existente) {
                printf("Nome já escolhido! Tente outro nome.\n");
            } else {
                break;
            }
        }

        printf("Bem-vindo, %s!\n", nome);
        printf("Vou pensar em um número entre 0 e 100, e você deve adivinhar qual é.\n");
        printf("A qualquer momento, você pode digitar 'Dica' para receber uma dica. Entretanto isso contará como um tentativa\n");

        tentativas = 0;

        while (1) {
            printf("Digite sua tentativa: ");
            if (fgets(opcao, sizeof(opcao), stdin) == NULL) {
                printf("Erro na leitura da opção. Tente novamente.\n");
                continue;
            }

          
            pos = strchr(opcao, '\n');
            if (pos) {
                *pos = '\0';
            }

          
            if (strcasecmp(opcao, "dica") == 0) {
                tentativas++;
                if (tentativas == 1) {
                    printf("Esta é a primeira tentativa, não há dicas disponíveis ainda.\n");
                } else {
                    if (tentativa > numero) {
                        printf("O número está entre %d e %d.\n", numero, tentativa);
                    } else {
                        printf("O número está entre %d e %d.\n", tentativa, numero);
                    }
                }
                continue;
            }

            if (sscanf(opcao, "%d", &tentativa) != 1) {
                printf("Entrada inválida. Tente novamente.\n");
                continue;
            }
            tentativas++;

            if (tentativa == numero) {
                printf("Parabéns! Você acertou!\n");
                strcpy(ranking[num_jogadores].nome, nome);
                ranking[num_jogadores].tentativas = tentativas;
                num_jogadores++;
                break; 
            }

            int diferenca = tentativa - numero;
            if (diferenca < 0) {
                diferenca = -diferenca;
            }

            if (diferenca > 50) {
                printf("Mais frio que isso só o inverno em Oymyakon na Rússia!\n");
            } else if (diferenca > 30) {
                printf("Frio demais!\n");
            } else if (diferenca > 20) {
                printf("Está frio.\n");
            } else if (diferenca > 10) {
                printf("Está quente.\n");
            } else if (diferenca > 5) {
                printf("Nossa, como tá quente aqui!\n");
            } else {
                printf("Mais quente que isso só Dallol, localizada no deserto.\n");
            }
        }

        printf("Deseja jogar novamente? (s/n): ");
        if (fgets(opcao, sizeof(opcao), stdin) == NULL) {
            printf("Erro na leitura da opção. Saindo do jogo...\n");
            break; 
        }

        pos = strchr(opcao, '\n');
        if (pos) {
            *pos = '\0';
        }

        if (strcasecmp(opcao, "n") == 0) {
            break; 
        }
    }

    printf("\nRanking dos Jogadores:\n");
    for (int i = 0; i < num_jogadores; i++) {
        printf("%d. %s - %d tentativas\n", i + 1, ranking[i].nome, ranking[i].tentativas);
    }

    printf("Obrigado por jogar!\n");

    return 0;
}
