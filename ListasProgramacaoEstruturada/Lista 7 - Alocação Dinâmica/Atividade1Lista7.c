//Atividade 1 - Lista 7
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>

typedef struct produto prod;
struct produto {
    int codigo, baixas[4][6], totalBaixas;
    char nome[50];
    double preco;
    prod *proximo;
} *produtos;

prod* inicializar();

int main() {
    int maisVendido = 0, totalBaixas[2], i;
    produtos = inicializar();

    for (i = 0; i < 5; i++) {
        prod* novo = (prod*) malloc(sizeof(produtos)* 50);

        printf("Insira o codigo do produto %i: ", i+1);
        scanf("%i", &novo->codigo);
        fflush(stdin);
        system("cls");

        printf("Insira o nome do produto %i: ", i+1);
        gets(novo->nome);
        fflush(stdin);
        system("cls");

        printf("Insira o preco do produto %i: ", i+1);
        scanf("%lf", &novo->preco);
        fflush(stdin);
        system("cls");

        for (int j = 0; j < 4; j ++) {
            for (int k = 0; k < 6; k ++) {
                printf("Insira as baixas do produto %i no dia %i da semana %i: ", i+1, k+1, j+1);
                scanf("%i", &novo->baixas[j][k]);
                fflush(stdin);
                totalBaixas[i] += novo->baixas[j][k];
                novo->totalBaixas = totalBaixas[i];
                system("cls");
            }
        }
        novo->proximo = produtos;
        produtos = novo;
    }

    for (i = 0; i < 5-1; i ++) {
        if (totalBaixas[maisVendido] < totalBaixas[i+1]) {
            maisVendido = i+1;
        }
    }

    prod *auxiliar;
    for (auxiliar = produtos; auxiliar!=NULL; auxiliar=auxiliar->proximo) {
        if (auxiliar->totalBaixas == totalBaixas[maisVendido]) {
            printf("Nome do produto mais vendido: %s\n", auxiliar->nome);
            printf("Quantidade de vendas do produto: %i", auxiliar->totalBaixas);
        }
    }
}

prod* inicializar() {
    return NULL;
}