//Atividade 1 - Lista 5
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>

struct produto {
    int codigo, baixas[4][6];
    char nome[50];
    double preco;
};

struct produto produtos[5];

int main(){
    int maisVendido = 0, totalBaixas[5], i;

    for (i = 0; i < 5; i++) {
        printf("Insira o codigo do produto %i: ", i+1);
        scanf("%i", &produtos[i].codigo);
        fflush(stdin);
        system("cls");
        
        printf("Insira o nome do produto %i: ", i+1);
        fgets(produtos[i].nome, 50, stdin);
        fflush(stdin);
        system("cls");

        printf("Insira o preco do produto %i: ", i+1);
        scanf("%lf", &produtos[i].preco);
        fflush(stdin);
        system("cls");

        for (int j = 0; j < 4; j ++) {
            for (int k = 0; k < 6; k ++) {
                printf("Insira as baixas do produto %i no dia %i da semana %i: ", i+1, k+1, j+1);
                scanf("%i", &produtos[i].baixas[j][k]);
                fflush(stdin);
                totalBaixas[i] += produtos[i].baixas[j][k];
                system("cls");
            }
        }
    }

    for (i = 0; i < 5-1; i ++) {
        if (totalBaixas[maisVendido] < totalBaixas[i+1]) {
            maisVendido = i+1;
        }
    }

    printf("Nome do produto mais vendido: ");
    puts(produtos[maisVendido].nome);
    printf("Quantidade de vendas do produto: %i", totalBaixas[maisVendido]);
}